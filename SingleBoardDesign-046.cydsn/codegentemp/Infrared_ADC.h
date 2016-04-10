/*******************************************************************************
* File Name: Infrared_ADC.h
* Version 2.30
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Sequencing Successive Approximation ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ADC_SAR_SEQ_Infrared_ADC_H)
#define CY_ADC_SAR_SEQ_Infrared_ADC_H

#include "cytypes.h"
#include "CyLib.h"


/***************************************
*      Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} Infrared_ADC_BACKUP_STRUCT;


/**************************************
*    Enumerated Types and Parameters
**************************************/

/*  Clock Source setting constants */
#define Infrared_ADC__EXTERNAL 0
#define Infrared_ADC__INTERNAL 1

/*  Sample Mode setting constants */
#define Infrared_ADC__FREERUNNING 0
#define Infrared_ADC__HARDWARESOC 1

/*  Reference type setting constants */
#define Infrared_ADC__VDDA_2 0
#define Infrared_ADC__VDDA 1
#define Infrared_ADC__INTERNAL1024 2
#define Infrared_ADC__INTERNAL1024BYPASSED 3
#define Infrared_ADC__INTERNALVREF 4
#define Infrared_ADC__INTERNALVREFBYPASSED 5
#define Infrared_ADC__VDDA_2BYPASSED 6
#define Infrared_ADC__EXTERNALVREF 7

/* Input buffer gain setting constants */
#define Infrared_ADC__DISABLED 0
#define Infrared_ADC__ONE 1
#define Infrared_ADC__TWO 2
#define Infrared_ADC__FOUR 3
#define Infrared_ADC__EIGHT 4
#define Infrared_ADC__SIXTEEN 5

/* Negative input setting sonstants in single ended mode */
#define Infrared_ADC__VSS 0
#define Infrared_ADC__VREF 1
#define Infrared_ADC__OTHER 2

/* Compare mode setting constants:
*    Mode0 - Disable
*    Mode1 - Result < Low_Limit
*    Mode2 - Low_Limit <= Result < High_Limit
*    Mode3 - High_Limit <= Result
*    Mode4 - (Result < Low_Limit) or (High_Limit <= Result)
*/
#define Infrared_ADC__MODE0 0
#define Infrared_ADC__MODE1 1
#define Infrared_ADC__MODE2 2
#define Infrared_ADC__MODE3 3

#define Infrared_ADC__RES8 0
#define Infrared_ADC__RES10 1

#define Infrared_ADC__RIGHT 0
#define Infrared_ADC__LEFT 1

#define Infrared_ADC__FSIGNED 1
#define Infrared_ADC__FUNSIGNED 0

#define Infrared_ADC__ACCUMULATE 0
#define Infrared_ADC__FIXEDRESOLUTION 1



/***************************************
*   Conditional Compilation Parameters
****************************************/ 

#define Infrared_ADC_CY_SAR_IP_VER0               	(0u)
#define Infrared_ADC_CY_SAR_IP_VER1               	(1u)

#if (CY_PSOC4_4100 || CY_PSOC4_4200)
    #define Infrared_ADC_CY_SAR_IP_VER              (Infrared_ADC_CY_SAR_IP_VER0)
#else /* Other devices */
    #define Infrared_ADC_CY_SAR_IP_VER              (Infrared_ADC_CY_SAR_IP_VER1)
#endif  /* (CY_PSOC4_4100 || CY_PSOC4_4200) */


/***************************************
*    Initial Parameter Constants
***************************************/
#define Infrared_ADC_DEFAULT_SAMPLE_MODE_SEL        (0u)
#define Infrared_ADC_DEFAULT_VREF_SEL               (7u)
#define Infrared_ADC_DEFAULT_NEG_INPUT_SEL          (0u)
#define Infrared_ADC_DEFAULT_ALT_RESOLUTION_SEL     (0u)
#define Infrared_ADC_DEFAULT_JUSTIFICATION_SEL      (0u)
#define Infrared_ADC_DEFAULT_DIFF_RESULT_FORMAT_SEL (1u)
#define Infrared_ADC_DEFAULT_SE_RESULT_FORMAT_SEL   (1u)
#define Infrared_ADC_DEFAULT_CLOCK_SOURCE           (1u)
#define Infrared_ADC_DEFAULT_VREF_MV_VALUE          (2500)
#define Infrared_ADC_DEFAULT_BUFFER_GAIN            (0u)
#define Infrared_ADC_DEFAULT_AVG_SAMPLES_NUM        (0u)
#define Infrared_ADC_DEFAULT_AVG_SAMPLES_DIV        (int16)(0x100u >> (7u - 0u))
#define Infrared_ADC_DEFAULT_AVG_MODE               (1u)
#define Infrared_ADC_MAX_RESOLUTION                 (12u)
#define Infrared_ADC_DEFAULT_LOW_LIMIT              (0u)
#define Infrared_ADC_DEFAULT_HIGH_LIMIT             (2047u)
#define Infrared_ADC_DEFAULT_COMPARE_MODE           (0u)
#define Infrared_ADC_DEFAULT_ACLKS_NUM              (4u)
#define Infrared_ADC_DEFAULT_BCLKS_NUM              (4u)
#define Infrared_ADC_DEFAULT_CCLKS_NUM              (4u)
#define Infrared_ADC_DEFAULT_DCLKS_NUM              (4u)
#define Infrared_ADC_TOTAL_CHANNELS_NUM             (1u)
#define Infrared_ADC_SEQUENCED_CHANNELS_NUM         (1u)
#define Infrared_ADC_DEFAULT_EN_CHANNELS            (1u)
#define Infrared_ADC_NOMINAL_CLOCK_FREQ             (16000000)
#define Infrared_ADC_INJ_CHANNEL_ENABLED            (0u)
#define Infrared_ADC_IRQ_REMOVE                     (0u)

