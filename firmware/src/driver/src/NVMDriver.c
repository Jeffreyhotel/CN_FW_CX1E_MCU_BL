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

#include "main.h"
#include <stdint.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include "driver/inc/NVMDriver.h"

// *****************************************************************************
// *****************************************************************************
// Section: PORT Implementation
// *****************************************************************************
// *****************************************************************************

void NVMDriver_Initialize(void)
{
    NVMCTRL_Initialize();
}

bool NVMDriver_Read( uint32_t *data, uint32_t length, const uint32_t address )
{
    return NVMCTRL_Read(data,length,address);
}

bool NVMDriver_PageWrite( uint32_t *data, const uint32_t address )
{
    return NVMCTRL_PageWrite(data,address);
}

bool NVMDriver_RowErase(uint32_t address)
{
    if(NVMDriver_IsBusy() == TRUE){
        return false;
    }else{
        /* Set address and command */
        NVMCTRL_REGS->NVMCTRL_ADDR = address >> 1U;

        NVMCTRL_REGS->NVMCTRL_CTRLA = (uint16_t)(NVMCTRL_CTRLA_CMD_ER_Val | NVMCTRL_CTRLA_CMDEX_KEY);

        return true;
    }
}

bool NVMDriver_RWWEEPROM_Read( uint32_t *data, uint32_t length, const uint32_t address )
{
    return NVMCTRL_RWWEEPROM_Read(data,address,length);
}

bool NVMDriver_RWWEEPROM_PageWrite ( uint32_t *data, const uint32_t address )
{
    return NVMCTRL_RWWEEPROM_PageWrite (data, address);
}

bool NVMDriver_RWWEEPROM_RowErase( uint32_t address )
{
    return NVMCTRL_RWWEEPROM_RowErase(address );
}

bool NVMDriver_IsBusy(void)
{
    return NVMCTRL_IsBusy();
}

void NVMDriver_RegionUnlock(uint32_t address)
{
    NVMCTRL_RegionUnlock(address);
}

/* *****************************************************************************
 End of File
 */