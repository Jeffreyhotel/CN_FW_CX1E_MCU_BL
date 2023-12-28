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

#ifndef __NVMDRIVER_H
#define __NVMDRIVER_H


/* ************************************************************************** */
/** Global Function Definition
 */
/* ************************************************************************** */
//#include "peripheral\nvmctrl\plib_nvmctrl.h"
#include "config\default\peripheral\nvmctrl\plib_nvmctrl.h"

/*---------------------------- Define Constant -------------------------------*/

void NVMDriver_Initialize(void);
bool NVMDriver_Read( uint32_t *data, uint32_t length, const uint32_t address );
bool NVMDriver_PageWrite( uint32_t *data, const uint32_t address );
bool NVMDriver_RowErase(uint32_t address);
bool NVMDriver_IsBusy(void);
void NVMDriver_RegionUnlock(uint32_t address);

#endif /* _EXAMPLE_FILE_NAME_H */
/* *****************************************************************************
 End of File
 */