/* Determines whether the configuration contains external negative input. */
#define Infrared_ADC_SINGLE_PRESENT                 (0u)
#define Infrared_ADC_CHANNELS_MODE                  (0u)
#define Infrared_ADC_MAX_CHANNELS_EN_MASK           (0xffffu >> (16u - Infrared_ADC_SEQUENCED_CHANNELS_NUM))


/***************************************
*        Function Prototypes
***************************************/

void Infrared_ADC_Start(void);
void Infrared_ADC_Stop(void);
void Infrared_ADC_Init(void);
void Infrared_ADC_Enable(void);
void Infrared_ADC_StartConvert(void);
void Infrared_ADC_StopConvert(void);
uint32 Infrared_ADC_IsEndConversion(uint32 retMode);
int16 Infrared_ADC_GetResult16(uint32 chan);
void Infrared_ADC_SetChanMask(uint32 mask);
void Infrared_ADC_SetLowLimit(uint32 lowLimit);
void Infrared_ADC_SetHighLimit(uint32 highLimit);
void Infrared_ADC_SetLimitMask(uint32 mask);
void Infrared_ADC_SetSatMask(uint32 mask);
void Infrared_ADC_SetOffset(uint32 chan, int16 offset);
void Infrared_ADC_SetGain(uint32 chan, int32 adcGain);
#if(Infrared_ADC_INJ_CHANNEL_ENABLED)
    void Infrared_ADC_EnableInjection(void);
#endif /* Infrared_ADC_INJ_CHANNEL_ENABLED */
#if(Infrared_ADC_DEFAULT_JUSTIFICATION_SEL == Infrared_ADC__RIGHT)
    int16 Infrared_ADC_CountsTo_mVolts(uint32 chan, int16 adcCounts);
    int32 Infrared_ADC_CountsTo_uVolts(uint32 chan, int16 adcCounts);
    float32 Infrared_ADC_CountsTo_Volts(uint32 chan, int16 adcCounts);
#endif /* End Infrared_ADC_DEFAULT_JUSTIFICATION_SEL == Infrared_ADC__RIGHT */
void Infrared_ADC_Sleep(void);
void Infrared_ADC_Wakeup(void);
void Infrared_ADC_SaveConfig(void);
void Infrared_ADC_RestoreConfig(void);

CY_ISR_PROTO( Infrared_ADC_ISR );


/**************************************
*           API Constants
**************************************/
/* Constants for Sleep mode states */
#define Infrared_ADC_DISABLED                   (0x00u)
#define Infrared_ADC_ENABLED                    (0x01u)
#define Infrared_ADC_STARTED                    (0x02u)
#define Infrared_ADC_BOOSTPUMP_ENABLED          (0x04u)

/*   Constants for IsEndConversion() "retMode" parameter  */
#define Infrared_ADC_RETURN_STATUS              (0x01u)
#define Infrared_ADC_WAIT_FOR_RESULT            (0x02u)
#define Infrared_ADC_RETURN_STATUS_INJ          (0x04u)
#define Infrared_ADC_WAIT_FOR_RESULT_INJ        (0x08u)

#define Infrared_ADC_MAX_FREQUENCY              (18000000)       /*18Mhz*/

#define Infrared_ADC_RESOLUTION_12              (12u)
#define Infrared_ADC_RESOLUTION_10              (10u)
#define Infrared_ADC_RESOLUTION_8               (8u)

#define Infrared_ADC_10US_DELAY                 (10u)

#define Infrared_ADC_10V_COUNTS                 (10.0F)
#define Infrared_ADC_10MV_COUNTS                (10000)
#define Infrared_ADC_10UV_COUNTS                (10000000L)


/***************************************
* Global variables external identifier
***************************************/

extern uint8 Infrared_ADC_initVar;
extern volatile int16 Infrared_ADC_offset[Infrared_ADC_TOTAL_CHANNELS_NUM];
extern volatile int32 Infrared_ADC_countsPer10Volt[Infrared_ADC_TOTAL_CHANNELS_NUM];


/***************************************
*              Registers
***************************************/

#define Infrared_ADC_SAR_CTRL_REG                (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_CTRL )
#define Infrared_ADC_SAR_CTRL_PTR                ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_CTRL )

#define Infrared_ADC_SAR_SAMPLE_CTRL_REG         (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_SAMPLE_CTRL )
#define Infrared_ADC_SAR_SAMPLE_CTRL_PTR         ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_SAMPLE_CTRL )

#define Infrared_ADC_SAR_SAMPLE_TIME01_REG       (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_SAMPLE_TIME01 )
#define Infrared_ADC_SAR_SAMPLE_TIME01_PTR       ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_SAMPLE_TIME01 )

#define Infrared_ADC_SAR_SAMPLE_TIME23_REG       (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_SAMPLE_TIME23 )
#define Infrared_ADC_SAR_SAMPLE_TIME23_PTR       ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_SAMPLE_TIME23 )

#define Infrared_ADC_SAR_RANGE_THRES_REG         (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_RANGE_THRES )
#define Infrared_ADC_SAR_RANGE_THRES_PTR         ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_RANGE_THRES )

#define Infrared_ADC_SAR_RANGE_COND_REG          (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_RANGE_COND )
#define Infrared_ADC_SAR_RANGE_COND_PTR          ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_RANGE_COND )

#define Infrared_ADC_SAR_CHAN_EN_REG             (*(reg32 *) CYREG_SAR_CHAN_EN )
#define Infrared_ADC_SAR_CHAN_EN_PTR             ( (reg32 *) CYREG_SAR_CHAN_EN )

