/*******************************************************************************
* File Name: Encoder_B.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Encoder_B.h"

static Encoder_B_BACKUP_STRUCT  Encoder_B_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Encoder_B_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Encoder_B_SUT.c usage_Encoder_B_Sleep_Wakeup
*******************************************************************************/
void Encoder_B_Sleep(void)
{
    #if defined(Encoder_B__PC)
        Encoder_B_backup.pcState = Encoder_B_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Encoder_B_backup.usbState = Encoder_B_CR1_REG;
            Encoder_B_USB_POWER_REG |= Encoder_B_USBIO_ENTER_SLEEP;
            Encoder_B_CR1_REG &= Encoder_B_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Encoder_B__SIO)
        Encoder_B_backup.sioState = Encoder_B_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Encoder_B_SIO_REG &= (uint32)(~Encoder_B_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Encoder_B_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Encoder_B_Sleep() for an example usage.
*******************************************************************************/
void Encoder_B_Wakeup(void)
{
    #if defined(Encoder_B__PC)
        Encoder_B_PC = Encoder_B_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Encoder_B_USB_POWER_REG &= Encoder_B_USBIO_EXIT_SLEEP_PH1;
            Encoder_B_CR1_REG = Encoder_B_backup.usbState;
            Encoder_B_USB_POWER_REG &= Encoder_B_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Encoder_B__SIO)
        Encoder_B_SIO_REG = Encoder_B_backup.sioState;
    #endif
}


/* [] END OF FILE */
