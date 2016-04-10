/*******************************************************************************
* File Name: HCSR04_Echo_4.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_HCSR04_Echo_4_H) /* Pins HCSR04_Echo_4_H */
#define CY_PINS_HCSR04_Echo_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "HCSR04_Echo_4_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} HCSR04_Echo_4_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   HCSR04_Echo_4_Read(void);
void    HCSR04_Echo_4_Write(uint8 value);
uint8   HCSR04_Echo_4_ReadDataReg(void);
#if defined(HCSR04_Echo_4__PC) || (CY_PSOC4_4200L) 
    void    HCSR04_Echo_4_SetDriveMode(uint8 mode);
#endif
void    HCSR04_Echo_4_SetInterruptMode(uint16 position, uint16 mode);
uint8   HCSR04_Echo_4_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void HCSR04_Echo_4_Sleep(void); 
void HCSR04_Echo_4_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(HCSR04_Echo_4__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define HCSR04_Echo_4_DRIVE_MODE_BITS        (3)
    #define HCSR04_Echo_4_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - HCSR04_Echo_4_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the HCSR04_Echo_4_SetDriveMode() function.
         *  @{
         */
        #define HCSR04_Echo_4_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define HCSR04_Echo_4_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define HCSR04_Echo_4_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define HCSR04_Echo_4_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define HCSR04_Echo_4_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define HCSR04_Echo_4_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define HCSR04_Echo_4_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define HCSR04_Echo_4_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define HCSR04_Echo_4_MASK               HCSR04_Echo_4__MASK
#define HCSR04_Echo_4_SHIFT              HCSR04_Echo_4__SHIFT
#define HCSR04_Echo_4_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HCSR04_Echo_4_SetInterruptMode() function.
     *  @{
     */
        #define HCSR04_Echo_4_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define HCSR04_Echo_4_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define HCSR04_Echo_4_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define HCSR04_Echo_4_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(HCSR04_Echo_4__SIO)
    #define HCSR04_Echo_4_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(HCSR04_Echo_4__PC) && (CY_PSOC4_4200L)
    #define HCSR04_Echo_4_USBIO_ENABLE               ((uint32)0x80000000u)
    #define HCSR04_Echo_4_USBIO_DISABLE              ((uint32)(~HCSR04_Echo_4_USBIO_ENABLE))
    #define HCSR04_Echo_4_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define HCSR04_Echo_4_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define HCSR04_Echo_4_USBIO_ENTER_SLEEP          ((uint32)((1u << HCSR04_Echo_4_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << HCSR04_Echo_4_USBIO_SUSPEND_DEL_SHIFT)))
    #define HCSR04_Echo_4_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << HCSR04_Echo_4_USBIO_SUSPEND_SHIFT)))
    #define HCSR04_Echo_4_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << HCSR04_Echo_4_USBIO_SUSPEND_DEL_SHIFT)))
    #define HCSR04_Echo_4_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(HCSR04_Echo_4__PC)
    /* Port Configuration */
    #define HCSR04_Echo_4_PC                 (* (reg32 *) HCSR04_Echo_4__PC)
#endif
/* Pin State */
#define HCSR04_Echo_4_PS                     (* (reg32 *) HCSR04_Echo_4__PS)
/* Data Register */
#define HCSR04_Echo_4_DR                     (* (reg32 *) HCSR04_Echo_4__DR)
/* Input Buffer Disable Override */
#define HCSR04_Echo_4_INP_DIS                (* (reg32 *) HCSR04_Echo_4__PC2)

/* Interrupt configuration Registers */
#define HCSR04_Echo_4_INTCFG                 (* (reg32 *) HCSR04_Echo_4__INTCFG)
#define HCSR04_Echo_4_INTSTAT                (* (reg32 *) HCSR04_Echo_4__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define HCSR04_Echo_4_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(HCSR04_Echo_4__SIO)
    #define HCSR04_Echo_4_SIO_REG            (* (reg32 *) HCSR04_Echo_4__SIO)
#endif /* (HCSR04_Echo_4__SIO_CFG) */

/* USBIO registers */
#if !defined(HCSR04_Echo_4__PC) && (CY_PSOC4_4200L)
    #define HCSR04_Echo_4_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define HCSR04_Echo_4_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define HCSR04_Echo_4_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define HCSR04_Echo_4_DRIVE_MODE_SHIFT       (0x00u)
#define HCSR04_Echo_4_DRIVE_MODE_MASK        (0x07u << HCSR04_Echo_4_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins HCSR04_Echo_4_H */


/* [] END OF FILE */
