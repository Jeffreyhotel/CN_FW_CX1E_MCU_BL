/* ************************************************************************** */
#ifndef MAINAPP_H    /* Guard against multiple inclusion */
#define MAINAPP_H
/* ************************************************************************** */
#define STATE_BOOT          0x00U
#define STATE_JUMP          0x01U
#define STATE_RETRYCHECK    0x02U

/* FUNCTION:  Define MCU ASM ... for BOOTLOADER VECTOR JUMP */
#define     ADDR_APP_START      0x00010000U
#define		ASM_NOP()			__NOP()
#define		ASM_SYS_RESET()	        (__NVIC_SystemReset())
#define		ASM_SET_MSP(u32Msp)	(__set_MSP(u32Msp))
#define		ASM_VECTOR_RESET(u32ResetVector)	asm("bx %0"::"r" (u32ResetVector))

void MainApp_ChangeUpdateMode(uint8_t targetMode);
uint8_t MainApp_Task(void);
uint8_t MainApp_Flow(uint8_t u8State);
uint8_t MainApp_Boot_Mode(uint8_t u8Nothing);
uint8_t MainApp_Jump_Mode(uint8_t u8Nothing);
uint8_t MainApp_Retrycheck_Mode(uint8_t u8Nothing);

#endif
/* *****************************************************************************
 End of File
 */
