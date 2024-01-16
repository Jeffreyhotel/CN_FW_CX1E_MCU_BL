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
#include "packs/ATSAMC21N17A_DFP/samc21n17a.h"
#include "driver/inc/PortDriver.h"


// *****************************************************************************
// *****************************************************************************
// Section: PORT Implementation
// *****************************************************************************
// *****************************************************************************

void PortDriver_Initial(void)
{
    /* MCC Code Generated Function*/
    PORT_Initialize();
}


/******************************************************************************
* Function Name         :Port_GroupRead
* Function Description  :The function reads the hardware pin state of all pins in the specified group
*                        and returns this as a 32 bit value. Each bit in the 32 bit value represent a
*                        pin. For example, bit 0 in group 0 will represent pin PA0. Bit 1 will
*                        represent PA1 and so on. The application should only consider the value of
*                        the port group pins which are implemented on the device.
* Parameter				:u32Group - One of the IO groups from the enum PORT_GROUP.
* Return Value 			:A 32-bit value representing the hardware state of of all the I/O pins in the
*                        selected port group.
* Source ID    			:N/A
* Example               :
*   <code>
*   uint32_t value;
*   value = PORT_Read(PORT_GROUP_C);
*   </code>
* Remarks               :N/A
******************************************************************************/
uint32_t LL_Port_GroupRead(uint32_t u32Group)
{
    uint32_t u32Temp;
    
    if((u32Group == IO_GROUP_A) || (u32Group == IO_GROUP_B)|| (u32Group == IO_GROUP_C))
    { 
        u32Temp =  ((port_group_registers_t*)u32Group)->PORT_IN;
    }
    else
    {
        u32Temp = 0xFFFFFFFFU;
    }
    
    return u32Temp;
}

/******************************************************************************
* Function Name         :Port_GroupWrite
* Function Description  :This function writes the value contained in the value parameter to the
*                        port group. Port group pins which are configured for output will be updated.
*                        The mask parameter provides additional control on the bits in the group to
*                        be affected. Setting a bit to 1 in the mask will cause the corresponding
*                        bit in the port group to be updated. Clearing a bit in the mask will cause
*                        that corresponding bit in the group to stay unaffected. For example,
*                        setting a mask value 0xFFFFFFFF will cause all bits in the port group
*                        to be updated. Setting a value 0x3 will only cause port group bit 0 and
*                        bit 1 to be updated.
*
*                        For port pins which are not configured for output and have the pull feature
*                        enabled, this function will affect pull value (pull up or pull down). A bit
*                        value of 1 will enable the pull up. A bit value of 0 will enable the pull
*                        down.
* Parameter				:u32Group - One of the IO groups from the enum PORT_GROUP.
*
*                        u32Mask  - A 32 bit value in which positions of 0s and 1s decide
*                                   which IO pins of the selected port group will be written.
*                                   1's - Will write to corresponding IO pins.
*                                   0's - Will remain unchanged.
*
*                       u32Value - Value which has to be written/driven on the I/O
*                                  lines of the selected port for which mask bits are '1'.
*                                  Values for the corresponding mask bit '0' will be ignored.
*                                  Refer to the function description for effect on pins
*                                  which are not configured for output.
* Return Value 			:u8Ret, 0x01-Group range correct, 0x00-Group range error
* Source ID    			:N/A
* Example               :
*    <code>
*    Write binary value 0011 to the pins PC3, PC2, PC1 and PC0 respectively.
*    (void)PORT_GroupWrite(PORT_GROUP_X, 0x0F, 0xF563D453);
*    </code>
* Remarks               :N/A
******************************************************************************/
#if 0
uint8_t LL_Port_GroupWrite(uint32_t u32Group, uint32_t u32Mask, uint32_t u32Value)
{
    uint8_t u8Status;
    uint32_t u32Temp; 
    
    /* Write the desired value */  
    if((u32Group == IO_GROUP_A) || (u32Group == IO_GROUP_B)|| (u32Group == IO_GROUP_C))
    {
        u32Temp = ((port_group_registers_t*)u32Group)->PORT_OUT; 
        ((port_group_registers_t*)u32Group)->PORT_OUT = (u32Temp & (~u32Mask)) | (u32Mask & u32Value);
        u8Status = DRIVER_TRUE;
    }
    else
    {
        u8Status = DRIVER_PARAMETER_ERROR;
    }
    
    return u8Status;
}
#endif

