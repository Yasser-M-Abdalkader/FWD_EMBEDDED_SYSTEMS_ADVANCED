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
    /* Set Pre-defined timer Configuration */

    /* Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making
        any changes. */
    CLR_BIT(GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMCTL, 0);
    /* Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000 */
    GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMCFG = 0x4;
    GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMTAMR &= ~(0b11);
    GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMTAMR |= (0x2);
    /* GPTMTAR: GPTM TimerA REgister | GPTMTAV: GPTM Timer A Value  */
    /* GPTMTAPR: GPTM Timer A Prescale */
    /* GPTMTAMATCHR: GPTM Timer A Match */

    /* Set GPTM Timer A Count Direction to Up Counts */
    SET_BIT(GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMTAMR, 4);

    /* Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
        Write a value of 0x1 for One-Shot mode.
        Write a value of 0x2 for Periodic mode. */
    /* Optionally configure the TnSNAPS, TnWOT, TnMTE, and TnCDIR bits in the GPTMTnMR register
to select whether to capture the value of the free-running timer at time-out, use an external
trigger to start counting, configure an additional trigger or interrupt, and count up or down */
    /* If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register
(GPTMIMR). */
    /* Set the TnEN bit in the GPTMCTL register to enable the timer and start counting */
    SET_BIT(GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMCTL, 0);
    /* Poll the GPTMRIS register or wait for the interrupt to be generated (if enabled). In both cases,
the status flags are cleared by writing a 1 to the appropriate bit of the GPTM Interrupt Clear
Register (GPTMICR). */

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
        GPT_TIMER0_BASE_ADDRESS->GPTMTAMATCHR = Value;
        SET_BET(GPT_TIMER0_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_TIMER0_BASE_ADDRESS->GPTMRIS, 1) == 0)
        {
            /* code */
        }
        break;
    case TIMER1:
        /* Load the value to the match value */
        GPT_TIMER1_BASE_ADDRESS->GPTMTAMATCHR = Value;
        SET_BET(GPT_TIMER1_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_TIMER1_BASE_ADDRESS->GPTMRIS, 1) == 0)
        {
            /* code */
        }
        break;
    case TIMER2:
        /* Load the value to the match value */
        GPT_TIMER2_BASE_ADDRESS->GPTMTAMATCHR = Value;
        SET_BET(GPT_TIMER2_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_TIMER2_BASE_ADDRESS->GPTMRIS, 1) == 0)
        {
            /* code */
        }
        break;
    case TIMER3:
        /* Load the value to the match value */
        GPT_TIMER3_BASE_ADDRESS->GPTMTAMATCHR = Value;
        SET_BET(GPT_TIMER3_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_TIMER3_BASE_ADDRESS->GPTMRIS, 1) == 0)
        {
            /* code */
        }
        break;
    case TIMER4:
        /* Load the value to the match value */
        GPT_TIMER4_BASE_ADDRESS->GPTMTAMATCHR = Value;
        SET_BET(GPT_TIMER4_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_TIMER4_BASE_ADDRESS->GPTMRIS, 1) == 0)
        {
            /* code */
        }
        break;
    case TIMER5:
        /* Load the value to the match value */
        GPT_TIMER5_BASE_ADDRESS->GPTMTAMATCHR = Value;
        SET_BET(GPT_TIMER5_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_TIMER5_BASE_ADDRESS->GPTMRIS, 1) == 0)
        {
            /* code */
        }
        break;
    case WIDE_TIMER0:
        /* Load the value to the match value */
        GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMTAMATCHR = Value;
        SET_BET(GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_WIDE_TIMER0_BASE_ADDRESS->GPTMRIS, 1) == 0)
        {
            /* code */
        }
        break;
    case WIDE_TIMER1:
        /* Load the value to the match value */
        GPT_WIDE_TIMER1_BASE_ADDRESS->GPTMTAMATCHR = Value;
        SET_BET(GPT_WIDE_TIMER1_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_WIDE_TIMER1_BASE_ADDRESS->GPTMRIS, 1) == 0)
        {
            /* code */
        }
        break;
    case WIDE_TIMER2:
        /* Load the value to the match value */
        GPT_WIDE_TIMER2_BASE_ADDRESS->GPTMTAMATCHR = Value;
        SET_BET(GPT_WIDE_TIMER2_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_WIDE_TIMER2_BASE_ADDRESS->GPTMRIS, 1) == 0)
        {
            /* code */
        }
        break;
    case WIDE_TIMER3:
        /* Load the value to the match value */
        GPT_WIDE_TIMER3_BASE_ADDRESS->GPTMTAMATCHR = Value;
        SET_BET(GPT_WIDE_TIMER3_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_WIDE_TIMER3_BASE_ADDRESS->GPTMRIS, 1) == 0)
        {
            /* code */
        }
        break;
    case WIDE_TIMER4:
        /* Load the value to the match value */
        GPT_WIDE_TIMER4_BASE_ADDRESS->GPTMTAMATCHR = Value;
        SET_BET(GPT_WIDE_TIMER4_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_WIDE_TIMER4_BASE_ADDRESS->GPTMRIS, 1) == 0)
        {
            /* code */
        }
        break;
    case WIDE_TIMER5:
        /* Load the value to the match value */
        GPT_WIDE_TIMER5_BASE_ADDRESS->GPTMTAMATCHR = Value;
        SET_BET(GPT_WIDE_TIMER5_BASE_ADDRESS->GPTMCTL, 0);

        /* Polling till the value is matched */
        while (GET_BIT(GPT_WIDE_TIMER5_BASE_ADDRESS->GPTMRIS, 1) == 0)
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