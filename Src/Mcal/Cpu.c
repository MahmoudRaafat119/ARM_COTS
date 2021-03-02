/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Cpu.c
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
#include "Cpu.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define CPU_SWITCH_TO_PRIVMODE_LOCAL()  __asm("MOV R0, 0x0\n");\
                                        __asm("MSR CONTROL, R0\n")
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint8 Counter = 0;
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

void Cpu_StartCriticalSection(void)
{
	Counter++;
	if(Counter <= 1)
    {
		   CPU_DISABLE_ALL_INTERRUPTS();
	  }
}

void Cpu_StopCriticalSection(void)
{
	Counter--;
	if(Counter == 0)
    {
		  CPU_ENABLE_ALL_INTERRUPTS();
	  }
}

/******************************************************************************
* \Syntax          : void Isr_SvcHandler(void)        
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Isr_SvcHandler(void)
{
	/*Switch to privledge Mode by writing to CONTROL Register */
	CPU_SWITCH_TO_PRIVMODE_LOCAL();
		
}

/**********************************************************************************************************************
 *  END OF FILE: Cpu.c
 *********************************************************************************************************************/
