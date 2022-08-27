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
    uint8 uint8LocalCounter;
    for (uint8LocalCounter = 0; uint8LocalCounter < PORT_PINS_NUMBER; uint8LocalCounter++)
    {
        uint8 uint8LocalPortId = (ConfigPtr->PortPin)/8;
        uint8 uint8LocalPinId = (ConfigPtr->PortPin) % 8;

        /* Activate Port Clock*/
        RCGCGPIO |= 1 << uint8LocalPortId;



        switch (uint8LocalPortId)
        {
        case PORTA: 
            if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
            {
                PORTA_GPIODIR &= ~(1 << uint8LocalPinId);
            }
            else
            {
                PORTA_GPIODIR |= (1 << uint8LocalPinId);
            }
            
             /* Disable Alternative Function */ 
            PORTA_GPIOAFSEL &= ~(1 << uint8LocalPinId);
            switch (ConfigPtr->Port_PinOutputCurrent)
            {
            case PORT_DRV2:
                PORTA_GPIODR2R |= (1 << uint8LocalPinId); 
                break;
            case PORT_DRV4:
                PORTA_GPIODR4R |= (1 << uint8LocalPinId);
                break;
            case PORT_DRV8:
                PORTA_GPIODR8R |= (1 << uint8LocalPinId);
                break;
            }
            switch (ConfigPtr->Port_PinInternalAttach)
            {
            case PORT_PUR:
                PORTA_GPIOPUR |= (1 << uint8LocalPinId); 
                break;
            case PORT_PDR:
                PORTA_GPIOPDR |= (1 << uint8LocalPinId);
                break;
            default : break;
            }
            PORTA_GPIODEN|= (1 << uint8LocalPinId);
            break;
        case PORTB:
                if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
            {
                PORTB_GPIODIR &= ~(1 << uint8LocalPinId);
            }
            else
            {
                PORTB_GPIODIR|= (1 << uint8LocalPinId);
            }
            PORTB_GPIOAFSEL &= ~(1 << uint8LocalPinId);
            switch (ConfigPtr->Port_PinOutputCurrent)
            {
            case PORT_DRV2:
                PORTB_GPIODR2R |= (1 << uint8LocalPinId); 
                break;
            case PORT_DRV4:
                PORTB_GPIODR4R |= (1 << uint8LocalPinId);
                break;
            case PORT_DRV8:
                PORTB_GPIODR8R |= (1 << uint8LocalPinId);
                break;
            }
            switch (ConfigPtr->Port_PinInternalAttach)
            {
            case PORT_PUR:
                PORTB_GPIOPUR |= (1 << uint8LocalPinId); 
                break;
            case PORT_PDR:
                PORTB_GPIOPDR|= (1 << uint8LocalPinId);
                break;
            default : break;
            }
            PORTB_GPIODEN |= (1 << uint8LocalPinId);
            break;
        case PORTC:
                if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
            {
                PORTC_GPIODIR &= ~(1 << uint8LocalPinId);
            }
            else
            {
                PORTC_GPIODIR |= (1 << uint8LocalPinId);
            }
            PORTC_GPIOAFSEL &= ~(1 << uint8LocalPinId);
            switch (ConfigPtr->Port_PinOutputCurrent)
            {
            case PORT_DRV2:
                PORTC_GPIODR2R |= (1 << uint8LocalPinId); 
                break;
            case PORT_DRV4:
                PORTC_GPIODR4R |= (1 << uint8LocalPinId);
                break;
            case PORT_DRV8:
                PORTC_GPIODR8R |= (1 << uint8LocalPinId);
                break;
            }
            switch (ConfigPtr->Port_PinInternalAttach)
            {
            case PORT_PUR:
                PORTC_GPIOPUR |= (1 << uint8LocalPinId); 
                break;
            case PORT_PDR:
                PORTC_GPIOPDR |= (1 << uint8LocalPinId);
                break;
                default : break;
            }
            PORTC_GPIODEN |= (1 << uint8LocalPinId);
            break;
        case PORTD:
                if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
            {
                PORTD_GPIODIR &= ~(1 << uint8LocalPinId);
            }
            else
            {
                PORTD_GPIODIR |= (1 << uint8LocalPinId);
            }
            PORTD_GPIOAFSEL &= ~(1 << uint8LocalPinId);
            switch (ConfigPtr->Port_PinOutputCurrent)
            {
            case PORT_DRV2:
                PORTD_GPIODR2R |= (1 << uint8LocalPinId); 
                break;
            case PORT_DRV4:
                PORTD_GPIODR4R |= (1 << uint8LocalPinId);
                break;
            case PORT_DRV8:
                PORTD_GPIODR8R |= (1 << uint8LocalPinId);
                break;
            }
            switch (ConfigPtr->Port_PinInternalAttach)
            {
            case PORT_PUR:
                PORTD_GPIOPUR |= (1 << uint8LocalPinId); 
                break;
            case PORT_PDR:
                PORTD_GPIOPDR |= (1 << uint8LocalPinId);
                break;
                default : break;
            }
            PORTD_GPIODEN |= (1 << uint8LocalPinId);
            break;
        case PORTE:
                if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
            {
                PORTE_GPIODIR &= ~(1 << uint8LocalPinId);
            }
            else
            {
                PORTE_GPIODIR |= (1 << uint8LocalPinId);
            }
            PORTE_GPIOAFSEL &= ~(1 << uint8LocalPinId);
            switch (ConfigPtr->Port_PinOutputCurrent)
            {
            case PORT_DRV2:
               PORTE_GPIODR2R |= (1 << uint8LocalPinId); 
                break;
            case PORT_DRV4:
                PORTE_GPIODR4R |= (1 << uint8LocalPinId);
                break;
            case PORT_DRV8:
                PORTE_GPIODR8R |= (1 << uint8LocalPinId);
                break;
            }
            switch (ConfigPtr->Port_PinInternalAttach)
            {
            case PORT_PUR:
                PORTE_GPIOPUR |= (1 << uint8LocalPinId); 
                break;
            case PORT_PDR:
                PORTE_GPIOPDR |= (1 << uint8LocalPinId);
                break;
                default : break;
            }
            PORTE_GPIODEN |= (1 << uint8LocalPinId);
            break;
        case PORTF:
                if (ConfigPtr->PortPinDirection == PORT_PIN_DIRECTION_INPUT)
            {
                PORTF_GPIODIR &= ~(1 << uint8LocalPinId);
            }
            else
            {
                PORTF_GPIODIR |= (1 << uint8LocalPinId);
            }
            PORTF_GPIOAFSEL &= ~(1 << uint8LocalPinId);
            switch (ConfigPtr->Port_PinOutputCurrent)
            {
            case PORT_DRV2:
                PORTF_GPIODR2R |= (1 << uint8LocalPinId); 
                break;
            case PORT_DRV4:
                PORTF_GPIODR4R |= (1 << uint8LocalPinId);
                break;
            case PORT_DRV8:
                PORTF_GPIODR8R |= (1 << uint8LocalPinId);
                break;
            }
            switch (ConfigPtr->Port_PinInternalAttach)
            {
            case PORT_PUR:
                PORTF_GPIOPUR |= (1 << uint8LocalPinId); 
                break;
            case PORT_PDR:
                PORTF_GPIOPDR |= (1 << uint8LocalPinId);
                break;
                default : break;
            }
            PORTF_GPIODEN |= (1 << uint8LocalPinId);
            break;
        }
    }
    

}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
/*SYSCTRL_BASE_ADDRESS*/