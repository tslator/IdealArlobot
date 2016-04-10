/*******************************************************************************
* File Name: Right_HB25_PWM_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Right_HB25_PWM.h"

static Right_HB25_PWM_BACKUP_STRUCT Right_HB25_PWM_backup;


/*******************************************************************************
* Function Name: Right_HB25_PWM_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Right_HB25_PWM_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Right_HB25_PWM_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Right_HB25_PWM_Sleep(void)
{
    if(0u != (Right_HB25_PWM_BLOCK_CONTROL_REG & Right_HB25_PWM_MASK))
    {
        Right_HB25_PWM_backup.enableState = 1u;
    }
    else
    {
        Right_HB25_PWM_backup.enableState = 0u;
    }

    Right_HB25_PWM_Stop();
    Right_HB25_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: Right_HB25_PWM_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Right_HB25_PWM_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Right_HB25_PWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Right_HB25_PWM_Wakeup(void)
{
    Right_HB25_PWM_RestoreConfig();

    if(0u != Right_HB25_PWM_backup.enableState)
    {
        Right_HB25_PWM_Enable();
    }
}


/* [] END OF FILE */
