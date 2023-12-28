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

#ifndef PORTDRIVER_H
#define PORTDRIVER_H

#include "config/default/peripheral/port/plib_port.h"
/* ************************************************************************** */
/** Global Function Definition
 */
/* ************************************************************************** */

uint8_t PortDrvier_PinRead(uint32_t u32Pin);
uint8_t PortDriver_PinToggle(uint32_t u32Pin);
uint8_t PortDriver_PinSet(uint32_t u32Pin);
uint8_t PortDriver_PinClear(uint32_t u32Pin);
void PortDriver_Initial(void);

// *****************************************************************************
/* PORT Group

  Summary:
    Identifies the port groups available on the device.

  Description:
    This enumeration identifies all the ports groups that are available on this
    device.

  Remarks:
    The caller should not use the constant expressions assigned to any of
    the enumeration constants as these may vary between devices.

    Port groups shown here are the ones available on the selected device. Not
    all ports groups are implemented. Refer to the device specific datasheet
    for more details. The MHC will generate this enumeration with the port
    groups that are available on the device.
*/

#define IO_GROUP_A    (0x41000000U)
#define IO_GROUP_B    (0x41000080U)
#define IO_GROUP_C    (0x41000100U)

// *****************************************************************************
/* PORT Pins

  Summary:
    Identifies the available Ports pins.

  Description:
    This enumeration identifies all the ports pins that are available on this
    device.

  Remarks:
    The caller should not use the constant expressions assigned to any of
    the enumeration constants as these may vary between devices.

    Port pins shown here are the ones available on the selected device. Not
    all ports pins within a port group are implemented. Refer to the device
    specific datasheet for more details.
*/

#define IO_PIN_PA00    (0U)
#define IO_PIN_PA01    (1U)
#define IO_PIN_PA02    (2U)
#define IO_PIN_PA03    (3U)
#define IO_PIN_PA04    (4U)
#define IO_PIN_PA05    (5U)
#define IO_PIN_PA06    (6U)
#define IO_PIN_PA07    (7U)
#define IO_PIN_PA08    (8U)
#define IO_PIN_PA09    (9U)
#define IO_PIN_PA10    (10U)
#define IO_PIN_PA11    (11U)
#define IO_PIN_PA12    (12U)
#define IO_PIN_PA13    (13U)
#define IO_PIN_PA14    (14U)
#define IO_PIN_PA15    (15U)
#define IO_PIN_PA16    (16U)
#define IO_PIN_PA17    (17U)
#define IO_PIN_PA18    (18U)
#define IO_PIN_PA19    (19U)
#define IO_PIN_PA20    (20U)
#define IO_PIN_PA21    (21U)
#define IO_PIN_PA22    (22U)
#define IO_PIN_PA23    (23U)
#define IO_PIN_PA24    (24U)
#define IO_PIN_PA25    (25U)
#define IO_PIN_PA26    (26U)
#define IO_PIN_PA27    (27U)
#define IO_PIN_PA28    (28U)
#define IO_PIN_PA29    (29U)
#define IO_PIN_PA30    (30U)
#define IO_PIN_PA31    (31U)
 
#define IO_PIN_PB00    (32U)
#define IO_PIN_PB01    (33U)
#define IO_PIN_PB02    (34U)
#define IO_PIN_PB03    (35U)
#define IO_PIN_PB04    (36U)
#define IO_PIN_PB05    (37U)
#define IO_PIN_PB06    (38U)
#define IO_PIN_PB07    (39U)
#define IO_PIN_PB08    (40U)
#define IO_PIN_PB09    (41U)
#define IO_PIN_PB10    (42U)
#define IO_PIN_PB11    (43U)
#define IO_PIN_PB12    (44U)
#define IO_PIN_PB13    (45U)
#define IO_PIN_PB14    (46U)
#define IO_PIN_PB15    (47U)
#define IO_PIN_PB16    (48U)
#define IO_PIN_PB17    (49U)
#define IO_PIN_PB18    (50U)
#define IO_PIN_PB19    (51U)
#define IO_PIN_PB20    (52U)
#define IO_PIN_PB21    (53U)
#define IO_PIN_PB22    (54U)
#define IO_PIN_PB23    (55U)
#define IO_PIN_PB24    (56U)
#define IO_PIN_PB25    (57U)
#define IO_PIN_PB26    (58U)
#define IO_PIN_PB27    (59U)
#define IO_PIN_PB28    (60U)
#define IO_PIN_PB29    (61U)
#define IO_PIN_PB30    (62U)
#define IO_PIN_PB31    (63U)

#define IO_PIN_PC00    (64U)
#define IO_PIN_PC01    (65U)
#define IO_PIN_PC02    (66U)
#define IO_PIN_PC03    (67U)
#define IO_PIN_PC04    (68U)
#define IO_PIN_PC05    (69U)
#define IO_PIN_PC06    (70U)
#define IO_PIN_PC07    (71U)
#define IO_PIN_PC08    (72U)
#define IO_PIN_PC09    (73U)
#define IO_PIN_PC10    (74U)
#define IO_PIN_PC11    (75U)
#define IO_PIN_PC12    (76U)
#define IO_PIN_PC13    (77U)
#define IO_PIN_PC14    (78U)
#define IO_PIN_PC15    (79U)
#define IO_PIN_PC16    (80U)
#define IO_PIN_PC17    (81U)
#define IO_PIN_PC18    (82U)
#define IO_PIN_PC19    (83U)
#define IO_PIN_PC20    (84U)
#define IO_PIN_PC21    (85U)
#define IO_PIN_PC22    (86U)
#define IO_PIN_PC23    (87U)
#define IO_PIN_PC24    (88U)
#define IO_PIN_PC25    (89U)
#define IO_PIN_PC26    (90U)
#define IO_PIN_PC27    (91U)
#define IO_PIN_PC28    (92U)
#define IO_PIN_MAX     (93U)
#define IO_PIN_NONE    (-1)   

/*------------------------------------------------------------------------------
Function Enable/Disable Define
*/
#define NVIC_PRIORITY_HIGH          (0x00U)
#define NVIC_PRIORITY_MEDIUM        (0x01U)
#define NVIC_PRIORITY_LOWER         (0x02U)
#define NVIC_PRIORITY_LOWEST        (0x03U)
#define MAX_NVIC_PRIORITY           (0x04U)
/*------------------------------------------------------------------------------
Function Enable/Disable Define
*/
#define FUNC_DISABLE                (0x00U)
#define FUNC_ENABLE                 (0x01U)
/*------------------------------------------------------------------------------
Return Status Define(don't use bit0 for error define)
*/
#define DRIVER_FALSE                (0x00U)
#define DRIVER_TRUE                 (0x01U)
#define DRIVER_TIMEOUT              (0x02U)
#define DRIVER_PARAMETER_ERROR      (0x04U)
#define DRIVER_WRITE_ERROR          (0x06U)
#define DRIVER_REGISTER_ERROR       (0x08U)


#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
