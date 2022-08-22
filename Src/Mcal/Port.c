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
void Port_Init(const Port_ConfigType* ConfigPtr)
{
    for (uint8 uint8LocalCounter = 0; uint8LocalCounter < PORT_PINS_NUMBER; uint8LocalCounter++)
    {
        uint8 uint8LocalPortId = (ConfigPtr->PortPin)/8;
        uint8 uint8LocalPinId = (ConfigPtr->PortPin)%8;
        *((uint32 *)(SYSCTRL_BASE_ADDRESS + 0x608)) |= 1 << uint8LocalPortId;
        switch (uint8LocalPortId)
        {
        case PORTA: 
            if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
            {
                GPIOA_BASE_ADDRESS->GPIODIR &= ~(1 << uint8LocalPinId);
            }
            else
            {
                GPIOA_BASE_ADDRESS->GPIODIR |= (1 << uint8LocalPinId);
            }
            GPIOA_BASE_ADDRESS->GPIOAFSEL &= ~(1 << uint8LocalPinId);
            switch (ConfigPtr->Port_PinOutputCurrent)
            {
            case PORT_DRV2:
                GPIOA_BASE_ADDRESS->GPIODR2R |= (1 << uint8LocalPinId); 
                break;
            case PORT_DRV4:
                GPIOA_BASE_ADDRESS->GPIODR4R |= (1 << uint8LocalPinId);
                break;
            case PORT_DRV8:
                GPIOA_BASE_ADDRESS->GPIODR8R |= (1 << uint8LocalPinId);
                break;
            }
            switch (ConfigPtr->Port_PinInternalAttach)
            {
            case PORT_PUR:
                GPIOA_BASE_ADDRESS->GPIOPUR |= (1 << uint8LocalPinId); 
                break;
            case PORT_PDR:
                GPIOA_BASE_ADDRESS->GPIOPDR |= (1 << uint8LocalPinId);
                break;
            default : break;
            }
            GPIOA_BASE_ADDRESS->GPIODEN |= (1 << uint8LocalPinId);
            break;
        case PORTB:
                if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
            {
                GPIOB_BASE_ADDRESS->GPIODIR &= ~(1 << uint8LocalPinId);
            }
            else
            {
                GPIOB_BASE_ADDRESS->GPIODIR |= (1 << uint8LocalPinId);
            }
            GPIOB_BASE_ADDRESS->GPIOAFSEL &= ~(1 << uint8LocalPinId);
            switch (ConfigPtr->Port_PinOutputCurrent)
            {
            case PORT_DRV2:
                GPIOB_BASE_ADDRESS->GPIODR2R |= (1 << uint8LocalPinId); 
                break;
            case PORT_DRV4:
                GPIOB_BASE_ADDRESS->GPIODR4R |= (1 << uint8LocalPinId);
                break;
            case PORT_DRV8:
                GPIOB_BASE_ADDRESS->GPIODR8R |= (1 << uint8LocalPinId);
                break;
            }
            switch (ConfigPtr->Port_PinInternalAttach)
            {
            case PORT_PUR:
                GPIOB_BASE_ADDRESS->GPIOPUR |= (1 << uint8LocalPinId); 
                break;
            case PORT_PDR:
                GPIOB_BASE_ADDRESS->GPIOPDR |= (1 << uint8LocalPinId);
                break;
            default : break;
            }
            GPIOB_BASE_ADDRESS->GPIODEN |= (1 << uint8LocalPinId);
            break;
        case PORTC:
                if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
            {
                GPIOC_BASE_ADDRESS->GPIODIR &= ~(1 << uint8LocalPinId);
            }
            else
            {
                GPIOC_BASE_ADDRESS->GPIODIR |= (1 << uint8LocalPinId);
            }
            GPIOC_BASE_ADDRESS->GPIOAFSEL &= ~(1 << uint8LocalPinId);
            switch (ConfigPtr->Port_PinOutputCurrent)
            {
            case PORT_DRV2:
                GPIOC_BASE_ADDRESS->GPIODR2R |= (1 << uint8LocalPinId); 
                break;
            case PORT_DRV4:
                GPIOC_BASE_ADDRESS->GPIODR4R |= (1 << uint8LocalPinId);
                break;
            case PORT_DRV8:
                GPIOC_BASE_ADDRESS->GPIODR8R |= (1 << uint8LocalPinId);
                break;
            }
            switch (ConfigPtr->Port_PinInternalAttach)
            {
            case PORT_PUR:
                GPIOC_BASE_ADDRESS->GPIOPUR |= (1 << uint8LocalPinId); 
                break;
            case PORT_PDR:
                GPIOC_BASE_ADDRESS->GPIOPDR |= (1 << uint8LocalPinId);
                break;
                default : break;
            }
            GPIOC_BASE_ADDRESS->GPIODEN |= (1 << uint8LocalPinId);
            break;
        case PORTD:
                if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
            {
                GPIOD_BASE_ADDRESS->GPIODIR &= ~(1 << uint8LocalPinId);
            }
            else
            {
                GPIOD_BASE_ADDRESS->GPIODIR |= (1 << uint8LocalPinId);
            }
            GPIOD_BASE_ADDRESS->GPIOAFSEL &= ~(1 << uint8LocalPinId);
            switch (ConfigPtr->Port_PinOutputCurrent)
            {
            case PORT_DRV2:
                GPIOD_BASE_ADDRESS->GPIODR2R |= (1 << uint8LocalPinId); 
                break;
            case PORT_DRV4:
                GPIOD_BASE_ADDRESS->GPIODR4R |= (1 << uint8LocalPinId);
                break;
            case PORT_DRV8:
                GPIOD_BASE_ADDRESS->GPIODR8R |= (1 << uint8LocalPinId);
                break;
            }
            switch (ConfigPtr->Port_PinInternalAttach)
            {
            case PORT_PUR:
                GPIOA_BASE_ADDRESS->GPIOPUR |= (1 << uint8LocalPinId); 
                break;
            case PORT_PDR:
                GPIOD_BASE_ADDRESS->GPIOPDR |= (1 << uint8LocalPinId);
                break;
                default : break;
            }
            GPIOD_BASE_ADDRESS->GPIODEN |= (1 << uint8LocalPinId);
            break;
        case PORTE:
                if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
            {
                GPIOE_BASE_ADDRESS->GPIODIR &= ~(1 << uint8LocalPinId);
            }
            else
            {
                GPIOE_BASE_ADDRESS->GPIODIR |= (1 << uint8LocalPinId);
            }
            GPIOE_BASE_ADDRESS->GPIOAFSEL &= ~(1 << uint8LocalPinId);
            switch (ConfigPtr->Port_PinOutputCurrent)
            {
            case PORT_DRV2:
                GPIOE_BASE_ADDRESS->GPIODR2R |= (1 << uint8LocalPinId); 
                break;
            case PORT_DRV4:
                GPIOE_BASE_ADDRESS->GPIODR4R |= (1 << uint8LocalPinId);
                break;
            case PORT_DRV8:
                GPIOE_BASE_ADDRESS->GPIODR8R |= (1 << uint8LocalPinId);
                break;
            }
            switch (ConfigPtr->Port_PinInternalAttach)
            {
            case PORT_PUR:
                GPIOE_BASE_ADDRESS->GPIOPUR |= (1 << uint8LocalPinId); 
                break;
            case PORT_PDR:
                GPIOE_BASE_ADDRESS->GPIOPDR |= (1 << uint8LocalPinId);
                break;
                default : break;
            }
            GPIOE_BASE_ADDRESS->GPIODEN |= (1 << uint8LocalPinId);
            break;
        case PORTF:
                if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
            {
                GPIOF_BASE_ADDRESS->GPIODIR &= ~(1 << uint8LocalPinId);
            }
            else
            {
                GPIOF_BASE_ADDRESS->GPIODIR |= (1 << uint8LocalPinId);
            }
            GPIOF_BASE_ADDRESS->GPIOAFSEL &= ~(1 << uint8LocalPinId);
            switch (ConfigPtr->Port_PinOutputCurrent)
            {
            case PORT_DRV2:
                GPIOF_BASE_ADDRESS->GPIODR2R |= (1 << uint8LocalPinId); 
                break;
            case PORT_DRV4:
                GPIOF_BASE_ADDRESS->GPIODR4R |= (1 << uint8LocalPinId);
                break;
            case PORT_DRV8:
                GPIOF_BASE_ADDRESS->GPIODR8R |= (1 << uint8LocalPinId);
                break;
            }
            switch (ConfigPtr->Port_PinInternalAttach)
            {
            case PORT_PUR:
                GPIOF_BASE_ADDRESS->GPIOPUR |= (1 << uint8LocalPinId); 
                break;
            case PORT_PDR:
                GPIOF_BASE_ADDRESS->GPIOPDR |= (1 << uint8LocalPinId);
                break;
                default : break;
            }
            GPIOF_BASE_ADDRESS->GPIODEN |= (1 << uint8LocalPinId);
            break;
        }
    }
    

}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
/*SYSCTRL_BASE_ADDRESS*/