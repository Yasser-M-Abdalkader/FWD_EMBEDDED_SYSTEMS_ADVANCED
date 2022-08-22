/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 ENReg[4];
}INTCTRL_EN;
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :3;
    uint32 VECPEND  :4;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 registerAccess;
    INTCTRL_BF bitAccess;
}INTCTRL_Tag;


typedef struct 
{
    uint32 PRI[16];
}INTCTRL_PRI;


typedef struct 
{
    uint32  GPIODIR;
    uint32  GPIOIS;
    uint32  GPIOIBE;
    uint32  GPIOIEV;
    uint32  GPIOIM;
    uint32  GPIORIS;
    uint32  GPIOMIS;
    uint32  GPIOICR;
    uint32  GPIOAFSEL;
    uint32  GPIODR2R;
    uint32  GPIODR4R;
    uint32  GPIODR8R;
    uint32  GPIOODR;
    uint32  GPIOPUR;
    uint32  GPIOPDR;
    uint32  GPIOSLR;
    uint32  GPIODEN;
    uint32  GPIOLOCK;
    uint32  GPIOCR;
    uint32  GPIOAMSEL;
    uint32  GPIOPCTL;
    uint32  GPIOADCCTL;
    uint32  GPIODMACTL;
    uint32  GPIOPeriphID4;
    uint32  GPIOPeriphID5;
    uint32  GPIOPeriphID6;
    uint32  GPIOPeriphID7;
    uint32  GPIOPeriphID0;
    uint32  GPIOPeriphID1;
    uint32  GPIOPeriphID2;
    uint32  GPIOPeriphID3;
    uint32  GPIOPCellID0;
    uint32  GPIOPCellID1;
    uint32  GPIOPCellID2;
    uint32  GPIOPCellID3;
}GPIO_RegisterType;





/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define SYSCTRL_BASE_ADDRESS                    0x400FE000

                   
#define GPIOA_DATA_BASE_ADDRESS                       (0x40058000)
#define GPIOA_BASE_ADDRESS                            ((volatile GPIO_RegisterType *)(GPIOA_DATA_BASE_ADDRESS + 0x400))   

#define GPIOB_DATA_BASE_ADDRESS                       0x40059000
#define GPIOB_BASE_ADDRESS                            ((volatile GPIO_RegisterType *)(GPIOB_DATA_BASE_ADDRESS + 0x400))

#define GPIOC_DATA_BASE_ADDRESS                       0x4005A000
#define GPIOC_BASE_ADDRESS                            ((volatile GPIO_RegisterType *)(GPIOC_DATA_BASE_ADDRESS + 0x400))

#define GPIOD_DATA_BASE_ADDRESS                       0x4005B000
#define GPIOD_BASE_ADDRESS                            ((volatile GPIO_RegisterType *)(GPIOD_DATA_BASE_ADDRESS + 0x400))

#define GPIOE_DATA_BASE_ADDRESS                       0x4005C000
#define GPIOE_BASE_ADDRESS                            ((volatile GPIO_RegisterType *)(GPIOE_DATA_BASE_ADDRESS + 0x400))

#define GPIOF_DATA_BASE_ADDRESS                       0x4005D000
#define GPIOF_BASE_ADDRESS                            ((volatile GPIO_RegisterType *)(GPIOF_DATA_BASE_ADDRESS + 0x400))



#define APINT                                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define PRI                                         ((volatile INTCTRL_PRI*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define EN                                          ((volatile INTCTRL_EN*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define INTCTRL                                     ((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define RCC                                         *((volatile uint32*)(SYSCTRL_BASE_ADDRESS+0x060))


#define GPIOA_DATA                                   ((volatile uint32*)(GPIOA_DATA_BASE_ADDRESS))
#define GPIOB_DATA                                   ((volatile uint32*)(GPIOB_DATA_BASE_ADDRESS))
#define GPIOC_DATA                                   ((volatile uint32*)(GPIOC_DATA_BASE_ADDRESS))
#define GPIOD_DATA                                   ((volatile uint32*)(GPIOD_DATA_BASE_ADDRESS))
#define GPIOE_DATA                                   ((volatile uint32*)(GPIOE_DATA_BASE_ADDRESS))
#define GPIOF_DATA                                   ((volatile uint32*)(GPIOF_DATA_BASE_ADDRESS))


#define GPIOA_REG                                     ((volatile GPIO_RegisterType*)(GPIOA_BASE_ADDRESS))
#define GPIOB_REG                                     ((volatile GPIO_RegisterType*)(GPIOB_BASE_ADDRESS))
#define GPIOC_REG                                     ((volatile GPIO_RegisterType*)(GPIOC_BASE_ADDRESS))
#define GPIOD_REG                                     ((volatile GPIO_RegisterType*)(GPIOD_BASE_ADDRESS))
#define GPIOE_REG                                     ((volatile GPIO_RegisterType*)(GPIOE_BASE_ADDRESS))
#define GPIOF_REG                                     ((volatile GPIO_RegisterType*)(GPIOF_BASE_ADDRESS))


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/