#include "Std_Types.h"
#include "Port.h"
#include "Dio.h"


int main (void)
{
    Port_ConfigType Port_Config[PORT_PINS_NUMBER] = 
{
    {
        .PortPin = PA5,
        .PortPinDirection = PORT_PIN_DIRECTION_OUTPUT,
        .PortPinLevelValue = STD_HIGH,
        .Port_PinOutputCurrent = PORT_DRV2,
        .Port_PinInternalAttach = PORT_DIS_RESISTOR,
    }
};
    Port_Init(Port_Config);
    Dio_WriteChannel(PA5, STD_HIGH);
		
}