/******************************************************************************
* Function Name         :Port_GroupLatchRead
* Function Description  :The function will return a 32-bit value representing the logic levels being
*                        driven on the output pins within the group. The function will not sample the
*                        actual hardware state of the output pin. Each bit in the 32-bit return value
*                        will represent one of the 32 port pins within the group. The application
*                        should only consider the value of the pins which are available on the
*                        device.
* Parameter				:u32Group - One of the IO groups from the enum PORT_GROUP.
* Return Value 			:A 32-bit value representing the output state of of all the I/O pins in the
*                        selected port group.
* Source ID    			:N/A
* Example               :
*    <code>
*    uint32_t value;
*    value = PORT_GroupLatchRead(PORT_GROUP_X);
*    </code>
* Remarks               :N/A
******************************************************************************/
#if 0
uint32_t LL_Port_GroupLatchRead(uint32_t u32Group)
{
    uint32_t u32Temp;

    if((u32Group == IO_GROUP_A) || (u32Group == IO_GROUP_B)|| (u32Group == IO_GROUP_C))
    { 
        u32Temp = ((port_group_registers_t*)u32Group)->PORT_OUT;
    }
    else
    {
        u32Temp = 0xFFFFFFFFU;
    }
    
    return u32Temp;
}
#endif

/******************************************************************************
* Function Name         :Port_GroupSet
* Function Description  :This function sets (drives a logic high) on the selected output pins of a
*                        group. The mask parameter control the pins to be updated. A mask bit
*                        position with a value 1 will cause that corresponding port pin to be set. A
*                        mask bit position with a value 0 will cause the corresponding port pin to
*                        stay un-affected.
* Parameter				:u32Group - One of the IO ports from the enum PORT_GROUP.
*                        u32Mask - A 32 bit value in which a bit represent a pin in the group. If the
*                        value of the bit is 1, the corresponding port pin will driven to logic 1. If
*                        the value of the bit is 0. the corresponding port pin will stay un-affected.
* Return Value 			:u8Ret, 0x01-Group range correct, 0x00-Group range error
* Source ID    			:N/A
* Example               :
*    <code>
*    Set PC5 and PC7 pins to 1
*    (void)PORT_GroupSet(PORT_GROUP_X, 0x00A0);
*    </code>
* Remarks               :If the port pin within the the group is not configured for output and has
*                        the pull feature enabled, driving a logic 1 on this pin will cause the pull
*                        up to be enabled.
******************************************************************************/
uint8_t LL_Port_GroupSet(uint32_t u32Group, uint32_t u32Mask)
{
    uint8_t u8Status;
    
    if((u32Group == IO_GROUP_A) || (u32Group == IO_GROUP_B)|| (u32Group == IO_GROUP_C))
    {
        ((port_group_registers_t*)u32Group)->PORT_OUTSET = u32Mask;   
        u8Status = DRIVER_TRUE;
    }
    else
    {
        u8Status = DRIVER_PARAMETER_ERROR;
    }
    
    return u8Status;
}

