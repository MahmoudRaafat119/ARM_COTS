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
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*************************************** 
 *   NVIC REGISTRE
***************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define			NVIC_BASE_ADD		(0xE000E100)

#define			NVIC_ISER0			*((volatile uint32 * )(NVIC_BASE_ADD +0x000))
#define			NVIC_ISER1			*((volatile uint32 * )(NVIC_BASE_ADD +0x004))

#define			NVIC_ICER0			*((volatile uint32 * )(NVIC_BASE_ADD +0x080))
#define			NVIC_ICER1			*((volatile uint32 * )(NVIC_BASE_ADD +0x084))

#define			NVIC_ISPR0			*((volatile uint32 * )(NVIC_BASE_ADD +0x100))
#define			NVIC_ISPR1			*((volatile uint32 * )(NVIC_BASE_ADD +0x104))

#define			NVIC_ICPR0			*((volatile uint32 * )(NVIC_BASE_ADD +0x180))
#define			NVIC_ICPR1			*((volatile uint32 * )(NVIC_BASE_ADD +0x184))

#define			NVIC_IABR0			*((volatile uint32 * )(NVIC_BASE_ADD +0x200))
#define			NVIC_IABR1			*((volatile uint32 * )(NVIC_BASE_ADD +0x204))

#define			NVIC_IPR			((volatile uint8 *)(NVIC_BASE_ADD + 0x300))
#define	    	NVIC_IPR			((volatile uint8 *)(0xE000E400))


 #define			SET_BIT(REG,BIT_NUM)		(REG |=  (1<<BIT_NUM))

    #define			NVIC_4BITS_GROUP_0BITS_SUB		0x05FA0300
	#define			NVIC_3BITS_GROUP_1BITS_SUB		0x05FA0400
	#define			NVIC_1BITS_GROUP_3BITS_SUB		0x05FA0600
	#define			NVIC_0BITS_GROUP_4BITS_SUB		0x05FA0700


#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
