/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2012 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_adc.h
* Version      : Applilet3 for RL78/L12 V1.00.00 [23 Mar 2012]
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file implements device driver for ADC module.
* Creation Date: 21/01/2013
***********************************************************************************************************************/

#ifndef ADC_H
#define ADC_H

/* Includes widely used macro definitions */
#include "r_cg_macrodriver.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/* stop supply of input clock */
#define _00_AD_CLOCK_STOP               (0x00U)

/* supply input clock */
#define _20_AD_CLOCK_SUPPLY             (0x20U)

/* AD converter mode register 0 (ADM0) */
#define _00_AD_ADM0_INITIALVALUE        (0x00U)

/* AD conversion operation control (ADCS) */
/* enable AD conversion operation control */
#define _80_AD_CONVERSION_ENABLE        (0x80U)

/* disable AD conversion operation control */
#define _00_AD_CONVERSION_DISABLE       (0x00U)

/* AD conversion clock selection (FR2 - FR0) */
/* fCLK/64 */
#define _00_AD_CONVERSION_CLOCK_64      (0x00U)
/* fCLK/32 */
#define _08_AD_CONVERSION_CLOCK_32      (0x08U)
/* fCLK/16 */
#define _10_AD_CONVERSION_CLOCK_16      (0x10U)
/* fCLK/8 */
#define _18_AD_CONVERSION_CLOCK_8       (0x18U)
/* fCLK/6 */
#define _20_AD_CONVERSION_CLOCK_6       (0x20U)
/* fCLK/5 */
#define _28_AD_CONVERSION_CLOCK_5       (0x28U)
/* fCLK/4 */
#define _30_AD_CONVERSION_CLOCK_4       (0x30U)
/* fCLK/2 */
#define _38_AD_CONVERSION_CLOCK_2       (0x38U)

/* Specification AD conversion time mode (LV1, LV0) */
/* normal 1 mode */
#define _00_AD_TIME_MODE_NORMAL_1       (0x00U)
/* normal 2 mode */
#define _02_AD_TIME_MODE_NORMAL_2       (0x02U)
/* low-voltage 1 mode */
#define _04_AD_TIME_MODE_LOWVOLTAGE_1   (0x04U)
/* low-voltage 2 mode */
#define _06_AD_TIME_MODE_LOWVOLTAGE_2   (0x06U)

/* AD comparator operation control (ADCE) */
/* enable comparator operation control */
#define _01_AD_COMPARATOR_ENABLE        (0x01U)
/* disable comparator operation control */
#define _00_AD_COMPARATOR_DISABLE       (0x00U)

/* Analog input channel specification register (ADS) */
/* Specification of analog input channel (ADISS, ADS4 - ADS0) */
/* Select mode */
/* ANI0 */
#define _00_AD_INPUT_CHANNEL_0          (0x00U)
/* ANI1 */
#define _01_AD_INPUT_CHANNEL_1          (0x01U)
/* ANI16 */
#define _10_AD_INPUT_CHANNEL_16         (0x10U)
/* ANI17 */
#define _11_AD_INPUT_CHANNEL_17         (0x11U)
/* ANI18 */
#define _12_AD_INPUT_CHANNEL_18         (0x12U)
/* ANI19 */
#define _13_AD_INPUT_CHANNEL_19         (0x13U)
/* ANI20 */
#define _14_AD_INPUT_CHANNEL_20         (0x14U)
/* ANI21 */
#define _15_AD_INPUT_CHANNEL_21         (0x15U)
/* ANI22 */
#define _16_AD_INPUT_CHANNEL_22         (0x16U)
/* ANI23 */
#define _17_AD_INPUT_CHANNEL_23         (0x17U)
/* temperature sensor 0 output is used to be the input channel */
#define _80_AD_INPUT_TEMPERSENSOR_0     (0x80U)
/* internal reference voltage output is used to be the input channel */
#define _81_AD_INPUT_INTERREFVOLT       (0x81U)

