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
} INTCTRL_EN;
typedef struct
{
    uint32 VECACT : 8;
    uint32 : 3;
    uint32 RETBASE : 1;
    uint32 VECPEND : 8;
    uint32 : 2;
    uint32 ISRPEND : 1;
    uint32 ISRPRE : 1;
    uint32 : 1;
    uint32 PENDSTCLR : 1;
    uint32 PENDSTSET : 1;
    uint32 UNPENDSV : 1;
    uint32 PENDSV : 1;
    uint32 : 2;
    uint32 NMISET : 1;
} INTCTRL_BF;
typedef union
{
    uint32 registerAccess;
    INTCTRL_BF bitAccess;
} INTCTRL_Tag;

typedef struct
{
    uint32 PRI[16];
} INTCTRL_PRI;

typedef struct
{
    uint32 GPTMCFG;
    uint32 GPTMTAMR;
    uint32 GPTMTBMR;
    uint32 GPTMCTL;
    uint32 GPTMSYNC;
    uint32 GPTMIMR;
    uint32 GPTMRIS;
    uint32 GPTMMIS;
    uint32 GPTMICR;
    uint32 GPTMTAILR;
    uint32 GPTMTBILR;
    uint32 GPTMTAMATCHR;
    uint32 GPTMTBMATCHR;
    uint32 GPTMTAPR;
    uint32 GPTMTBPR;
    uint32 GPTMTAPMR;
    uint32 GPTMTBPMR;
    uint32 GPTMTAR;
    uint32 GPTMTBR;
    uint32 GPTMTAV;
    uint32 GPTMTBV;
    uint32 GPTMRTCPD;
    uint32 GPTMTAPS;
    uint32 GPTMTBPS;
    uint32 GPTMTAPV;
    uint32 GPTMTBPV;
} GPT_RegisterType;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS 0xE000E000
#define SYSCTRL_BASE_ADDRESS 0x400FE000

#define GPT_TIMER0_BASE_ADDRESS 0x40030000
#define GPT_TIMER1_BASE_ADDRESS 0x40031000
#define GPT_TIMER2_BASE_ADDRESS 0x40032000
#define GPT_TIMER3_BASE_ADDRESS 0x40033000
#define GPT_TIMER4_BASE_ADDRESS 0x40034000
#define GPT_TIMER5_BASE_ADDRESS 0x40035000

#define GPT_WIDE_TIMER0_BASE_ADDRESS 0x40036000
#define GPT_WIDE_TIMER1_BASE_ADDRESS 0x40037000
#define GPT_WIDE_TIMER2_BASE_ADDRESS 0x4004C000
#define GPT_WIDE_TIMER3_BASE_ADDRESS 0x4004D000
#define GPT_WIDE_TIMER4_BASE_ADDRESS 0x4004E000
#define GPT_WIDE_TIMER5_BASE_ADDRESS 0x4004F000

#define APINT *((volatile uint32 *)(CORTEXM4_PERI_BASE_ADDRESS + 0xD0C))
#define PRI ((volatile INTCTRL_PRI *)(CORTEXM4_PERI_BASE_ADDRESS + 0x400))
#define EN ((volatile INTCTRL_EN *)(CORTEXM4_PERI_BASE_ADDRESS + 0x100))
#define INTCTRL ((volatile INTCTRL_Tag *)(CORTEXM4_PERI_BASE_ADDRESS + 0xD04))
#define RCC (*((volatile uint32 *)(SYSCTRL_BASE_ADDRESS + 0x060)))
#define RCGCGPIO (*((volatile uint32 *)(SYSCTRL_BASE_ADDRESS + 0x0608)))

#define GPIOA_BASE_ADDRESS 0x40004000
#define GPIOB_BASE_ADDRESS 0x40005000
#define GPIOC_BASE_ADDRESS 0x40006000
#define GPIOD_BASE_ADDRESS 0x40007000
#define GPIOE_BASE_ADDRESS 0x40024000
#define GPIOF_BASE_ADDRESS 0x40025000


#define GPIODATA 0x00
#define GPIODIR 0x400
#define GPIOIS 0x404
#define GPIOIBE 0x408
#define GPIOIEV 0x40C
#define GPIOIM 0x410
#define GPIORIS 0x414
#define GPIOMIS 0x418
#define GPIOICR 0x41C
#define GPIOAFSEL 0x420
#define GPIODR2R 0x500
#define GPIODR4R 0x504
#define GPIODR8R 0x508
#define GPIOODR 0x50C
#define GPIOPUR 0x510
#define GPIOPDR 0x514
#define GPIOSLR 0x518
#define GPIODEN 0x51C
#define GPIOLOCK 0x520
#define GPIOCR 0x524
#define GPIOAMSEL 0x528
#define GPIOPCTL 0x52C
#define GPIOADCCTL 0x530
#define GPIODMACTL 0x534



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define ACCESS_REGISTER(PERIPHERAL_BASE_ADDRESS, REGISTER) (*(volatile uint32 *)((PERIPHERAL_BASE_ADDRESS) + (REGISTER)))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#endif /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/