#define Infrared_ADC_SAR_START_CTRL_REG          (*(reg32 *) CYREG_SAR_START_CTRL )
#define Infrared_ADC_SAR_START_CTRL_PTR          ( (reg32 *) CYREG_SAR_START_CTRL )

#define Infrared_ADC_SAR_DFT_CTRL_REG            (*(reg32 *) CYREG_SAR_DFT_CTRL )
#define Infrared_ADC_SAR_DFT_CTRL_PTR            ( (reg32 *) CYREG_SAR_DFT_CTRL )

#define Infrared_ADC_SAR_CHAN_CONFIG_REG         (*(reg32 *) CYREG_SAR_CHAN_CONFIG00 )
#define Infrared_ADC_SAR_CHAN_CONFIG_PTR         ( (reg32 *) CYREG_SAR_CHAN_CONFIG00 )
#define Infrared_ADC_SAR_CHAN_CONFIG_IND         CYREG_SAR_CHAN_CONFIG00

#define Infrared_ADC_SAR_CHAN_WORK_REG           (*(reg32 *) CYREG_SAR_CHAN_WORK00 )
#define Infrared_ADC_SAR_CHAN_WORK_PTR           ( (reg32 *) CYREG_SAR_CHAN_WORK00 )

#define Infrared_ADC_SAR_CHAN_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT00 )
#define Infrared_ADC_SAR_CHAN_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT00 )
#define Infrared_ADC_SAR_CHAN_RESULT_IND         CYREG_SAR_CHAN_RESULT00

#define Infrared_ADC_SAR_CHAN0_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT00 )
#define Infrared_ADC_SAR_CHAN0_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT00 )

#define Infrared_ADC_SAR_CHAN1_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT01 )
#define Infrared_ADC_SAR_CHAN1_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT01 )

#define Infrared_ADC_SAR_CHAN2_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT02 )
#define Infrared_ADC_SAR_CHAN2_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT02 )

#define Infrared_ADC_SAR_CHAN3_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT03 )
#define Infrared_ADC_SAR_CHAN3_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT03 )

#define Infrared_ADC_SAR_CHAN4_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT04 )
#define Infrared_ADC_SAR_CHAN4_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT04 )

#define Infrared_ADC_SAR_CHAN5_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT05 )
#define Infrared_ADC_SAR_CHAN5_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT05 )

#define Infrared_ADC_SAR_CHAN6_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT06 )
#define Infrared_ADC_SAR_CHAN6_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT06 )

#define Infrared_ADC_SAR_CHAN7_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT07 )
#define Infrared_ADC_SAR_CHAN7_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT07 )

#if(Infrared_ADC_CY_SAR_IP_VER != Infrared_ADC_CY_SAR_IP_VER0)
    #define Infrared_ADC_SAR_CHAN8_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT08 )
    #define Infrared_ADC_SAR_CHAN8_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT08 )

    #define Infrared_ADC_SAR_CHAN9_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT09 )
    #define Infrared_ADC_SAR_CHAN9_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT09 )

    #define Infrared_ADC_SAR_CHAN10_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT010 )
    #define Infrared_ADC_SAR_CHAN10_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT010 )

    #define Infrared_ADC_SAR_CHAN11_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT011 )
    #define Infrared_ADC_SAR_CHAN11_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT011 )

    #define Infrared_ADC_SAR_CHAN12_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT012 )
    #define Infrared_ADC_SAR_CHAN12_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT012 )

    #define Infrared_ADC_SAR_CHAN13_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT013 )
    #define Infrared_ADC_SAR_CHAN13_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT013 )

    #define Infrared_ADC_SAR_CHAN14_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT014 )
    #define Infrared_ADC_SAR_CHAN14_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT014 )

    #define Infrared_ADC_SAR_CHAN15_RESULT_REG         (*(reg32 *) CYREG_SAR_CHAN_RESULT015 )
    #define Infrared_ADC_SAR_CHAN15_RESULT_PTR         ( (reg32 *) CYREG_SAR_CHAN_RESULT015 )
#endif /* (Infrared_ADC_CY_SAR_IP_VER != Infrared_ADC_CY_SAR_IP_VER0) */

#define Infrared_ADC_SAR_CHAN_WORK_VALID_REG     (*(reg32 *) CYREG_SAR_CHAN_WORK_VALID)
#define Infrared_ADC_SAR_CHAN_WORK_VALID_PTR     ( (reg32 *) CYREG_SAR_CHAN_WORK_VALID)

#define Infrared_ADC_SAR_CHAN_RESULT_VALID_REG   ( *(reg32 *) CYREG_SAR_CHAN_RESULT_VALID )
#define Infrared_ADC_SAR_CHAN_RESULT_VALID_PTR   ( (reg32 *) CYREG_SAR_CHAN_RESULT_VALID )

#define Infrared_ADC_SAR_STATUS_REG              (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_STATUS )
#define Infrared_ADC_SAR_STATUS_PTR              ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_STATUS )

#define Infrared_ADC_SAR_AVG_START_REG           (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_AVG_STAT )
#define Infrared_ADC_SAR_AVG_START_PTR           ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_AVG_STAT )

#define Infrared_ADC_SAR_INTR_REG                (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_INTR )
#define Infrared_ADC_SAR_INTR_PTR                ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_INTR )

#define Infrared_ADC_SAR_INTR_SET_REG            (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_INTR_SET )
#define Infrared_ADC_SAR_INTR_SET_PTR            ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_INTR_SET )

#define Infrared_ADC_SAR_INTR_MASK_REG           (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_INTR_MASK )
#define Infrared_ADC_SAR_INTR_MASK_PTR           ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_INTR_MASK )

