/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef UARTDRIVER_H
#define UARTDRIVER_H


/* ************************************************************************** */
/** Global Function Definition
 */
/* ************************************************************************** */
#include "peripheral/sercom/usart/plib_sercom_usart_common.h"

void UartDriver_initial(void);
void UartDriver_ReadAbort(void);
bool UartDriver_Read( void *buffer, const size_t size );
USART_ERROR UartDriver_ErrorGet(void);
bool UartDriver_WriteIsBusy(void);
bool UartDriver_Write( void *buffer, const size_t size );

#endif /* _EXAMPLE_FILE_NAME_H */
/* *****************************************************************************
 End of File
 */
