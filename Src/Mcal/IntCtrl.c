/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/

/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
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


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{

    uint8 uint8ArrInterrupts[INTCTRL_PERI_EN_NUMBER] = INTCTRL_PERI_EN_ARR;

	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    uint32 uint32LocalAPINT = INTCTRL_PRI_LEVEL;
    uint32LocalAPINT <<= 8;
    uint32LocalAPINT |= 0x05FA0000;
    APINT = uint32LocalAPINT; 
    uint8 uint8LocalCounter;
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/ 

	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
    for (uint8LocalCounter = 0; uint8LocalCounter < INTCTRL_PERI_EN_NUMBER; uint8LocalCounter++)
    {
        uint8 uint8LocalEnReg = uint8ArrInterrupts[uint8LocalCounter]/32;
        uint8 uint8LocalEnBit = uint8ArrInterrupts[uint8LocalCounter]%32;
        EN->ENReg[uint8LocalEnReg] = ENABLE<<uint8LocalEnBit;
    }

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/