#define Infrared_ADC_SAR_INTR_MASKED_REG         (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_INTR_MASKED )
#define Infrared_ADC_SAR_INTR_MASKED_PTR         ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_INTR_MASKED )

#define Infrared_ADC_SAR_SATURATE_INTR_REG       (*(reg32 *) CYREG_SAR_SATURATE_INTR )
#define Infrared_ADC_SAR_SATURATE_INTR_PTR       ( (reg32 *) CYREG_SAR_SATURATE_INTR )

#define Infrared_ADC_SAR_SATURATE_INTR_SET_REG   (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_SATURATE_INTR_SET )
#define Infrared_ADC_SAR_SATURATE_INTR_SET_PTR   ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_SATURATE_INTR_SET )

#define Infrared_ADC_SAR_SATURATE_INTR_MASK_REG  (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_SATURATE_INTR_MASK )
#define Infrared_ADC_SAR_SATURATE_INTR_MASK_PTR  ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_SATURATE_INTR_MASK )

#define Infrared_ADC_SAR_SATURATE_INTR_MASKED_REG \
                                                 (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED )
#define Infrared_ADC_SAR_SATURATE_INTR_MASKED_PTR \
                                                 ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED )

#define Infrared_ADC_SAR_RANGE_INTR_REG          (*(reg32 *) CYREG_SAR_RANGE_INTR )
#define Infrared_ADC_SAR_RANGE_INTR_PTR          ( (reg32 *) CYREG_SAR_RANGE_INTR )

#define Infrared_ADC_SAR_RANGE_INTR_SET_REG      (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_RANGE_INTR_SET )
#define Infrared_ADC_SAR_RANGE_INTR_SET_PTR      ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_RANGE_INTR_SET )

#define Infrared_ADC_SAR_RANGE_INTR_MASK_REG     (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_RANGE_INTR_MASK )
#define Infrared_ADC_SAR_RANGE_INTR_MASK_PTR     ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_RANGE_INTR_MASK )

#define Infrared_ADC_SAR_RANGE_INTR_MASKED_REG   (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_RANGE_INTR_MASKED )
#define Infrared_ADC_SAR_RANGE_INTR_MASKED_PTR   ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_RANGE_INTR_MASKED )

#define Infrared_ADC_SAR_INTR_CAUSE_REG          (*(reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_INTR_CAUSE )
#define Infrared_ADC_SAR_INTR_CAUSE_PTR          ( (reg32 *) Infrared_ADC_cy_psoc4_sar__SAR_INTR_CAUSE )

#define Infrared_ADC_SAR_INJ_CHAN_CONFIG_REG     (*(reg32 *) CYREG_SAR_INJ_CHAN_CONFIG)
#define Infrared_ADC_SAR_INJ_CHAN_CONFIG_PTR     ( (reg32 *) CYREG_SAR_INJ_CHAN_CONFIG)

#define Infrared_ADC_SAR_INJ_RESULT_REG          (*(reg32 *) CYREG_SAR_INJ_RESULT )
#define Infrared_ADC_SAR_INJ_RESULT_PTR          ( (reg32 *) CYREG_SAR_INJ_RESULT )

#define Infrared_ADC_MUX_SWITCH0_REG             (*(reg32 *)  CYREG_SAR_MUX_SWITCH0 )
#define Infrared_ADC_MUX_SWITCH0_PTR             ( (reg32 *)  CYREG_SAR_MUX_SWITCH0 )

#define Infrared_ADC_MUX_SWITCH_HW_CTRL_REG      (*(reg32 *)  CYREG_SAR_MUX_SWITCH_HW_CTRL )
#define Infrared_ADC_MUX_SWITCH_HW_CTRL_PTR      ( (reg32 *)  CYREG_SAR_MUX_SWITCH_HW_CTRL )

#define Infrared_ADC_PUMP_CTRL_REG               (*(reg32 *)  CYREG_SAR_PUMP_CTRL )
#define Infrared_ADC_PUMP_CTRL_PTR               ( (reg32 *)  CYREG_SAR_PUMP_CTRL )

#define Infrared_ADC_ANA_TRIM_REG                (*(reg32 *)  CYREG_SAR_ANA_TRIM )
#define Infrared_ADC_ANA_TRIM_PTR                ( (reg32 *)  CYREG_SAR_ANA_TRIM )

#define Infrared_ADC_WOUNDING_REG                (*(reg32 *)  CYREG_SAR_WOUNDING )
#define Infrared_ADC_WOUNDING_PTR                ( (reg32 *)  CYREG_SAR_WOUNDING )


/**************************************
*       Register Constants
**************************************/
#define Infrared_ADC_INTC_NUMBER                (Infrared_ADC_IRQ__INTC_NUMBER)
#define Infrared_ADC_INTC_PRIOR_NUMBER          (Infrared_ADC_IRQ__INTC_PRIOR_NUM)

/* defines for CTRL register */
#define Infrared_ADC_VREF_INTERNAL1024          (0x00000040Lu)
#define Infrared_ADC_VREF_EXTERNAL              (0x00000050Lu)
#define Infrared_ADC_VREF_VDDA_2                (0x00000060Lu)
#define Infrared_ADC_VREF_VDDA                  (0x00000070Lu)
#define Infrared_ADC_VREF_INTERNAL1024BYPASSED  (0x000000C0Lu)
#define Infrared_ADC_VREF_VDDA_2BYPASSED        (0x000000E0Lu)
#define Infrared_ADC_VREF_INTERNALVREF          (0x00000000Lu)
#define Infrared_ADC_VREF_INTERNALVREFBYPASSED  (0x00000000Lu)

