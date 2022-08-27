/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static uint32 Port_PortsAddress[] =
    {
        GPIOA_BASE_ADDRESS,
        GPIOB_BASE_ADDRESS,
        GPIOC_BASE_ADDRESS,
        GPIOD_BASE_ADDRESS,
        GPIOE_BASE_ADDRESS,
        GPIOF_BASE_ADDRESS,
};
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr)
 * \Description     :
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr, uint8 ConfigSize)
{
    uint8 uint8LocalCounter;

    for (uint8LocalCounter = 0; uint8LocalCounter < ConfigSize; uint8LocalCounter++)
    {
        uint8 uint8LocalPortId = (ConfigPtr->PortPin) / 8;
        uint8 uint8LocalPinId = (ConfigPtr->PortPin) % 8;

        /* Activate Port Clock*/
        RCGCGPIO |= 1 << uint8LocalPortId;

        if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
        {
            ACCESS_REGISTER(Port_PortsAddress[uint8LocalPortId], GPIODIR) &= ~(1 << uint8LocalPinId);
        }
        else
        {
            ACCESS_REGISTER(Port_PortsAddress[uint8LocalPortId], GPIODIR) |= (1 << uint8LocalPinId);
        }

        /* Disable Alternative Function */
        ACCESS_REGISTER(Port_PortsAddress[uint8LocalPortId], GPIOAFSEL) &= ~(1 << uint8LocalPinId);
        switch (ConfigPtr->Port_PinOutputCurrent)
        {
        case PORT_DRV2:
            ACCESS_REGISTER(Port_PortsAddress[uint8LocalPortId], GPIODR2R) |= (1 << uint8LocalPinId);
            break;
        case PORT_DRV4:
            ACCESS_REGISTER(Port_PortsAddress[uint8LocalPortId], GPIODR4R) |= (1 << uint8LocalPinId);
            break;
        case PORT_DRV8:
            ACCESS_REGISTER(Port_PortsAddress[uint8LocalPortId], GPIODR8R) |= (1 << uint8LocalPinId);
            break;
        }

        /*  */
        switch (ConfigPtr->Port_PinInternalAttach)
        {
        case PORT_PUR:
            ACCESS_REGISTER(Port_PortsAddress[uint8LocalPortId], GPIOPUR) |= (1 << uint8LocalPinId);
            break;
        case PORT_PDR:
            ACCESS_REGISTER(Port_PortsAddress[uint8LocalPortId], GPIOPDR) |= (1 << uint8LocalPinId);
            break;
        default:
            break;
        }

        /* Enable Pin */
        ACCESS_REGISTER(Port_PortsAddress[uint8LocalPortId], GPIODEN) |= (1 << uint8LocalPinId);
    }
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
/*SYSCTRL_BASE_ADDRESS*/