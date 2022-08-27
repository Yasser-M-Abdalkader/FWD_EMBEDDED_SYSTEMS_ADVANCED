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
    uint8 uint16LocalPortID = ChannelId / 8;
    uint8 uint16LocalPinNumber = ChannelId % 8;
    
    switch (uint16LocalPortID)
    {
    case DIO_PORTA: *((volatile uint32 *)(PORTA_GPIODATA +  (1 << (uint16LocalPinNumber + 2)))) = Level ;    break;
    case DIO_PORTB: *((volatile uint32 *)(PORTB_GPIODATA + (1 << (uint16LocalPinNumber + 2)))) = Level  ;    break; 
    case DIO_PORTC: *((volatile uint32 *)(PORTC_GPIODATA + (1 << (uint16LocalPinNumber + 2)))) = Level  ;    break;
    case DIO_PORTD: *(( volatile uint32 *)(PORTD_GPIODATA + (1 << (uint16LocalPinNumber + 2)))) = Level  ;    break;
    case DIO_PORTE: *((volatile uint32 *)(PORTE_GPIODATA + (1 << (uint16LocalPinNumber + 2)))) = Level  ;    break;
    case DIO_PORTF: *((volatile uint32 *)(PORTF_GPIODATA + (1 << (uint16LocalPinNumber + 2)))) = Level  ;    break;
    }
}

void Dio_WritePort(Dio_PortType PortlId, Dio_PortLevelType Level)
{
    uint8 uint8LocalPortID = PortlId / 8;
    switch (uint8LocalPortID)
    {
    case DIO_PORTA: *((uint32 *)(PORTA_GPIODATA + (1 << (0xff + 2)))) = Level;    break;
    case DIO_PORTB: *((uint32 *)(PORTB_GPIODATA + (1 << (0xff + 2)))) = Level;    break; 
    case DIO_PORTC: *((uint32 *)(PORTC_GPIODATA + (1 << (0xff + 2)))) = Level;    break;
    case DIO_PORTD: *((uint32 *)(PORTD_GPIODATA + (1 << (0xff + 2)))) = Level;    break;
    case DIO_PORTE: *((uint32 *)(PORTE_GPIODATA + (1 << (0xff + 2)))) = Level;    break;
    case DIO_PORTF: *((uint32 *)(PORTF_GPIODATA + (1 << (0xff + 2)))) = Level;    break;
    }

}


Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    uint8 uint8LocalPortID = ChannelId / 8;
    uint8 uint8LocalPinNumber = ChannelId % 8;

    Dio_LevelType localChannelLevel = DIO_LOW;
    switch (uint8LocalPortID)
    {
    case DIO_PORTA: localChannelLevel = *((uint32 *)(PORTA_GPIODATA+ (1 << (uint8LocalPinNumber + 2))));    break;
    case DIO_PORTB: localChannelLevel = *((uint32 *)(PORTB_GPIODATA+ (1 << (uint8LocalPinNumber + 2))));    break; 
    case DIO_PORTC: localChannelLevel = *((uint32 *)(PORTC_GPIODATA+ (1 << (uint8LocalPinNumber + 2))));    break;
    case DIO_PORTD: localChannelLevel = *((uint32 *)(PORTD_GPIODATA+ (1 << (uint8LocalPinNumber + 2))));    break;
    case DIO_PORTE: localChannelLevel = *((uint32 *)(PORTE_GPIODATA+ (1 << (uint8LocalPinNumber + 2))));    break;
    case DIO_PORTF: localChannelLevel = *((uint32 *)(PORTF_GPIODATA+ (1 << (uint8LocalPinNumber + 2))));    break;
    } 
    return localChannelLevel;
}

Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    uint8 uint8LocalPortID = PortId / 8;
    Dio_PortLevelType localPortLevel = 0x00;
    switch (uint8LocalPortID)
    {
    case DIO_PORTA: localPortLevel = *((uint32 *)(PORTA_GPIODATA+ (1 << (0xff + 2))));    break;
    case DIO_PORTB: localPortLevel = *((uint32 *)(PORTB_GPIODATA+ (1 << (0xff + 2))));    break; 
    case DIO_PORTC: localPortLevel = *((uint32 *)(PORTC_GPIODATA+ (1 << (0xff + 2))));    break;
    case DIO_PORTD: localPortLevel = *((uint32 *)(PORTD_GPIODATA+ (1 << (0xff + 2))));    break;
    case DIO_PORTE: localPortLevel = *((uint32 *)(PORTE_GPIODATA+ (1 << (0xff + 2))));    break;
    case DIO_PORTF: localPortLevel = *((uint32 *)(PORTF_GPIODATA+ (1 << (0xff + 2))));    break;
    }

    return localPortLevel;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/