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
/*  GPTMTnMR
    GPTMCFG
    GPTMCTL
    GPTMIMR
    GPTMTAV*/

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
void Gpt_Init(const Gpt_ConfigType *ConfigPtr)
{

    switch (ConfigPtr->ChannelID)
    {
    case TIMER0:
        /* 1. Disable timer */
        CLR_BIT(GPT_TIMER0_BASE_ADDRESS->GPTMCTL, 0);

        /* 2. Select Stand Alon Mode */
        GPT_TIMER0_BASE_ADDRESS->GPTMCFG = 0x4;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_TIMER0_BASE_ADDRESS->GPTMTAMR, 4);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_TIMER0_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
        GPT_TIMER0_BASE_ADDRESS->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_TIMER0_BASE_ADDRESS->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;
        break;
    case TIMER1:
        /* 1. Disable timer */
        CLR_BIT(GPT_TIMER1_BASE_ADDRESS->GPTMCTL, 0);

        /* 2. Select Stand Alon Mode */
        GPT_TIMER1_BASE_ADDRESS->GPTMCFG = 0x4;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_TIMER1_BASE_ADDRESS->GPTMTAMR, 4);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_TIMER1_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
        GPT_TIMER1_BASE_ADDRESS->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_TIMER1_BASE_ADDRESS->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;
        break;
    case TIMER2:
        /* 1. Disable timer */
        CLR_BIT(GPT_TIMER2_BASE_ADDRESS->GPTMCTL, 0);

        /* 2. Select Stand Alon Mode */
        GPT_TIMER2_BASE_ADDRESS->GPTMCFG = 0x4;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_TIMER2_BASE_ADDRESS->GPTMTAMR, 4);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_TIMER2_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
        GPT_TIMER2_BASE_ADDRESS->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_TIMER2_BASE_ADDRESS->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;
        break;
    case TIMER3:
        /* 1. Disable timer */
        CLR_BIT(GPT_TIMER3_BASE_ADDRESS->GPTMCTL, 0);

        /* 2. Select Stand Alon Mode */
        GPT_TIMER3_BASE_ADDRESS->GPTMCFG = 0x4;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_TIMER3_BASE_ADDRESS->GPTMTAMR, 4);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_TIMER3_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
        GPT_TIMER3_BASE_ADDRESS->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_TIMER3_BASE_ADDRESS->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;
        break;
    case TIMER4:
        /* 1. Disable timer */
        CLR_BIT(GPT_TIMER4_BASE_ADDRESS->GPTMCTL, 0);

        /* 2. Select Stand Alon Mode */
        GPT_TIMER4_BASE_ADDRESS->GPTMCFG = 0x4;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_TIMER4_BASE_ADDRESS->GPTMTAMR, 4);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_TIMER4_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
        GPT_TIMER4_BASE_ADDRESS->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_TIMER4_BASE_ADDRESS->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;
        break;
    case TIMER5:
        /* 1. Disable timer */
        CLR_BIT(GPT_TIMER5_BASE_ADDRESS->GPTMCTL, 0);

        /* 2. Select Stand Alon Mode */
        GPT_TIMER5_BASE_ADDRESS->GPTMCFG = 0x4;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_TIMER5_BASE_ADDRESS->GPTMTAMR, 4);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_TIMER5_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
        GPT_TIMER5_BASE_ADDRESS->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_TIMER5_BASE_ADDRESS->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;
        break;

    case WIDE_TIMER0:
        /* 1. Disable timer */
        CLR_BIT(GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMCTL, 0);

        /* 2. Select Stand Alon Mode */
        GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMCFG = 0x4;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMTAMR, 4);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
        GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;

        break;
    case WIDE_TIMER1:
        /* 1. Disable timer */
        CLR_BIT(GPT_WIDE_TIMER1_BASE_ADDRESS->GPTMCTL, 0);

        /* 2. Select Stand Alon Mode */
        GPT_WIDE_TIMER1_BASE_ADDRESS->GPTMCFG = 0x4;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_WIDE_TIMER1_BASE_ADDRESS->GPTMTAMR, 4);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_WIDE_TIMER1_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
        GPT_WIDE_TIMER1_BASE_ADDRESS->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_WIDE_TIMER1_BASE_ADDRESS->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;
        break;
    case WIDE_TIMER2:
        /* 1. Disable timer */
        CLR_BIT(GPT_WIDE_TIMER2_BASE_ADDRESS->GPTMCTL, 0);

        /* 2. Select Stand Alon Mode */
        GPT_WIDE_TIMER2_BASE_ADDRESS->GPTMCFG = 0x4;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_WIDE_TIMER2_BASE_ADDRESS->GPTMTAMR, 4);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_WIDE_TIMER2_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
        GPT_WIDE_TIMER2_BASE_ADDRESS->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_WIDE_TIMER2_BASE_ADDRESS->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;
        break;
    case WIDE_TIMER3:
        /* 1. Disable timer */
        CLR_BIT(GPT_WIDE_TIMER3_BASE_ADDRESS->GPTMCTL, 0);

        /* 2. Select Stand Alon Mode */
        GPT_WIDE_TIMER3_BASE_ADDRESS->GPTMCFG = 0x4;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_WIDE_TIMER3_BASE_ADDRESS->GPTMTAMR, 4);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_WIDE_TIMER3_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
        GPT_WIDE_TIMER3_BASE_ADDRESS->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_WIDE_TIMER3_BASE_ADDRESS->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;
        break;
    case WIDE_TIMER4:
        /* 1. Disable timer */
        CLR_BIT(GPT_WIDE_TIMER4_BASE_ADDRESS->GPTMCTL, 0);

        /* 2. Select Stand Alon Mode */
        GPT_WIDE_TIMER4_BASE_ADDRESS->GPTMCFG = 0x4;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_WIDE_TIMER4_BASE_ADDRESS->GPTMTAMR, 4);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_WIDE_TIMER4_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
        GPT_WIDE_TIMER4_BASE_ADDRESS->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_WIDE_TIMER4_BASE_ADDRESS->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;
        break;
    case WIDE_TIMER5:
        /* 1. Disable timer */
        CLR_BIT(GPT_WIDE_TIMER5_BASE_ADDRESS->GPTMCTL, 0);

        /* 2. Select Stand Alon Mode */
        GPT_WIDE_TIMER5_BASE_ADDRESS->GPTMCFG = 0x4;

        /* 3. Select Timer Direction (Count Up) */
        SET_BIT(GPT_WIDE_TIMER5_BASE_ADDRESS->GPTMTAMR, 4);

        /* 4. Select Timer Mode (One-Shot Timer mode, Periodic Timer mode) */
        GPT_WIDE_TIMER5_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
        GPT_WIDE_TIMER5_BASE_ADDRESS->GPTMTAMR |= (ConfigPtr->GptChannelMode);

        /* 5. Set Prescalar */
        GPT_WIDE_TIMER5_BASE_ADDRESS->GPTMTAPR = (16 / ConfigPtr->Gpt_ChannelTickFrequency) - 1;
        break;
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
    switch (Channel)
    {
    case TIMER0:
        /* Load the value to the match value */
        GPT_TIMER0_BASE_ADDRESS->GPTMTAILR = Value;
        SET_BET(GPT_TIMER0_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_TIMER0_BASE_ADDRESS->GPTMRIS, 0) == 0)
        {
            /* code */
        }
        break;
    case TIMER1:
        /* Load the value to the match value */
        GPT_TIMER1_BASE_ADDRESS->GPTMTAILR = Value;
        SET_BET(GPT_TIMER1_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_TIMER1_BASE_ADDRESS->GPTMRIS, 0) == 0)
        {
            /* code */
        }
        break;
    case TIMER2:
        /* Load the value to the match value */
        GPT_TIMER2_BASE_ADDRESS->GPTMTAILR = Value;
        SET_BET(GPT_TIMER2_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_TIMER2_BASE_ADDRESS->GPTMRIS, 0) == 0)
        {
            /* code */
        }
        break;
    case TIMER3:
        /* Load the value to the match value */
        GPT_TIMER3_BASE_ADDRESS->GPTMTAILR = Value;
        SET_BET(GPT_TIMER3_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_TIMER3_BASE_ADDRESS->GPTMRIS, 0) == 0)
        {
            /* code */
        }
        break;
    case TIMER4:
        /* Load the value to the match value */
        GPT_TIMER4_BASE_ADDRESS->GPTMTAILR = Value;
        SET_BET(GPT_TIMER4_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_TIMER4_BASE_ADDRESS->GPTMRIS, 0) == 0)
        {
            /* code */
        }
        break;
    case TIMER5:
        /* Load the value to the match value */
        GPT_TIMER5_BASE_ADDRESS->GPTMTAILR = Value;
        SET_BET(GPT_TIMER5_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_TIMER5_BASE_ADDRESS->GPTMRIS, 0) == 0)
        {
            /* code */
        }
        break;
    case WIDE_TIMER0:
        /* Load the value to the match value */
        GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMTAILR = Value;
        SET_BET(GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMRIS, 0) == 0)
        {
            /* code */
        }
        break;
    case WIDE_TIMER1:
        /* Load the value to the match value */
        GPT_WIDE_TIMER1_BASE_ADDRESS->GPTMTAILR = Value;
        SET_BET(GPT_WIDE_TIMER1_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_WIDE_TIMER1_BASE_ADDRESS->GPTMRIS, 0) == 0)
        {
            /* code */
        }
        break;
    case WIDE_TIMER2:
        /* Load the value to the match value */
        GPT_WIDE_TIMER2_BASE_ADDRESS->GPTMTAILR = Value;
        SET_BET(GPT_WIDE_TIMER2_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_WIDE_TIMER2_BASE_ADDRESS->GPTMRIS, 0) == 0)
        {
            /* code */
        }
        break;
    case WIDE_TIMER3:
        /* Load the value to the match value */
        GPT_WIDE_TIMER3_BASE_ADDRESS->GPTMTAILR = Value;
        SET_BET(GPT_WIDE_TIMER3_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_WIDE_TIMER3_BASE_ADDRESS->GPTMRIS, 0) == 0)
        {
            /* code */
        }
        break;
    case WIDE_TIMER4:
        /* Load the value to the match value */
        GPT_WIDE_TIMER4_BASE_ADDRESS->GPTMTAILR = Value;
        SET_BET(GPT_WIDE_TIMER4_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_WIDE_TIMER4_BASE_ADDRESS->GPTMRIS, 0) == 0)
        {
            /* code */
        }
        break;
    case WIDE_TIMER5:
        /* Load the value to the match value */
        GPT_WIDE_TIMER5_BASE_ADDRESS->GPTMTAILR = Value;
        SET_BET(GPT_WIDE_TIMER5_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_WIDE_TIMER5_BASE_ADDRESS->GPTMRIS, 0) == 0)
        {
            /* code */
        }
        break;
    default:
        break;
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
}

Std_ReturnType Gpt_PredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimerValuePtr)
{
}

/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/