/******************************************************************************
* Function Name         :Port_GroupClear
* Function Description  :This function clears (drives a logic 0) on the selected output pins of a
*                        group. The mask parameter control the pins to be updated. A mask bit
*                        position with a value 1 will cause that corresponding port pin to be clear.
*                        A mask bit position with a value 0 will cause the corresponding port pin to
*                        stay un-affected.
* Parameter				:u32Group - One of the IO ports from the enum PORT_GROUP.
* 
*                        u32Mask - A 32 bit value in which a bit represent a pin in the group. If the
*                        value of the bit is 1, the corresponding port pin will driven to logic 0. If
*                        the value of the bit is 0. the corresponding port pin will stay un-affected.
* Return Value 			:u8Ret, 0x01-Group range correct, 0x00-Group range error
* Source ID    			:N/A
* Example               :
*   <code>
*    Clear PC5 and PC7 pins to 1
*    (void)PORT_GroupClear(PORT_GROUP_X, 0x00A0);
*    </code>
* Remarks               :N/A
******************************************************************************/
uint8_t LL_Port_GroupClear(uint32_t u32Group, uint32_t u32Mask)
{
    uint8_t u8Status;
    
    if((u32Group == IO_GROUP_A) || (u32Group == IO_GROUP_B)|| (u32Group == IO_GROUP_C))
    {
        ((port_group_registers_t*)u32Group)->PORT_OUTCLR = u32Mask;
        u8Status = DRIVER_TRUE;
    }
    else
    {
        u8Status = DRIVER_PARAMETER_ERROR;
    }
    
    return u8Status;
}

/******************************************************************************
* Function Name         :Port_GroupToggle
* Function Description  :This function toggles the selected output pins of a group. The mask
*                        parameter control the pins to be updated. A mask bit position with a value 1
*                        will cause that corresponding port pin to be toggled.  A mask bit position
*                        with a value 0 will cause the corresponding port pin to stay un-affected.
* Parameter				:u32Group - One of the IO ports from the enum PORT_GROUP.
* 
*                        u32Mask - A 32 bit value in which a bit represent a pin in the group. If the
*                        value of the bit is 1, the corresponding port pin will be toggled. If the
*                        value of the bit is 0. the corresponding port pin will stay un-affected.
* Return Value 			:u8Ret, 0x01-Group range correct, 0x00-Group range error
* Source ID    			:N/A
* Example               :
*    <code>
*    Clear PC5 and PC7 pins to 1
*    (void)PORT_GroupToggle(PORT_GROUP_X, 0x00A0);
*    </code>
* Remarks               :If the port pin within the the group is not configured for output and has
*                        the pull feature enabled, driving a logic 0 on this pin will cause the pull
*                        down to be enabled. Driving a logic 1 on this pin will cause the pull up to
*                        be enabled.
******************************************************************************/
uint8_t LL_Port_GroupToggle(uint32_t u32Group, uint32_t u32Mask)
{
    uint8_t u8Status;
    
    if((u32Group == IO_GROUP_A) || (u32Group == IO_GROUP_B)|| (u32Group == IO_GROUP_C))
    {    
        ((port_group_registers_t*)u32Group)->PORT_OUTTGL = u32Mask;
        u8Status = DRIVER_TRUE;
    }
    else
    {
        u8Status = DRIVER_PARAMETER_ERROR;
    }
    
    return u8Status;
}

/******************************************************************************
* Function Name         :Port_GroupInputEnable
* Function Description  :This function configures the selected IO pins of a group as input. The pins
*                        to be configured as input are selected by setting the corresponding bits in
*                        the mask parameter to 1.
* Parameter				:u32Group - One or more of the of the IO ports from the enum PORT_GROUP.
* 
*                        u32Mask - A 32 bit value in which a bit represents a pin in the group. If the
*                        value of the bit is 1, the corresponding port pin will be configured as
*                        input. If the value of the bit is 0. the corresponding port pin will stay
*                        un-affected.
* Return Value 			:u8Ret, 0x01-Group range correct, 0x00-Group range error
* Source ID    			:N/A
* Example               :
*   <code>
*   Make PC5 and PC7 pins as input
*   (void)PORT_GroupInputEnable(PORT_GROUP_X, 0x00A0);
*   </code>
* Remarks               :N/A
******************************************************************************/
#if 0
uint8_t LL_Port_GroupInputEnable(uint32_t u32Group, uint32_t u32Mask)
{
    uint8_t u8Status;
    
    if((u32Group == IO_GROUP_A) || (u32Group == IO_GROUP_B)|| (u32Group == IO_GROUP_C))
    {      
        ((port_group_registers_t*)u32Group)->PORT_DIRCLR = u32Mask; 
        u8Status = DRIVER_TRUE;
    }
    else
    {
        u8Status = DRIVER_PARAMETER_ERROR;
    }
    
    return u8Status;
}
#endif

