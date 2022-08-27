/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
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
#include "Bit_MATH.h"
#include "Gpt.h"
#include "Mcu_Hw.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/
#define TAEN 0
#define TACDIR  4
#define TATORIS 0
#define CONCATENATE_TIMERS 0x00
#define SPLIT_TIMERS 0x4
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static volatile GPT_RegisterType *GPT_BASE_ADDRESS_TIMER[] =
    {
        GPT_TIMER0_BASE_ADDRESS,
        GPT_TIMER1_BASE_ADDRESS,
        GPT_TIMER2_BASE_ADDRESS,
        GPT_TIMER3_BASE_ADDRESS,
        GPT_TIMER4_BASE_ADDRESS,
        GPT_TIMER5_BASE_ADDRESS,
        GPT_WIDE_TIMER0_BASE_ADDRESS,
        GPT_WIDE_TIMER1_BASE_ADDRESS,
        GPT_WIDE_TIMER2_BASE_ADDRESS,
        GPT_WIDE_TIMER3_BASE_ADDRESS,
        GPT_WIDE_TIMER4_BASE_ADDRESS,
        GPT_WIDE_TIMER5_BASE_ADDRESS};
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
 * \Syntax          : void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
 * \Description     : Initiate General Purpose Timer
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : ConfigPtr   A pointer to user's configuration
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Gpt_Init(const Gpt_ConfigType *ConfigPtr, uint8 ConfigSize)
{

    uint8 localCounter;
    for (localCounter = 0; localCounter < ConfigSize; localCounter++)
    {
        /* 1. Disable Channel */
        CLR_BIT(GPT_BASE_ADDRESS_TIMER[ConfigPtr->ChannelID]->GPTMCTL, TAEN);

        /* 2. Select (individual, split timers) Mode */
        GPT_BASE_ADDRESS_TIMER[ConfigPtr->ChannelID]->GPTMCFG = SPLIT_TIMERS;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_BASE_ADDRESS_TIMER[ConfigPtr->ChannelID]->GPTMTAMR, TACDIR);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_BASE_ADDRESS_TIMER[ConfigPtr->ChannelID]->GPTMTAMR &= ~(0b11);
        GPT_BASE_ADDRESS_TIMER[ConfigPtr->ChannelID]->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_BASE_ADDRESS_TIMER[ConfigPtr->ChannelID]->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;
    }
}

/******************************************************************************
* \Syntax          : void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
* \Description     : Shall start the selected timer channel with a defined target time
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant (but not for the same timer channel)
* \Parameters (in) : Channel   The selecter timer
                   : Value     Target Time
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{

    /* 1. Set tthe upper bound for the timeout event */
    GPT_BASE_ADDRESS_TIMER[Channel]->GPTMTAILR = Value;

    /* 2. Enable Channel */
    SET_BET(GPT_BASE_ADDRESS_TIMER[Channel]->GPTMCTL, TAEN);

    /* 3. Poll Timeout */
    while (GET_BIT(GPT_BASE_ADDRESS_TIMER[Channel]->GPTMRIS, TATORIS) == 0)
    {
    }
}

/******************************************************************************
 * \Syntax          : void Gpt_StopTimer(Gpt_ChannelType Channel)
 * \Description     : Shall Stop the selected timer channel
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant (but not for the same timer channel)
 * \Parameters (in) : Channel   The selecter timer
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    /* 1. Disable Channel */
    CLR_BET(GPT_BASE_ADDRESS_TIMER[Channel]->GPTMCTL, TAEN);
}

Std_ReturnType Gpt_PredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimerValuePtr)
{
}

/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/