#define Infrared_ADC_NEG_VSSA_KELVIN            (0x00000000Lu)
#define Infrared_ADC_NEG_VSSA                   (0x00000200Lu)
#define Infrared_ADC_NEG_VREF                   (0x00000E00Lu)
#if(Infrared_ADC_TOTAL_CHANNELS_NUM > 1u)
    #define Infrared_ADC_NEG_OTHER              (uint16)((uint16)Infrared_ADC_cy_psoc4_sarmux_8__VNEG << 9u)
#else
    #define Infrared_ADC_NEG_OTHER              (0)
#endif /* Infrared_ADC_TOTAL_CHANNELS_NUM > 1u */

#define Infrared_ADC_SAR_HW_CTRL_NEGVREF        (0x00002000Lu)

#define Infrared_ADC_BOOSTPUMP_EN               (0x00100000Lu)

#define Infrared_ADC_NORMAL_PWR                 (0x00000000Lu)
#define Infrared_ADC_HALF_PWR                   (0x01000000Lu)
#define Infrared_ADC_MORE_PWR                   (0x02000000Lu)
#define Infrared_ADC_QUARTER_PWR                (0x03000000Lu)
#define Infrared_ADC_DEEPSLEEP_ON               (0x08000000Lu)

#define Infrared_ADC_DSI_SYNC_CONFIG            (0x10000000Lu)
#define Infrared_ADC_DSI_MODE                   (0x20000000Lu)
#define Infrared_ADC_SWITCH_DISABLE             (0x40000000Lu)
#define Infrared_ADC_ENABLE                     (0x80000000Lu)

/* defines for STATUS register */
#define Infrared_ADC_STATUS_BUSY                (0x80000000Lu)

/* defines for SAMPLE_CTRL register */
#define Infrared_ADC_ALT_RESOLUTION_10BIT       (0x00000001Lu)
#define Infrared_ADC_ALT_RESOLUTION_8BIT        (0x00000000Lu)

#define Infrared_ADC_DATA_ALIGN_LEFT            (0x00000002Lu)
#define Infrared_ADC_DATA_ALIGN_RIGHT           (0x00000000Lu)

#define Infrared_ADC_SE_SIGNED_RESULT           (0x00000004Lu)
#define Infrared_ADC_SE_UNSIGNED_RESULT         (0x00000000Lu)

#define Infrared_ADC_DIFF_SIGNED_RESULT         (0x00000008Lu)
#define Infrared_ADC_DIFF_UNSIGNED_RESULT       (0x00000000Lu)

#define Infrared_ADC_AVG_CNT_OFFSET             (4u)
#define Infrared_ADC_AVG_CNT_MASK               (0x00000070Lu)
#define Infrared_ADC_AVG_SHIFT                  (0x00000080Lu)

#define Infrared_ADC_CONTINUOUS_EN              (0x00010000Lu)
#define Infrared_ADC_DSI_TRIGGER_EN             (0x00020000Lu)
#define Infrared_ADC_DSI_TRIGGER_LEVEL          (0x00040000Lu)
#define Infrared_ADC_DSI_SYNC_TRIGGER           (0x00080000Lu)
#define Infrared_ADC_EOS_DSI_OUT_EN             (0x80000000Lu)

/* defines for SAMPLE_TIME01 / SAMPLE_TIME23 registers */
#define Infrared_ADC_SAMPLE_TIME13_OFFSET       (16u)
#define Infrared_ADC_SAMPLE_TIME02_MASK         (0x000003FFLu)
#define Infrared_ADC_SAMPLE_TIME13_MASK         (0x03FF0000Lu)

/* defines for RANGE_THRES registers */
#define Infrared_ADC_RANGE_HIGH_OFFSET          (16u)
#define Infrared_ADC_RANGE_HIGH_MASK            (0xFFFF0000Lu)
#define Infrared_ADC_RANGE_LOW_MASK             (0x0000FFFFLu)

/* defines for RANGE_COND register */
/* Compare mode setting constants:
*    BELOW   - Result < Low_Limit
*    INSIDE  - Low_Limit <= Result < High_Limit
*    ABOVE   - High_Limit <= Result
*    OUTSIDE - (Result < Low_Limit) or (High_Limit <= Result)
*/
#define Infrared_ADC_CMP_MODE_BELOW             (0x00000000Lu)
#define Infrared_ADC_CMP_MODE_INSIDE            (0x40000000Lu)
#define Infrared_ADC_CMP_MODE_ABOVE             (0x80000000Lu)
#define Infrared_ADC_CMP_MODE_OUTSIDE           (0xC0000000Lu)
#define Infrared_ADC_CMP_OFFSET                 (30u)

/* defines for _START_CTRL register */
#define Infrared_ADC_FW_TRIGGER                 (0x00000001Lu)

/* defines for DFT_CTRL register */
#define Infrared_ADC_DLY_INC                    (0x00000001Lu)
#define Infrared_ADC_HIZ                        (0x00000002Lu)
#define Infrared_ADC_DFT_INC_MASK               (0x000F0000Lu)
#define Infrared_ADC_DFT_OUTC_MASK              (0x00700000Lu)
#define Infrared_ADC_SEL_CSEL_DFT_MASK          (0x0F000000Lu)

/* configuration for clock speed > 9 Mhz based on
* characterization results
*/
#define Infrared_ADC_SEL_CSEL_DFT_CHAR          (0x03000000Lu)
#define Infrared_ADC_EN_CSEL_DFT                (0x10000000Lu)
#define Infrared_ADC_DCEN                       (0x20000000Lu)
#define Infrared_ADC_ADFT_OVERRIDE              (0x80000000Lu)

