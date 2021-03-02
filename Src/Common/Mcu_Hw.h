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
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/***************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES FOR INTCTRL 
 ***************************************************/
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
    uint32       R;
    INTCTRL_BF   B;
	
}INTCTRL_Tag;

/**************************************
*   NVIC REGISTRE
***************************************/
#define NVIC_ENABLE_BASE_ADDRESS         0xE000E100
#define NVIC_PRI_BASE_ADDRESS            0xE000E400
/**************************************
*   SYSTEM CONTROL REGISTRES
***************************************/
#define SYSCONTROL_BASE_ADDRESS           0x400FE000
#define RESC                            (*((volatile uint32*)0x400FE05C))
#define RCC                             (*((volatile RCC_TAG*)0x400FE060))
#define RCC2                            (*((volatile RCC2_TAG*)0x400FE070))
#define PLLSTAT                         (*((volatile uint32*)0x400FE168))

typedef struct
{
	uint32 MOSCDIS  :1;
	uint32          :3;
	uint32 OSCSRC   :2;
	uint32 XTAL     :5;
	uint32 BYPASS   :1;
	uint32          :1;
	uint32 PWRDN    :1;
	uint32          :3;
	uint32 PWMDIV   :3;
	uint32 USEPWMDIV:1;
	uint32          :1;
	uint32 USESYSDIV:1;
	uint32 SYSDIV   :4;
	uint32 ACG      :1;
	uint32          :4;	
}Mcu_StrBF;	
	
typedef union
{
	uint32 R;
	Mcu_StrBF B;

}RCC_TAG;

typedef struct
{
	uint32              :4;
	uint32  OSCSRC2     :3;
	uint32              :4;
	uint32  BYPASS      :1;
	uint32              :1;
	uint32  PWRDN2      :1;
	uint32  USBPWRDN    :1;
	uint32              :1;
	uint32              :6;
	uint32  SYSDIV2LSB  :1;
	uint32  SYSDIV2     :6;
	uint32              :1;
	uint32  DIV400      :1;
	uint32  USERCC2     :1;
}Mcu_StrBF2;	
	
typedef union
{
	uint32 R;
	Mcu_StrBF2 B;

}RCC2_TAG;
#define SYSCONTROL_RCG_BASE_ADDR    0x400FE600

#define RCGCGPIO_OFFSET                  0x608
#define RCGCGPIO                        (*((volatile uint32*)(SYSCONTROL_RCG_BASE_ADDR+RCGCGPIO_OFFSET))


#define SYSCTR_RCG_BASE_ADDR    0x400FE600
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define GET_HWREG(BaseAddr,RegOffset)      *((volatile uint32*)(BaseAddr+RegOffset))
#define GPIODIR(BaseAddr)                  *((volatile uint32*)BaseAddr+GPIODIR_OFFSET) 

#define BASE_ADDRESS_PRE                              0x40000000
#define BASE_ADDRESS_PRE_ALIAS                        0x42000000

#define GET_RegisterOffset(RegisterAddr)              ((RegisterAddr - BASE_ADDRESS_PRE)/4)
#define GET_BitOffset(RegisterAddr,BitPos)            ((GET_RegisterOffset(RegisterAddr)*32) + BitPos)
#define GET_BBAlIAS_PRE_REG(RegisterAddr, BitPos)     (*(volatile uint32*)((GET_BitOffset(RegisterAddr,BitPos)*4) + BASE_ADDRESS_PRE_ALIAS))
 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
