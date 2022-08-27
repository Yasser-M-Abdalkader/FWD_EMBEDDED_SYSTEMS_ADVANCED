#include "Std_Types.h"
#include "Port.h"
#include "Dio.h"


int main (void)
{
    uint8 localActivePints = 1;
    Port_ConfigType Port_Config[] = 
{
    {
        .PortPin = PF1,
        .PortPinDirection = PORT_PIN_DIRECTION_OUTPUT,
        .PortPinLevelValue = DIO_HIGH,
        .Port_PinOutputCurrent = PORT_DRV2,
        .Port_PinInternalAttach = PORT_DIS_RESISTOR,
    }
};
    Port_Init(Port_Config, localActivePints);
    Dio_WriteChannel(PF1, DIO_HIGH);
		
}