/* defines for CHAN_CONFIG / DIE_CHAN_CONFIG register
*  and channelsConfig parameter
*/
#define Infrared_ADC_SARMUX_VIRT_SELECT         (0x00000070Lu)
#define Infrared_ADC_DIFFERENTIAL_EN            (0x00000100Lu)
#define Infrared_ADC_ALT_RESOLUTION_ON          (0x00000200Lu)
#define Infrared_ADC_AVERAGING_EN               (0x00000400Lu)

#define Infrared_ADC_SAMPLE_TIME_SEL_SHIFT      (12u)
#define Infrared_ADC_SAMPLE_TIME_SEL_MASK       (0x00003000Lu)

#define Infrared_ADC_CHANNEL_CONFIG_MASK        (0x00003700Lu)

/* for CHAN_CONFIG only */
#define Infrared_ADC_DSI_OUT_EN                 (0x80000000Lu)

/* for INJ_CHAN_CONFIG only */
#define Infrared_ADC_INJ_TAILGATING             (0x40000000Lu)
#define Infrared_ADC_INJ_CHAN_EN                (0x80000000Lu)

/* defines for CHAN_WORK register */
#define Infrared_ADC_SAR_WRK_MAX_12BIT          (0x00001000Lu)
#define Infrared_ADC_SAR_WRK_MAX_10BIT          (0x00000400Lu)
#define Infrared_ADC_SAR_WRK_MAX_8BIT           (0x00000100Lu)

/* defines for CHAN_RESULT register */
#define Infrared_ADC_RESULT_MASK                (0x0000FFFFLu)
#define Infrared_ADC_SATURATE_INTR_MIR          (0x20000000Lu)
#define Infrared_ADC_RANGE_INTR_MIR             (0x40000000Lu)
#define Infrared_ADC_CHAN_RESULT_VALID_MIR      (0x80000000Lu)

/* defines for INTR_MASK register */
#define Infrared_ADC_EOS_MASK                   (0x00000001Lu)
#define Infrared_ADC_OVERFLOW_MASK              (0x00000002Lu)
#define Infrared_ADC_FW_COLLISION_MASK          (0x00000004Lu)
#define Infrared_ADC_DSI_COLLISION_MASK         (0x00000008Lu)
#define Infrared_ADC_INJ_EOC_MASK               (0x00000010Lu)
#define Infrared_ADC_INJ_SATURATE_MASK          (0x00000020Lu)
#define Infrared_ADC_INJ_RANGE_MASK             (0x00000040Lu)
#define Infrared_ADC_INJ_COLLISION_MASK         (0x00000080Lu)

/* defines for INJ_RESULT register */
#define Infrared_ADC_INJ_COLLISION_INTR_MIR     (0x10000000Lu)
#define Infrared_ADC_INJ_SATURATE_INTR_MIR      (0x20000000Lu)
#define Infrared_ADC_INJ_RANGE_INTR_MIR         (0x40000000Lu)
#define Infrared_ADC_INJ_EOC_INTR_MIR           (0x80000000Lu)

/* defines for MUX_SWITCH0 register */
#define Infrared_ADC_MUX_FW_VSSA_VMINUS         (0x00010000Lu)

/* defines for PUMP_CTRL register */
#define Infrared_ADC_PUMP_CTRL_ENABLED          (0x80000000Lu)

/* additional defines for channelsConfig parameter */
#define Infrared_ADC_IS_SATURATE_EN_MASK        (0x00000001Lu)
#define Infrared_ADC_IS_RANGE_CTRL_EN_MASK      (0x00000002Lu)

/* defines for WOUNDING register */
#define Infrared_ADC_WOUNDING_12BIT             (0x00000000Lu)
#define Infrared_ADC_WOUNDING_10BIT             (0x00000001Lu)
#define Infrared_ADC_WOUNDING_8BIT              (0x00000002Lu)

/* Trim value based on characterization */
#define Infrared_ADC_TRIM_COEF                  (2u)

#if(Infrared_ADC_MAX_RESOLUTION == Infrared_ADC_RESOLUTION_10)
    #define Infrared_ADC_ALT_WOUNDING           Infrared_ADC_WOUNDING_10BIT
#else
    #define Infrared_ADC_ALT_WOUNDING           Infrared_ADC_WOUNDING_8BIT
#endif /* Infrared_ADC_MAX_RESOLUTION == Infrared_ADC_RESOLUTION_10 */

#if(Infrared_ADC_DEFAULT_VREF_SEL == Infrared_ADC__VDDA_2)
    #define Infrared_ADC_DEFAULT_VREF_SOURCE    Infrared_ADC_VREF_VDDA_2
#elif(Infrared_ADC_DEFAULT_VREF_SEL == Infrared_ADC__VDDA)
    #define Infrared_ADC_DEFAULT_VREF_SOURCE    Infrared_ADC_VREF_VDDA
#elif(Infrared_ADC_DEFAULT_VREF_SEL == Infrared_ADC__INTERNAL1024)
    #define Infrared_ADC_DEFAULT_VREF_SOURCE    Infrared_ADC_VREF_INTERNAL1024
#elif(Infrared_ADC_DEFAULT_VREF_SEL == Infrared_ADC__INTERNAL1024BYPASSED)
    #define Infrared_ADC_DEFAULT_VREF_SOURCE    Infrared_ADC_VREF_INTERNAL1024BYPASSED
#elif(Infrared_ADC_DEFAULT_VREF_SEL == Infrared_ADC__INTERNALVREF)
    #define Infrared_ADC_DEFAULT_VREF_SOURCE    Infrared_ADC_VREF_INTERNALVREF