/*
    AD converter mode register 1 (ADM1)
*/
/* AD trigger mode selection (ADTMD1, ADTMD0) */
/* software trigger mode */
#define _00_AD_TRIGGER_SOFTWARE         (0x00U)
/* hardware trigger mode (no wait) */
#define _80_AD_TRIGGER_HARDWARE_NOWAIT  (0x80U)
/* hardware trigger mode (wait) */
#define _C0_AD_TRIGGER_HARDWARE_WAIT    (0xC0U)
/* AD conversion mode selection (ADSCM) */
/* continuous conversion mode */
#define _00_AD_CONVMODE_CONSELECT       (0x00U)
/* one-shot conversion mode */
#define _20_AD_CONVMODE_ONESELECT       (0x20U)

/* Trigger signal selection (ADTRS1, ADTRS0) */
/* INTTM01 */
#define _00_AD_TRIGGER_INTTM01          (0x00U)
/* INTRTC */
#define _02_AD_TRIGGER_INTRTC           (0x02U)
/* INTIT */
#define _03_AD_TRIGGER_INTIT            (0x03U)

/*
    AD converter mode register 2 (ADM2)
*/
/* AD VREF(+) selection (ADREFP1, ADREFP0) */
/* use VDD as VREF(+) */
#define _00_AD_POSITIVE_VDD             (0x00U)
/* use AVREFP as VREF(+) */
#define _40_AD_POSITIVE_AVREFP          (0x40U)
/* use internal voltage as VREF(+) */
#define _80_AD_POSITIVE_INTERVOLT       (0x80U)

/* AD VREF(-) selection (ADREFM) */
/* use VSS as VREF(-) */
#define _00_AD_NEGATIVE_VSS             (0x00U)
/* use AVREFM as VREF(-) */
#define _20_AD_NEGATIVE_AVREFM          (0x20U)

/* AD conversion result upper/lower bound value selection (ADRCK) */
/* generates INTAD when ADLL <= ADCRH <= ADUL */
#define _00_AD_AREA_MODE_1              (0x00U)
/* generates INTAD when ADUL < ADCRH or ADLL > ADCRH */
#define _08_AD_AREA_MODE_2_3            (0x08U)

/* AD wake-up function selection (AWC) */
/* stop wake-up function */
#define _00_AD_WAKEUP_OFF               (0x00U)
/* use wake-up function */
#define _04_AD_WAKEUP_ON                (0x04U)

/* AD resolution selection (ADTYP) */
/* 10 bits */
#define _00_AD_RESOLUTION_10BIT         (0x00U)
/* 8 bits */
#define _01_AD_RESOLUTION_8BIT          (0x01U)

/*
    AD test function register (ADTES)
*/
/* AD test mode signal (ADTES2 - ADTES0) */
/* normal mode */
#define _00_AD_NORMAL_INPUT             (0x00U)
/* use AVREFM as test signal */
#define _02_AD_TEST_AVREFM              (0x02U)
/* use AVREFP as test signal */
#define _03_AD_TEST_AVREFP              (0x03U)

/*
    AD port configuration register (ADPC)
*/
/* Analog input/digital input switching (ADPC3 - ADPC0) */
/* ANI0 - ANI1 */
#define _00_AD_ADPC_2ANALOG             (0x00U)
/* ANI0 */
#define _02_AD_ADPC_1ANALOG             (0x02U)
/* ANI0 - ANI1 (all digital) */
#define _01_AD_ADPC_0ANALOG             (0x01U)

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Upper bound (ADUL) value */
#define _FF_AD_ADUL_VALUE               (0xFFU)
/* Lower bound (ADLL) value */
#define _00_AD_ADLL_VALUE               (0x00U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef enum
{
    ADCHANNEL0,
    ADCHANNEL1,
    ADCHANNEL16 = 16U,
    ADCHANNEL17,
    ADCHANNEL18,
    ADCHANNEL19,
    ADCHANNEL20,
    ADCHANNEL21,
    ADCHANNEL22,
    ADCHANNEL23,
    ADTEMPERSENSOR0 = 128U,
    ADINTERREFVOLT
} ad_channel_t;

typedef enum
{
    ADNORMALINPUT,
    ADAVREFM = 2U,
    ADAVREFP
} test_channel_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_ADC_Create(void);
void R_ADC_Start(void);
void R_ADC_Stop(void);
void R_ADC_Set_Operation_On(void);
void R_ADC_Set_Operation_Off(void);
void R_ADC_Get_Result(uint16_t * const buffer);

/* Flag for ADC conversion result complete */
extern uint8_t g_adc_done;

/* Variable for ADC conversion result */
extern uint16_t  g_adc_value;

#endif
