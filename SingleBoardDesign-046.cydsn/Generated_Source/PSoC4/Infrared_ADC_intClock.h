/*******************************************************************************
* File Name: Infrared_ADC_intClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Infrared_ADC_intClock_H)
#define CY_CLOCK_Infrared_ADC_intClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Infrared_ADC_intClock_StartEx(uint32 alignClkDiv);
#define Infrared_ADC_intClock_Start() \
    Infrared_ADC_intClock_StartEx(Infrared_ADC_intClock__PA_DIV_ID)

#else

void Infrared_ADC_intClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Infrared_ADC_intClock_Stop(void);

void Infrared_ADC_intClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Infrared_ADC_intClock_GetDividerRegister(void);
uint8  Infrared_ADC_intClock_GetFractionalDividerRegister(void);

#define Infrared_ADC_intClock_Enable()                         Infrared_ADC_intClock_Start()
#define Infrared_ADC_intClock_Disable()                        Infrared_ADC_intClock_Stop()
#define Infrared_ADC_intClock_SetDividerRegister(clkDivider, reset)  \
    Infrared_ADC_intClock_SetFractionalDividerRegister((clkDivider), 0u)
#define Infrared_ADC_intClock_SetDivider(clkDivider)           Infrared_ADC_intClock_SetDividerRegister((clkDivider), 1u)
#define Infrared_ADC_intClock_SetDividerValue(clkDivider)      Infrared_ADC_intClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Infrared_ADC_intClock_DIV_ID     Infrared_ADC_intClock__DIV_ID

#define Infrared_ADC_intClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Infrared_ADC_intClock_CTRL_REG   (*(reg32 *)Infrared_ADC_intClock__CTRL_REGISTER)
#define Infrared_ADC_intClock_DIV_REG    (*(reg32 *)Infrared_ADC_intClock__DIV_REGISTER)

#define Infrared_ADC_intClock_CMD_DIV_SHIFT          (0u)
#define Infrared_ADC_intClock_CMD_PA_DIV_SHIFT       (8u)
#define Infrared_ADC_intClock_CMD_DISABLE_SHIFT      (30u)
#define Infrared_ADC_intClock_CMD_ENABLE_SHIFT       (31u)

#define Infrared_ADC_intClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Infrared_ADC_intClock_CMD_DISABLE_SHIFT))
#define Infrared_ADC_intClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Infrared_ADC_intClock_CMD_ENABLE_SHIFT))

#define Infrared_ADC_intClock_DIV_FRAC_MASK  (0x000000F8u)
#define Infrared_ADC_intClock_DIV_FRAC_SHIFT (3u)
#define Infrared_ADC_intClock_DIV_INT_MASK   (0xFFFFFF00u)
#define Infrared_ADC_intClock_DIV_INT_SHIFT  (8u)

#else 

#define Infrared_ADC_intClock_DIV_REG        (*(reg32 *)Infrared_ADC_intClock__REGISTER)
#define Infrared_ADC_intClock_ENABLE_REG     Infrared_ADC_intClock_DIV_REG
#define Infrared_ADC_intClock_DIV_FRAC_MASK  Infrared_ADC_intClock__FRAC_MASK
#define Infrared_ADC_intClock_DIV_FRAC_SHIFT (16u)
#define Infrared_ADC_intClock_DIV_INT_MASK   Infrared_ADC_intClock__DIVIDER_MASK
#define Infrared_ADC_intClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Infrared_ADC_intClock_H) */

/* [] END OF FILE */