#elif(Infrared_ADC_DEFAULT_VREF_SEL == Infrared_ADC__INTERNALVREFBYPASSED)
    #define Infrared_ADC_DEFAULT_VREF_SOURCE    Infrared_ADC_VREF_INTERNALVREFBYPASSED
#elif(Infrared_ADC_DEFAULT_VREF_SEL == Infrared_ADC__VDDA_2BYPASSED)
    #define Infrared_ADC_DEFAULT_VREF_SOURCE    Infrared_ADC_VREF_VDDA_2BYPASSED
#else
    #define Infrared_ADC_DEFAULT_VREF_SOURCE    Infrared_ADC_VREF_EXTERNAL
#endif /* Infrared_ADC_DEFAULT_VREF_SEL == Infrared_ADC__VDDA_2 */

#if(Infrared_ADC_DEFAULT_NEG_INPUT_SEL == Infrared_ADC__VSS)
    /* Connect NEG input of SARADC to VSSA close to the SARADC for single channel mode */
    #if(Infrared_ADC_TOTAL_CHANNELS_NUM == 1u)
        #define Infrared_ADC_DEFAULT_SE_NEG_INPUT    Infrared_ADC_NEG_VSSA
    #else
        #define Infrared_ADC_DEFAULT_SE_NEG_INPUT    Infrared_ADC_NEG_VSSA_KELVIN
    #endif /* (Infrared_ADC_TOTAL_CHANNELS_NUM == 1u) */
    /* Do not connect VSSA to VMINUS when one channel in differential mode used */
    #if((Infrared_ADC_TOTAL_CHANNELS_NUM == 1u) && (Infrared_ADC_CHANNELS_MODE != 0u))
        #define Infrared_ADC_DEFAULT_MUX_SWITCH0     0u
    #else    /* miltiple channels or one single channel */
        #define Infrared_ADC_DEFAULT_MUX_SWITCH0     Infrared_ADC_MUX_FW_VSSA_VMINUS
    #endif /* (Infrared_ADC_TOTAL_CHANNELS_NUM == 1u) */
#elif(Infrared_ADC_DEFAULT_NEG_INPUT_SEL == Infrared_ADC__VREF)
    /* Do not connect VNEG to VREF when one channel in differential mode used */
    #if((Infrared_ADC_TOTAL_CHANNELS_NUM == 1u) && (Infrared_ADC_CHANNELS_MODE != 0u))
        #define Infrared_ADC_DEFAULT_SE_NEG_INPUT    0u
    #else    /* miltiple channels or one single channel */
        #define Infrared_ADC_DEFAULT_SE_NEG_INPUT    Infrared_ADC_NEG_VREF
    #endif /* (Infrared_ADC_TOTAL_CHANNELS_NUM == 1u) */
    #define Infrared_ADC_DEFAULT_MUX_SWITCH0     0u
#elif (Infrared_ADC_SINGLE_PRESENT != 0u)
    #define Infrared_ADC_DEFAULT_SE_NEG_INPUT    Infrared_ADC_NEG_OTHER
    #define Infrared_ADC_DEFAULT_MUX_SWITCH0     0u
#else
    #define Infrared_ADC_DEFAULT_SE_NEG_INPUT    0u
    #define Infrared_ADC_DEFAULT_MUX_SWITCH0     0u
#endif /* Infrared_ADC_DEFAULT_NEG_INPUT_SEL == Infrared_ADC__VREF */

/* If the SAR is configured for multiple channels, always set SAR_HW_CTRL_NEGVREF to 1 */
#if(Infrared_ADC_TOTAL_CHANNELS_NUM == 1u)
    #define Infrared_ADC_DEFAULT_HW_CTRL_NEGVREF 0u
#else
    #define Infrared_ADC_DEFAULT_HW_CTRL_NEGVREF Infrared_ADC_SAR_HW_CTRL_NEGVREF
#endif /* (Infrared_ADC_TOTAL_CHANNELS_NUM == 1u) */


#if(Infrared_ADC_DEFAULT_ALT_RESOLUTION_SEL == Infrared_ADC__RES8)
    #define Infrared_ADC_DEFAULT_ALT_RESOLUTION     (Infrared_ADC_ALT_RESOLUTION_8BIT)
    #define Infrared_ADC_DEFAULT_MAX_WRK_ALT        (Infrared_ADC_SAR_WRK_MAX_8BIT)
#else
    #define Infrared_ADC_DEFAULT_ALT_RESOLUTION     (Infrared_ADC_ALT_RESOLUTION_10BIT)
    #define Infrared_ADC_DEFAULT_MAX_WRK_ALT        (Infrared_ADC_SAR_WRK_MAX_10BIT)
#endif /* End Infrared_ADC_DEFAULT_ALT_RESOLUTION_SEL == Infrared_ADC__RES8 */

#if(Infrared_ADC_DEFAULT_JUSTIFICATION_SEL == Infrared_ADC__RIGHT)
    #define Infrared_ADC_DEFAULT_JUSTIFICATION  Infrared_ADC_DATA_ALIGN_RIGHT
#else
    #define Infrared_ADC_DEFAULT_JUSTIFICATION  Infrared_ADC_DATA_ALIGN_LEFT
#endif /* Infrared_ADC_DEFAULT_JUSTIFICATION_SEL == Infrared_ADC__RIGHT */

#if(Infrared_ADC_DEFAULT_DIFF_RESULT_FORMAT_SEL == Infrared_ADC__FSIGNED)
    #define Infrared_ADC_DEFAULT_DIFF_RESULT_FORMAT Infrared_ADC_DIFF_SIGNED_RESULT
#else
    #define Infrared_ADC_DEFAULT_DIFF_RESULT_FORMAT Infrared_ADC_DIFF_UNSIGNED_RESULT
