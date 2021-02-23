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
#include "IntCtrl_Lcfg.c"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define NVIC_GROUPING_SYSTEM_XXX    0x05FA0400
#define NVIC_GROUPING_SYSTEM_XXY    0x05FA0500
#define NVIC_GROUPING_SYSTEM_XYY    0x05FA0600
#define NVIC_GROUPING_SYSTEM_YYY    0x05FA0700

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
* \Syntax          : Svoid IntCrtl_Init(void)        
* \Description     : NVIC initialization                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : void
*******************************************************************************/
void IntCrtl_Init(void)
{
	Nvic_IntType intNum;
	uint8  Group, SubGroup,i,GroupingField;
	uint32 enRegOffset, enBitOffset;
	uint32 priRegOffset, priBitOffset;
	
	/* configure grouping and subgrouping int APINT register in SCB */
	
	#define		SCB_AIRCR		*((volatile uint32 *)(0xE000ED00+0x0C))
	SCB_AIRCR = NVIC_GROUPING_SYSTEM;
	
	for(i=0; i< NVIC_ACTIVATED_INT_SIZE ;i++)
	{
        intNum			= NVIC_Cfg[i].Interupt_Number;
		Group		    = NVIC_Cfg[i].Group_Priority;
		SubGroup        = NVIC_Cfg[i].SubGroup_Priority;
		
		/* enable\disable based on user configuration */
		if(intNum < 32)
		{
			NVIC_ISER0 = (1<<intNum);
		}
		else if(intNum < 60)
		{
			intNum -=32;
			NVIC_ISER1 = (1<<intNum);
		}
		else 
		{
			/*	return Error	 */
		}

			#if NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXX
						GroupingField = Group;
						
			#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXY
						GroupingField = ((Group<<1)&0x6) | (SubGroup&0x1);
						
			#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XYY
				    	GroupingField = ((Group<<2)&0x4) | (SubGroup&0x3);
						
			#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_YYY
					    GroupingField = Group;
			#else
				#error INVALID GROUPING SELECTION			
			#endif
			
			/* asign group\subgroup priority */
			if(intNum < 60)
			{
				NVIC_IPR[intNum] =  GroupingField;
			}
			else
			{
				/*	Return ERROR				*/
			}		
	}	
}



/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