/******************************************************************************
* Function Name         :Port_GroupOutputEnable
* Function Description  :This function configures the selected IO pins of a group as output. The pins
*                        to be configured as output are selected by setting the corresponding bits in
*                        the mask parameter to 1.
* Parameter				:u32Group - One or more of the of the IO ports from the enum PORT_GROUP.
*                        u32Mask - A 32 bit value in which a bit represents a pin in the group. If the
*                        value of the bit is 1, the corresponding port pin will be configured as
*                        output. If the value of the bit is 0. the corresponding port pin will stay
*                        un-affected.
* Return Value 			:u8Ret, 0x01-Group range correct, 0x00-Group range error
* Source ID    			:N/A
* Example               :
*   <code>
*   Make PC5 and PC7 pins as output
*   (void)Port_GroupOutputEnable(PORT_GROUP_X, 0x00A0);
*   </code>
* Remarks               :N/A
******************************************************************************/
#if 0
uint8_t LL_Port_GroupOutputEnable(uint32_t u32Group, uint32_t u32Mask)
{
     uint8_t u8Status;
    
    if((u32Group == IO_GROUP_A) || (u32Group == IO_GROUP_B)|| (u32Group == IO_GROUP_C))
    {   
        ((port_group_registers_t*)u32Group)->PORT_DIRSET = u32Mask;
        u8Status = DRIVER_TRUE;
    }
    else
    {
        u8Status = DRIVER_PARAMETER_ERROR;
    }
    
    return u8Status;
}
#endif

/******************************************************************************
* Function Name         :Port_PinWrite
* Function Description  :This function writes/drives the "value" on the selected I/O line/pin.
* Parameter				:u32Pin - One of the IO pins from the enum PORT_PIN.
* 
*                        u32Value - value to be written on the selected pin.
*                        true  = set pin to high (1).
*                        false = clear pin to low (0).
* Return Value 			:u8Ret, 0x01-pin and value range correct, 0x00-pin or value range error
* Source ID    			:N/A
* Example               :
*    <code>
*    bool value = true;
*    (void)Port_PinWrite(PORT_PIN_PB3, value);
*    </code>
* Remarks               :N/A
******************************************************************************/
#if 0
uint8_t LL_Port_PinWrite(uint32_t u32Pin, uint8_t u8Value)
{
    uint8_t u8Status;
    uint32_t u32Group;
    uint32_t u32Mask;
    
    if((u32Pin < IO_PIN_MAX) && (u8Value <= 0x01U))
    {
        u32Group = (PORT_BASE_ADDRESS + (0x80U * (u32Pin>>5U)));
        u32Mask = (0x1U << (u32Pin & 0x1FU));
        u8Status = LL_Port_GroupWrite(u32Group, u32Mask, u8Value << (u32Pin & 0x1fU)); 
    }
    else
    {
        u8Status = DRIVER_PARAMETER_ERROR;
    }

    
    return u8Status;
}
#endif

/******************************************************************************
* Function Name         :Port_PinRead
* Function Description  :This function reads the present state at the selected input pin.  The
*                        function can also be called to read the value of an output pin if input
*                        sampling on the output pin is enabled in MHC. If input synchronization on
*                        the pin is disabled in MHC, the function will cause a 2 PORT Clock cycles
*                        delay. Enabling the synchronization eliminates the delay but will increase
*                        power consumption.
* Parameter				:u32Pin - the port pin whose state needs to be read.
* Return Value 			:true - the state at the pin is a logic high.
*                        false - the state at the pin is a logic low.
* Source ID    			:N/A
* Example               :
*    <code>
*    bool value;
*    value = Port_PinRead(PORT_PIN_PB3);
*    </code>
* Remarks               :N/A
******************************************************************************/
uint8_t LL_Port_PinRead(uint32_t u32Pin)
{
    uint32_t volatile u32Group;
    uint32_t volatile u32Value;
    uint8_t volatile u8PinLevel;
    
    if(u32Pin < IO_PIN_MAX)
    {
        u32Group = ((PORT_BASE_ADDRESS + (0x80U * (u32Pin>>5U))));
        u32Value = LL_Port_GroupRead(u32Group);
        u8PinLevel = (uint8_t)((u32Value >> (u32Pin & 0x1FU)) & 0x1U);
    }
    else
    {
        u8PinLevel = 0xFFU;
    }

    return u8PinLevel;
}