#endif /* Infrared_ADC_DEFAULT_DIFF_RESULT_FORMAT_SEL == Infrared_ADC__FSIGNED */

#if(Infrared_ADC_DEFAULT_SE_RESULT_FORMAT_SEL == Infrared_ADC__FSIGNED)
    #define Infrared_ADC_DEFAULT_SE_RESULT_FORMAT Infrared_ADC_SE_SIGNED_RESULT
#else
    #define Infrared_ADC_DEFAULT_SE_RESULT_FORMAT Infrared_ADC_SE_UNSIGNED_RESULT
#endif /* Infrared_ADC_DEFAULT_SE_RESULT_FORMAT_SEL == Infrared_ADC__FSIGNED */

#if(Infrared_ADC_DEFAULT_SAMPLE_MODE_SEL == Infrared_ADC__FREERUNNING)
    #define Infrared_ADC_DSI_TRIGGER        0u
#else /* Firmware trigger */
    #define Infrared_ADC_DSI_TRIGGER        (Infrared_ADC_DSI_TRIGGER_EN | Infrared_ADC_DSI_SYNC_TRIGGER)
#endif /* End Infrared_ADC_DEFAULT_SAMPLE_MODE == Infrared_ADC__FREERUNNING */

#if(Infrared_ADC_INJ_CHANNEL_ENABLED)
    #define Infrared_ADC_SAR_INTR_MASK      (Infrared_ADC_EOS_MASK | Infrared_ADC_INJ_EOC_MASK)
#else
    #define Infrared_ADC_SAR_INTR_MASK      (Infrared_ADC_EOS_MASK)
#endif /* Infrared_ADC_INJ_CHANNEL_ENABLED*/

#if(Infrared_ADC_DEFAULT_AVG_MODE == Infrared_ADC__FIXEDRESOLUTION)
    #define Infrared_ADC_AVG_SHIFT_MODE     Infrared_ADC_AVG_SHIFT
#else
    #define Infrared_ADC_AVG_SHIFT_MODE     0u
#endif /* End Infrared_ADC_DEFAULT_AVG_MODE */

#define Infrared_ADC_COMPARE_MODE           (uint32)((uint32)(Infrared_ADC_DEFAULT_COMPARE_MODE) \
                                                << Infrared_ADC_CMP_OFFSET)

#if(Infrared_ADC_TOTAL_CHANNELS_NUM > 1u)
    #define Infrared_ADC_DEFAULT_SWITCH_CONF    0u
#else /* Disable SAR sequencer from enabling routing switches in single channel mode */
    #define Infrared_ADC_DEFAULT_SWITCH_CONF    Infrared_ADC_SWITCH_DISABLE
#endif /* End Infrared_ADC_TOTAL_CHANNELS_NUM > 1 */

#define Infrared_ADC_DEFAULT_POWER \
       ((Infrared_ADC_NOMINAL_CLOCK_FREQ > (Infrared_ADC_MAX_FREQUENCY / 4)) ? Infrared_ADC_NORMAL_PWR : \
       ((Infrared_ADC_NOMINAL_CLOCK_FREQ > (Infrared_ADC_MAX_FREQUENCY / 8)) ? Infrared_ADC_HALF_PWR : \
                                                                                       Infrared_ADC_QUARTER_PWR))

#define Infrared_ADC_DEFAULT_CTRL_REG_CFG       (Infrared_ADC_DEFAULT_VREF_SOURCE \
                                                   | Infrared_ADC_DEFAULT_SE_NEG_INPUT \
                                                   | Infrared_ADC_DEFAULT_HW_CTRL_NEGVREF \
                                                   | Infrared_ADC_DEFAULT_POWER \
                                                   | Infrared_ADC_DSI_SYNC_CONFIG \
                                                   | Infrared_ADC_DEFAULT_SWITCH_CONF)

#define Infrared_ADC_DEFAULT_SAMPLE_CTRL_REG_CFG (Infrared_ADC_DEFAULT_DIFF_RESULT_FORMAT \
                                                    | Infrared_ADC_DEFAULT_SE_RESULT_FORMAT \
                                                    | Infrared_ADC_DEFAULT_JUSTIFICATION \
                                                    | Infrared_ADC_DEFAULT_ALT_RESOLUTION \
                                           | (uint8)(Infrared_ADC_DEFAULT_AVG_SAMPLES_NUM \
                                                   << Infrared_ADC_AVG_CNT_OFFSET) \
                                                    | Infrared_ADC_AVG_SHIFT_MODE \
                                                    | Infrared_ADC_DSI_TRIGGER \
                                                    | Infrared_ADC_EOS_DSI_OUT_EN)

#define Infrared_ADC_DEFAULT_RANGE_THRES_REG_CFG (Infrared_ADC_DEFAULT_LOW_LIMIT \
            | (uint32)((uint32)Infrared_ADC_DEFAULT_HIGH_LIMIT << Infrared_ADC_RANGE_HIGH_OFFSET))

#define Infrared_ADC_DEFAULT_SAMPLE_TIME01_REG_CFG (Infrared_ADC_DEFAULT_ACLKS_NUM \
            | (uint32)((uint32)Infrared_ADC_DEFAULT_BCLKS_NUM << Infrared_ADC_SAMPLE_TIME13_OFFSET))

#define Infrared_ADC_DEFAULT_SAMPLE_TIME23_REG_CFG (Infrared_ADC_DEFAULT_CCLKS_NUM \
            | (uint32)((uint32)Infrared_ADC_DEFAULT_DCLKS_NUM << Infrared_ADC_SAMPLE_TIME13_OFFSET))


#endif /* End CY_ADC_SAR_SEQ_Infrared_ADC_H */


/* [] END OF FILE */
