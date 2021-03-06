/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


const Nvic_CfgType NVIC_Cfg[NVIC_ACTIVATED_INT_SIZE] ={
	/* Interupt_Number    Group_Priority     SubGroup_Priority */
  { NVIC_GPIO_PORT_B,    2,                       1                  },
  { NVIC_UART_2,         1,                       0                  },
  { NVIC_UART_3,         2,                       0                  },
  { NVIC_16_32_TIMER_5_B,3,                       1                  },
  { NVIC_PWM_1_GEN_0,    0,                       0                  },
 
};


/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
