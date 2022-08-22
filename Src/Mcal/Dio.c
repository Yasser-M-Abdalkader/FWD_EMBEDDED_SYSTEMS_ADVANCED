/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
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
#include "Dio.h"
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
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8 uint8LocalPortID = ChannelId / 8;
    uint8 uint8LocalPinNumber = ChannelId % 8;
    switch (uint8LocalPortID)
    {
    case PORTA: *(GPIOA_DATA + uint8LocalPinNumber) = Level;    break;
    case PORTB: *(GPIOB_DATA + uint8LocalPinNumber) = Level;    break; 
    case PORTC: *(GPIOC_DATA + uint8LocalPinNumber) = Level;    break;
    case PORTD: *(GPIOD_DATA + uint8LocalPinNumber) = Level;    break;
    case PORTE: *(GPIOE_DATA + uint8LocalPinNumber) = Level;    break;
    case PORTF: *(GPIOF_DATA + uint8LocalPinNumber) = Level;    break;
    }
}

void Dio_WritePort(Dio_PortType PortlId, Dio_PortLevelType Level)
{
    uint8 uint8LocalPortID = PortlId / 8;
    switch (uint8LocalPortID)
    {
    case PORTA: *(GPIOA_DATA + 0xff) = Level;    break;
    case PORTB: *(GPIOB_DATA + 0xff) = Level;    break; 
    case PORTC: *(GPIOC_DATA + 0xff) = Level;    break;
    case PORTD: *(GPIOD_DATA + 0xff) = Level;    break;
    case PORTE: *(GPIOE_DATA + 0xff) = Level;    break;
    case PORTF: *(GPIOF_DATA + 0xff) = Level;    break;
    }

}


Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    uint8 uint8LocalPortID = ChannelId / 8;
    uint8 uint8LocalPinNumber = ChannelId % 8;

    Dio_LevelType localChannelLevel = DIO_LOW;
    switch (uint8LocalPortID)
    {
    case PORTA: localChannelLevel = *(GPIOA_DATA + uint8LocalPinNumber);    break;
    case PORTB: localChannelLevel = *(GPIOB_DATA + uint8LocalPinNumber);    break; 
    case PORTC: localChannelLevel = *(GPIOC_DATA + uint8LocalPinNumber);    break;
    case PORTD: localChannelLevel = *(GPIOD_DATA + uint8LocalPinNumber);    break;
    case PORTE: localChannelLevel = *(GPIOE_DATA + uint8LocalPinNumber);    break;
    case PORTF: localChannelLevel = *(GPIOF_DATA + uint8LocalPinNumber);    break;
    } 
    return localChannelLevel;
}

Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    uint8 uint8LocalPortID = PortId / 8;
    Dio_PortLevelType localPortLevel = 0x00;
    switch (uint8LocalPortID)
    {
    case PORTA: localPortLevel = *(GPIOA_DATA + 0xff);    break;
    case PORTB: localPortLevel = *(GPIOB_DATA + 0xff);    break; 
    case PORTC: localPortLevel = *(GPIOC_DATA + 0xff);    break;
    case PORTD: localPortLevel = *(GPIOD_DATA + 0xff);    break;
    case PORTE: localPortLevel = *(GPIOE_DATA + 0xff);    break;
    case PORTF: localPortLevel = *(GPIOF_DATA + 0xff);    break;
    }

    return localPortLevel;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/