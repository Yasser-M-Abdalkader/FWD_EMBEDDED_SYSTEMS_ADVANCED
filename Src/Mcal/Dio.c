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
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8 uint8LocalPortID = ChannelId / 8;
    uint8 uint16LocalPinNumber = ChannelId % 8;
    *((volatile uint32 *)(ACCESS_REGISTER(Port_PortsAddress[uint8LocalPortID], GPIODATA) + (1 << (uint16LocalPinNumber + 2)))) = Level << uint16LocalPinNumber;
}

void Dio_WritePort(Dio_PortType PortlId, Dio_PortLevelType Level)
{
    *((uint32 *)(ACCESS_REGISTER(Port_PortsAddress[PortlId], GPIODATA) + (0xff << 2))) = Level;
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Dio_LevelType localChannelLevel = DIO_LOW;
    uint8 uint8LocalPortID = ChannelId / 8;
    uint8 uint8LocalPinNumber = ChannelId % 8;
    
    localChannelLevel = (*((uint32 *)(ACCESS_REGISTER(Port_PortsAddress[uint8LocalPortID], GPIODATA) + (1 << (uint8LocalPinNumber + 2))))) >> uint8LocalPinNumber;

    return localChannelLevel;
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    Dio_PortLevelType localPortLevel = 0x00;

    localPortLevel = *((uint32 *)(ACCESS_REGISTER(Port_PortsAddress[PortId], GPIODATA) + ((0xff << 2))));

    return localPortLevel;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/