/* ************************************************************************** */

/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */
#include "main.h"
#include "stdio.h"
#include "string.h"
#include "driver/inc/UartDriver.h"
#include "driver/inc/PortDriver.h"
#include "app/inc/UartApp.h"

//volatile uint32_t nBytesRead = 0;

/*  Function: UartApp_TxWriteString
**  Callfrom: UartApp.h
**        Do: Parsing TxBuffer String to UART with 3ms(11154U debounce)
 */
void UartApp_TxWriteString(uint8_t* u8TxBuffer)
{
    uint32_t u32debounce = 0UL;
    if (UART_DEBUG_ENABLE == TRUE){
        while((true == UartDriver_WriteIsBusy()) && (u32debounce < 11154U))
        {
            u32debounce += 1UL;
        }
        UartDriver_Write(u8TxBuffer,strlen((const char*)u8TxBuffer));
    }
}

/* *****************************************************************************
 End of File
 */