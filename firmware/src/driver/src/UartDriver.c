/*******************************************************************************
  PORT

  Company:
    AUO

  File Name:
    Port.c

  Version:
    1.00.02
  
  Summary:
    Interface definition of PORT PLIB

  Description:
    This file provides an interface to control and interact with PORT-I/O
    Pin controller module.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include "driver/inc/UartDriver.h"
#include "peripheral/sercom/usart/plib_sercom1_usart.h"

// *****************************************************************************
// *****************************************************************************
// Section: PORT Implementation
// *****************************************************************************
// *****************************************************************************

void UartDriver_initial()
{
    SERCOM1_USART_Initialize();
}

void UartDriver_ReadAbort()
{
    SERCOM1_USART_ReadAbort();
}

bool UartDriver_Read( void *buffer, const size_t size )
{
    return SERCOM1_USART_Read(buffer,size);
}

USART_ERROR UartDriver_ErrorGet()
{
    return SERCOM1_USART_ErrorGet();
}

bool UartDriver_WriteIsBusy()
{
    return SERCOM1_USART_WriteIsBusy();
}


bool UartDriver_Write( void *buffer, const size_t size )
{
    uint32_t u32debounce = 0UL;
    if (true == SERCOM1_USART_Write(buffer, size ))
    {
        while((true == UartDriver_WriteIsBusy()) && (u32debounce < 11154U))
        {
            u32debounce += 1UL;
        }
        return true;
    }
    return false;
}


/* *****************************************************************************
 End of File
 */
