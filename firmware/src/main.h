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

#ifndef MAIN_H    /* Guard against multiple inclusion */
#define MAIN_H

#include "device.h"
#include "packs/CMSIS/CMSIS/Core/Include/cmsis_gcc.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------- Switch Support Function ----------------------*/
#define	MICROCHIP_ARM_ENV	1U
/*---------------------------- Definition Constant ------------------------------*/
#define TRUE                1U
#define FALSE               0U
#define NOTHING             0U
#define PIN_HIGH            1U
#define PIN_LOW             0U
#define UART_DEBUG_ENABLE   TRUE


/* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */