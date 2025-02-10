/* ************************************************************************** */
/** Descriptive File Name
  @Company
    AUO
  @File Name
    MainApp.c
  @Summary
    Start state machine with function - Power Management APP.
  @Description
    RUN Main APP with State .
 **/
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */
#include "main.h"
#include "app/inc/MainApp.h"
#include "driver/inc/PortDriver.h"
#include "config/default/peripheral/nvic/plib_nvic.h"
#include "config/default/peripheral/nvmctrl/plib_nvmctrl.h"
#include "config/default/peripheral/clock/plib_clock.h"
#include "driver/inc/UartDriver.h"
#include "driver/inc/NVMDriver.h"
#include "app/inc/UartApp.h"
/* TODO:  Include other files here if needed. */


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
static uint8_t gu8MainStatus = STATE_BOOT;
static uint8_t UART_DEBUG = 0x01;
static uint8_t RETRY_FLAG = 0x00;
static uint8_t u8TxBuffer[60] = {0};


/*  Function: MainApp_Boot_Mode
**  Callfrom: Main_Flow state machine
**        Do: Do basic initial like PORT/CLOCK and other mustbe function.
**        Go: Go back to SLEEP mode if WAKEUP PIN is LOW, otherwise go to PRENORMAL mode for fully initial.
 */
uint8_t MainApp_Boot_Mode(uint8_t u8Nothing)
{
    /* Microchip default setting*/
    NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_RWS(3UL);
    /* PORT & CLOCK Initialize*/
    PortDriver_Initial();
    CLOCK_Initialize();
    /* For Debug, UART(SERCOM1) initial at Boot Mode*/
    UartDriver_initial();
    
    NVIC_SetPriority(SERCOM1_IRQn, 0);
    NVIC_EnableIRQ(SERCOM1_IRQn);
    
    /* For Debug, NVIC enable early here*/
    NVIC_INT_Enable();
    NVMDriver_Initialize();
    
    if (UART_DEBUG == 0x01){
        sprintf((char *)u8TxBuffer,"BOOT-Loader FINISHED\r\n");
        UartApp_TxWriteString(u8TxBuffer);
        //UartApp_TxWriteString((uint8_t *)"BOOT RETRY\r\n");
    }else{/*DO NOTHING*/}
    (void) u8Nothing;
    return STATE_JUMP;
}

/*  Function: MainApp_PreNormal_Mode
**  Callfrom: Main_Flow state machine
**        Do: Do all initial like SERCOM/ADC/TC and other mustbe function.
**        Go: Strightly go into NORMAL mode.
 */
uint8_t MainApp_Jump_Mode(uint8_t u8Nothing)
{
    uint32_t u32Msp, u32ResetVector;
    uint32_t u32data[1] = {0};
    uint32_t ADDR_JUMP = 0U;
    int i=0U;
    if (UART_DEBUG == 0x01U && RETRY_FLAG == 0x00U){
        //Debug info
        sprintf((char *)u8TxBuffer,"Start JUMP ...\r\n");
        UartApp_TxWriteString(u8TxBuffer);
    }else{/*DO NOTHING*/}
    PortDriver_PinSet(IO_PIN_PC01);
    while(!NVMDriver_Read(&u32data[0],4U,0x0001F000U));

    if ((u32data[0] & 0x000000FF) == 0x0000000A){
        UartApp_TxWriteString((uint8_t *)"Flash Jump A\r\n");
        ADDR_JUMP = ADDR_APP_A_START;
    }else if((u32data[0] & 0x000000FF) == 0x0000000B){
        UartApp_TxWriteString((uint8_t *)"Flash Jump B\r\n");
        ADDR_JUMP = ADDR_APP_B_START;
    }else{
        UartApp_TxWriteString((uint8_t *)"Flash != A or B\r\n");
        ADDR_JUMP = ADDR_APP_A_START;
    }

	u32Msp = *(uint32_t *)(ADDR_JUMP);
	u32ResetVector = *(uint32_t *)(ADDR_JUMP + 4U);
	(void)(u32Msp);
	(void)(u32ResetVector);
    if(u32Msp != (uint32_t)(0xFFFFFFFFU))
    {
        while(UartDriver_WriteIsBusy()==TRUE);
        for (i = 0; i < 65535; i++)
        {
            asm("nop");
        }
        __set_MSP(u32Msp);
        asm("bx %0"::"r" (u32ResetVector));
    }
    
    if (UART_DEBUG == 0x01U && RETRY_FLAG == 0x00U){
        //Debug info
        sprintf((char *)u8TxBuffer,"JUMP Done ...\r\n");
        UartApp_TxWriteString(u8TxBuffer);
    }else{/*DO NOTHING*/}
    
    (void) u8Nothing;
    return STATE_RETRYCHECK;
}

/*  Function: MainApp_Normal_Mode
**  Callfrom: Main_Flow state machine
**        Do: Do most time function.
**        Go: Strightly go into NORMAL mode.
 */
uint8_t MainApp_Retrycheck_Mode(uint8_t u8Nothing)
{
    uint8_t u8Return;
    uint8_t u32debounce;
    u8Return = STATE_JUMP;
    if (UART_DEBUG == 0x01U && RETRY_FLAG == 0x00U){
        RETRY_FLAG = 0x01U;
        sprintf((char *)u8TxBuffer,"JUMP RETRY CHECK\r\n");
        UartApp_TxWriteString(u8TxBuffer);
        //UartApp_TxWriteString((uint8_t *)"BOOT RETRY\r\n");
    }else{/*DO NOTHING*/}
    (void) u8Nothing;
    (void) u32debounce;
    return u8Return;
}


uint8_t MainApp_Task(void)
{
    uint8_t u8Return = FALSE;
    uint8_t u8Status = gu8MainStatus;
    u8Status = MainApp_Flow(u8Status);
    gu8MainStatus = u8Status;
    
    if((u8Status != STATE_BOOT)
        && (u8Status != STATE_JUMP)
        && (u8Status != STATE_RETRYCHECK))
    {
        u8Return=FALSE;
    }
    else
    {
        u8Return=TRUE;
    }
    return u8Return;
}

/*  Function: MainApp_Flow
**  Callfrom: MainApp_Task() at main.c
**        Do: Do State Machine Case
**        Go: loop state machine
 */
uint8_t MainApp_Flow(uint8_t u8State)
{
    uint8_t u8CurrentState;
    
    switch(u8State)
    {
        case STATE_BOOT:
            u8CurrentState = MainApp_Boot_Mode(NOTHING);
        break;

        case STATE_JUMP:
            u8CurrentState = MainApp_Jump_Mode(NOTHING);
        break;

        case STATE_RETRYCHECK:
            u8CurrentState = MainApp_Retrycheck_Mode(NOTHING);
        break;

        default:
            /* Do nothing & no check here*/
            u8CurrentState = STATE_BOOT;
        break;
    }

    return u8CurrentState;
}


/* *****************************************************************************
 End of File
 */
