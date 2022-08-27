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
    uint32 VECPEND  :8;
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
}GPT_RegisterType;






/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define SYSCTRL_BASE_ADDRESS                   0x400FE000




#define GPT_TIMER0_BASE_ADDRESS                 (((volatile GPT_RegisterType *)0x40030000))
#define GPT_TIMER1_BASE_ADDRESS                 (((volatile GPT_RegisterType *)0x40031000))
#define GPT_TIMER2_BASE_ADDRESS                 (((volatile GPT_RegisterType *)0x40032000))
#define GPT_TIMER3_BASE_ADDRESS                 (((volatile GPT_RegisterType *)0x40033000))
#define GPT_TIMER4_BASE_ADDRESS                 (((volatile GPT_RegisterType *)0x40034000))
#define GPT_TIMER5_BASE_ADDRESS                 (((volatile GPT_RegisterType *)0x40035000))

#define GPT_WIDE_TIMER0_BASE_ADDRESS            (((volatile GPT_RegisterType *)0x40036000))     
#define GPT_WIDE_TIMER1_BASE_ADDRESS            (((volatile GPT_RegisterType *)0x40037000))
#define GPT_WIDE_TIMER2_BASE_ADDRESS            (((volatile GPT_RegisterType *)0x4004C000))
#define GPT_WIDE_TIMER3_BASE_ADDRESS            (((volatile GPT_RegisterType *)0x4004D000))     
#define GPT_WIDE_TIMER4_BASE_ADDRESS            (((volatile GPT_RegisterType *)0x4004E000))
#define GPT_WIDE_TIMER5_BASE_ADDRESS            (((volatile GPT_RegisterType *)0x4004F000))

                   




#define APINT                                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define PRI                                         ((volatile INTCTRL_PRI*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define EN                                          ((volatile INTCTRL_EN*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define INTCTRL                                     ((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define RCC                                         (*((volatile uint32*)(SYSCTRL_BASE_ADDRESS+0x060)))
#define RCGCGPIO                                    (*((volatile uint32*)(SYSCTRL_BASE_ADDRESS+0x0608))) 




#define GPIOA_BASE_ADDRESS                           (0x40004000)
#define PORTA_GPIODATA                               GPIOA_BASE_ADDRESS
#define PORTA_GPIODIR                                (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x400))
#define PORTA_GPIOIS                                 (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x404))
#define PORTA_GPIOIBE                                (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x408))
#define PORTA_GPIOIEV                                (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x40C))
#define PORTA_GPIOIM                                 (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x410))
#define PORTA_GPIORIS                                (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x414))
#define PORTA_GPIOMIS                                (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x418))
#define PORTA_GPIOICR                                (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x41C))
#define PORTA_GPIOAFSEL                              (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x420))
#define PORTA_GPIODR2R                               (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x500))
#define PORTA_GPIODR4R                               (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x504))
#define PORTA_GPIODR8R                               (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x508))
#define PORTA_GPIOODR                                (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x50C))
#define PORTA_GPIOPUR                                (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x510))
#define PORTA_GPIOPDR                                (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x514))
#define PORTA_GPIOSLR                                (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x518))
#define PORTA_GPIODEN                                (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x51C))
#define PORTA_GPIOLOCK                               (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x520))
#define PORTA_GPIOCR                                 (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x524))
#define PORTA_GPIOAMSEL                              (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x528))
#define PORTA_GPIOPCTL                               (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x52C))
#define PORTA_GPIOADCCTL                             (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x530))
#define PORTA_GPIODMACTL                             (*(uint32 *)(GPIOA_BASE_ADDRESS + 0x534))



#define GPIOB_BASE_ADDRESS                       0x40005000
#define PORTB_GPIODATA                                     (GPIOB_BASE_ADDRESS)
#define PORTB_GPIODIR                                (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x400))
#define PORTB_GPIOIS                                 (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x404))
#define PORTB_GPIOIBE                                (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x408))
#define PORTB_GPIOIEV                                (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x40C))
#define PORTB_GPIOIM                                 (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x410))
#define PORTB_GPIORIS                                (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x414))
#define PORTB_GPIOMIS                                (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x418))
#define PORTB_GPIOICR                                (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x41C))
#define PORTB_GPIOAFSEL                              (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x420))
#define PORTB_GPIODR2R                               (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x500))
#define PORTB_GPIODR4R                               (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x504))
#define PORTB_GPIODR8R                               (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x508))
#define PORTB_GPIOODR                                (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x50C))
#define PORTB_GPIOPUR                                (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x510))
#define PORTB_GPIOPDR                                (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x514))
#define PORTB_GPIOSLR                                (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x518))
#define PORTB_GPIODEN                                (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x51C))
#define PORTB_GPIOLOCK                               (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x520))
#define PORTB_GPIOCR                                 (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x524))
#define PORTB_GPIOAMSEL                              (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x528))
#define PORTB_GPIOPCTL                               (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x52C))
#define PORTB_GPIOADCCTL                             (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x530))
#define PORTB_GPIODMACTL                             (*(uint32 *)(GPIOB_BASE_ADDRESS + 0x534))

