/*******************************************************************************
* File Name: Left_PhaseCounter_Intr.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Left_PhaseCounter_Intr_H)
#define CY_ISR_Left_PhaseCounter_Intr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Left_PhaseCounter_Intr_Start(void);
void Left_PhaseCounter_Intr_StartEx(cyisraddress address);
void Left_PhaseCounter_Intr_Stop(void);

CY_ISR_PROTO(Left_PhaseCounter_Intr_Interrupt);

void Left_PhaseCounter_Intr_SetVector(cyisraddress address);
cyisraddress Left_PhaseCounter_Intr_GetVector(void);

void Left_PhaseCounter_Intr_SetPriority(uint8 priority);
uint8 Left_PhaseCounter_Intr_GetPriority(void);

void Left_PhaseCounter_Intr_Enable(void);
uint8 Left_PhaseCounter_Intr_GetState(void);
void Left_PhaseCounter_Intr_Disable(void);

void Left_PhaseCounter_Intr_SetPending(void);
void Left_PhaseCounter_Intr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Left_PhaseCounter_Intr ISR. */
#define Left_PhaseCounter_Intr_INTC_VECTOR            ((reg32 *) Left_PhaseCounter_Intr__INTC_VECT)

/* Address of the Left_PhaseCounter_Intr ISR priority. */
#define Left_PhaseCounter_Intr_INTC_PRIOR             ((reg32 *) Left_PhaseCounter_Intr__INTC_PRIOR_REG)

/* Priority of the Left_PhaseCounter_Intr interrupt. */
#define Left_PhaseCounter_Intr_INTC_PRIOR_NUMBER      Left_PhaseCounter_Intr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Left_PhaseCounter_Intr interrupt. */
#define Left_PhaseCounter_Intr_INTC_SET_EN            ((reg32 *) Left_PhaseCounter_Intr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Left_PhaseCounter_Intr interrupt. */
#define Left_PhaseCounter_Intr_INTC_CLR_EN            ((reg32 *) Left_PhaseCounter_Intr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Left_PhaseCounter_Intr interrupt state to pending. */
#define Left_PhaseCounter_Intr_INTC_SET_PD            ((reg32 *) Left_PhaseCounter_Intr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Left_PhaseCounter_Intr interrupt. */
#define Left_PhaseCounter_Intr_INTC_CLR_PD            ((reg32 *) Left_PhaseCounter_Intr__INTC_CLR_PD_REG)



#endif /* CY_ISR_Left_PhaseCounter_Intr_H */


/* [] END OF FILE */