uint8_t PortDrvier_PinRead(uint32_t u32Pin)
{
    return LL_Port_PinRead(u32Pin);
}
/******************************************************************************
* Function Name         :Port_PinLatchRead
* Function Description  :This function reads the data driven on the selected I/O line/pin. The
*                        function does not sample the state of the hardware pin. It only returns the
*                        value that is written to output register. Refer to the PORT_PinRead()
*                        function if the state of the output pin needs to be read.
* Parameter				:u32Pin - One of the IO pins from the enum PORT_PIN.
* Return Value 			:true - the present value in the output latch is a logic high.
*                        false - the present value in the output latch is a logic low.
* Source ID    			:N/A
* Example               :
*    <code>
*    bool value;
*    value = Port_PinLatchRead(PORT_PIN_PB3);
*    </code>
* Remarks               :N/A
******************************************************************************/
#if 0
uint8_t LL_Port_PinLatchRead(uint32_t u32Pin)
{
    uint32_t u32Group;
    uint32_t u32Value;
    uint8_t u8PinLevel;
    
    if(u32Pin < IO_PIN_MAX)
    {
        u32Group =  ((PORT_BASE_ADDRESS + (0x80U * (u32Pin>>5U)))); 
        u32Value = LL_Port_GroupLatchRead(u32Group);  
        u8PinLevel = (uint8_t)((u32Value >> (u32Pin & 0x1FU)) & 0x1U);
    }
    else
    {
        u8PinLevel = 0xFFU;
    }
    
    return u8PinLevel;
}
#endif

/******************************************************************************
* Function Name         :Port_PinToggle
* Function Description  :This function toggles/inverts the present value on the selected I/O line/pin.
* Parameter				:u32Pin - One of the IO pins from the enum PORT_PIN.
* Return Value 			:u8Ret, 0x01-pin range correct, 0x00-pin range error
* Source ID    			:N/A
* Example               :
*    <code>
*    (void)Port_PinToggle(PORT_PIN_PB3);
*    </code>
* Remarks               :N/A
******************************************************************************/
uint8_t LL_Port_PinToggle(uint32_t u32Pin)
{
    uint32_t u32Group;
    uint32_t u32Mask;
    uint8_t u8Status;
    
    if(u32Pin < IO_PIN_MAX)
    {
        u32Group =  (PORT_BASE_ADDRESS + (0x80U * (u32Pin>>5U)));
        u32Mask =  (0x1U << (u32Pin & 0x1FU));
        u8Status = LL_Port_GroupToggle(u32Group, u32Mask);
    }
    else
    {
        u8Status = DRIVER_PARAMETER_ERROR;
    }
    
    return u8Status;
}

uint8_t PortDriver_PinToggle(uint32_t u32Pin)
{
    return LL_Port_PinToggle(u32Pin);
}
/******************************************************************************
* Function Name         :Port_PinSet
* Function Description  :This function drives a logic 1 on the selected I/O line/pin.
* Parameter				:u32Pin - One of the IO pins from the enum PORT_PIN.
* Return Value 			:u8Ret, 0x01-pin range correct, 0x00-pin range error
* Source ID    			:N/A
* Example               :
*    <code>
*    Port_PinSet(PORT_PIN_PB3);
*    </code>
* Remarks               :N/A
******************************************************************************/
uint8_t LL_Port_PinSet(uint32_t u32Pin)
{
    uint32_t u32Group;
    uint32_t u32Mask;
    uint8_t u8Status;
    
    if(u32Pin < IO_PIN_MAX)
    {
        u32Group =  (PORT_BASE_ADDRESS + (0x80U * (u32Pin>>5U)));
        u32Mask =  (0x1U << (u32Pin & 0x1FU));
        u8Status = LL_Port_GroupSet(u32Group, u32Mask);
    }
    else
    {
        u8Status = DRIVER_PARAMETER_ERROR;
    }
    
    return u8Status;
}