#define GPIOC_BASE_ADDRESS                       0x40006000
#define PORTC_GPIODATA                            (GPIOC_BASE_ADDRESS)
#define PORTC_GPIODIR                             (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x400))
#define PORTC_GPIOIS                              (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x404))
#define PORTC_GPIOIBE                             (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x408))
#define PORTC_GPIOIEV                             (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x40C))
#define PORTC_GPIOIM                              (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x410))
#define PORTC_GPIORIS                             (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x414))
#define PORTC_GPIOMIS                             (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x418))
#define PORTC_GPIOICR                             (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x41C))
#define PORTC_GPIOAFSEL                           (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x420))
#define PORTC_GPIODR2R                            (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x500))
#define PORTC_GPIODR4R                            (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x504))
#define PORTC_GPIODR8R                            (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x508))
#define PORTC_GPIOODR                             (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x50C))
#define PORTC_GPIOPUR                             (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x510))
#define PORTC_GPIOPDR                             (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x514))
#define PORTC_GPIOSLR                             (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x518))
#define PORTC_GPIODEN                             (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x51C))
#define PORTC_GPIOLOCK                            (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x520))
#define PORTC_GPIOCR                              (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x524))
#define PORTC_GPIOAMSEL                           (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x528))
#define PORTC_GPIOPCTL                            (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x52C))
#define PORTC_GPIOADCCTL                          (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x530))
#define PORTC_GPIODMACTL                          (*(uint32 *)(GPIOC_BASE_ADDRESS + 0x534))

#define GPIOD_BASE_ADDRESS                       0x40007000
#define PORTD_GPIODATA                             (GPIOD_BASE_ADDRESS)
#define PORTD_GPIODIR                              (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x400))
#define PORTD_GPIOIS                               (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x404))
#define PORTD_GPIOIBE                              (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x408))
#define PORTD_GPIOIEV                              (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x40C))
#define PORTD_GPIOIM                               (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x410))
#define PORTD_GPIORIS                              (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x414))
#define PORTD_GPIOMIS                              (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x418))
#define PORTD_GPIOICR                              (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x41C))
#define PORTD_GPIOAFSEL                            (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x420))
#define PORTD_GPIODR2R                             (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x500))
#define PORTD_GPIODR4R                             (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x504))
#define PORTD_GPIODR8R                             (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x508))
#define PORTD_GPIOODR                              (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x50C))
#define PORTD_GPIOPUR                              (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x510))
#define PORTD_GPIOPDR                              (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x514))
#define PORTD_GPIOSLR                              (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x518))
#define PORTD_GPIODEN                              (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x51C))
#define PORTD_GPIOLOCK                             (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x520))
#define PORTD_GPIOCR                               (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x524))
#define PORTD_GPIOAMSEL                            (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x528))
#define PORTD_GPIOPCTL                             (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x52C))
#define PORTD_GPIOADCCTL                           (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x530))
#define PORTD_GPIODMACTL                           (*(uint32 *)(GPIOD_BASE_ADDRESS + 0x534))

#define GPIOE_BASE_ADDRESS                          0x40024000
#define PORTE_GPIODATA                              (GPIOE_BASE_ADDRESS)
#define PORTE_GPIODIR                               (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x400))
#define PORTE_GPIOIS                                (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x404))
#define PORTE_GPIOIBE                               (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x408))
#define PORTE_GPIOIEV                               (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x40C))
#define PORTE_GPIOIM                                (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x410))
#define PORTE_GPIORIS                               (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x414))
#define PORTE_GPIOMIS                               (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x418))
#define PORTE_GPIOICR                               (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x41C))
#define PORTE_GPIOAFSEL                             (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x420))
#define PORTE_GPIODR2R                              (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x500))
#define PORTE_GPIODR4R                              (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x504))
#define PORTE_GPIODR8R                              (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x508))
#define PORTE_GPIOODR                               (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x50C))
#define PORTE_GPIOPUR                               (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x510))
#define PORTE_GPIOPDR                               (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x514))
#define PORTE_GPIOSLR                               (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x518))
#define PORTE_GPIODEN                               (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x51C))
#define PORTE_GPIOLOCK                              (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x520))
#define PORTE_GPIOCR                                (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x524))
#define PORTE_GPIOAMSEL                             (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x528))
#define PORTE_GPIOPCTL                              (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x52C))
#define PORTE_GPIOADCCTL                            (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x530))
#define PORTE_GPIODMACTL                            (*(uint32 *)(GPIOE_BASE_ADDRESS + 0x534))

#define GPIOF_BASE_ADDRESS                              0x40025000
#define PORTF_GPIODATA                                  (GPIOF_BASE_ADDRESS)
#define PORTF_GPIODIR                                   (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x400))
#define PORTF_GPIOIS                                    (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x404))
#define PORTF_GPIOIBE                                   (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x408))
#define PORTF_GPIOIEV                                   (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x40C))
#define PORTF_GPIOIM                                    (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x410))
#define PORTF_GPIORIS                                   (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x414))
#define PORTF_GPIOMIS                                   (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x418))
#define PORTF_GPIOICR                                   (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x41C))
#define PORTF_GPIOAFSEL                                 (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x420))
#define PORTF_GPIODR2R                                  (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x500))
#define PORTF_GPIODR4R                                  (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x504))
#define PORTF_GPIODR8R                                  (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x508))
#define PORTF_GPIOODR                                   (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x50C))
#define PORTF_GPIOPUR                                   (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x510))
#define PORTF_GPIOPDR                                   (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x514))
#define PORTF_GPIOSLR                                   (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x518))
#define PORTF_GPIODEN                                   (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x51C))
#define PORTF_GPIOLOCK                                  (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x520))
#define PORTF_GPIOCR                                    (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x524))
#define PORTF_GPIOAMSEL                                 (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x528))
#define PORTF_GPIOPCTL                                  (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x52C))
#define PORTF_GPIOADCCTL                                (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x530))
#define PORTF_GPIODMACTL                                (*(uint32 *)(GPIOF_BASE_ADDRESS + 0x534))


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/