uint8_t PortDriver_PinSet(uint32_t u32Pin)
{
    return LL_Port_PinSet(u32Pin);
}
/******************************************************************************
* Function Name         :Port_PinClear
* Function Description  :This function drives a logic 0 on the selected I/O line/pin.
* Parameter				:u32Pin - One of the IO pins from the enum PORT_PIN.
* Return Value 			:u8Ret, 0x01-pin range correct, 0x00-pin range error
* Source ID    			:N/A
* Example               :
*    <code>
*    (void)Port_PinClear(PORT_PIN_PB3);
*    </code>
* Remarks               :N/A
******************************************************************************/
uint8_t LL_Port_PinClear(uint32_t u32Pin)
{
    uint32_t u32Group;
    uint32_t u32Mask;
    uint8_t u8Status;
    
    if(u32Pin < IO_PIN_MAX)
    {
        u32Group =  (PORT_BASE_ADDRESS + (0x80U * (u32Pin>>5U)));
        u32Mask =  (0x1U << (u32Pin & 0x1FU));
        u8Status = LL_Port_GroupClear(u32Group, u32Mask);
    }
    else
    {
        u8Status = DRIVER_PARAMETER_ERROR;
    }
    
    return u8Status;
}

uint8_t PortDriver_PinClear(uint32_t u32Pin)
{
    return LL_Port_PinClear(u32Pin);
}

/******************************************************************************
* Function Name         :Port_PinInputEnable
* Function Description  :This function configures the selected IO pin as input. This function
*                        override the MHC input output pin settings.
* Parameter				:u32Pin - One of the IO pins from the enum PORT_PIN.
* Return Value 			:u8Ret, 0x01-pin range correct, 0x00-pin range error
* Source ID    			:N/A
* Example               :
*    <code>
*    (void)Port_PinInputEnable(PORT_PIN_PB3);
*    </code>
* Remarks               :N/A
******************************************************************************/
#if 0
uint8_t LL_Port_PinInputEnable(uint32_t u32Pin)
{
    uint32_t u32Group;
    uint32_t u32Mask;
    uint8_t u8Status;
    
    if(u32Pin < IO_PIN_MAX)
    {
        u32Group =  (PORT_BASE_ADDRESS + (0x80U * (u32Pin>>5U)));
        u32Mask =  (0x1U << (u32Pin & 0x1FU));
        u8Status = LL_Port_GroupInputEnable(u32Group, u32Mask);
    }
    else
    {
        u8Status = DRIVER_PARAMETER_ERROR;
    }
    
    return u8Status;
}
#endif

/******************************************************************************
* Function Name         :Port_PinOutputEnable
* Function Description  :This function enables selected IO pin as output. Calling this function will
*                        override the MHC input output pin configuration.
* Parameter				:u32Pin - One of the IO pins from the enum PORT_PIN.
* Return Value 			:u8Ret, 0x01-pin range correct, 0x00-pin range error
* Source ID    			:N/A
* Example               :
*    <code>
*    (void)PORT_PinOutputEnable(PORT_PIN_PB3);
*    </code>
* Remarks               :N/A
******************************************************************************/
#if 0
uint8_t LL_Port_PinOutputEnable(uint32_t u32Pin)
{
    uint32_t u32Group;
    uint32_t u32Mask;
    uint8_t u8Status;
    
    if(u32Pin < IO_PIN_MAX)
    {
        u32Group =  (PORT_BASE_ADDRESS + (0x80U * (u32Pin>>5U)));
        u32Mask =  (0x1U << (u32Pin & 0x1FU));
        u8Status = LL_Port_GroupOutputEnable(u32Group, u32Mask);
    }
    else
    {
        u8Status = DRIVER_PARAMETER_ERROR;
    }
    
    return u8Status;
}
#endif
