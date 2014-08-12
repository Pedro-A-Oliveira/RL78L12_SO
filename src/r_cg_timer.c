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
* File Name    : r_cg_timer.c
* Version      : Applilet3 for RL78/L12 V1.00.00 [23 Mar 2012]
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file implements device driver for TAU module.
* Creation Date: 21/01/2013
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
/* Defines the I/O register structures */
#include "iodefine.h"

/* Defines the extended I/O register structures */
#include "iodefine_ext.h"

/* Header files inclusion */
#include "r_cg_macrodriver.h"
#include "r_cg_timer.h"
#include "r_cg_userdefine.h"


/***********************************************************************************************************************
* Function Name: R_TAU0_Create
* Description  : This function initializes the TAU0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Create (void)
{
    /* supplies input clock */
    TAU0EN = 1U;
    
    /* Configure the timer channel clock sources */
    TPS0 = _0007_TAU_CKM0_FCLK_7 | _00F0_TAU_CKM1_FCLK_15 | _0000_TAU_CKM2_FCLK_1 | _3000_TAU_CKM3_FCLK_14;
    
    /* Stop all channels */
    TT0 = _0001_TAU_CH0_STOP_TRG_ON | _0002_TAU_CH1_STOP_TRG_ON | _0004_TAU_CH2_STOP_TRG_ON |
          _0008_TAU_CH3_STOP_TRG_ON | _0010_TAU_CH4_STOP_TRG_ON | _0020_TAU_CH5_STOP_TRG_ON |
          _0040_TAU_CH6_STOP_TRG_ON | _0080_TAU_CH7_STOP_TRG_ON | _0200_TAU_CH1_H8_STOP_TRG_ON |
          _0800_TAU_CH3_H8_STOP_TRG_ON;
          
    /* Set INTTM00 low priority */
    TMPR100 = 1U;
    TMPR000 = 1U;
    
    /* Set INTTM01H low priority */
    TMPR101H = 1U;
    TMPR001H = 1U;
    
    /* Set INTTM02 low priority */
    TMPR102 = 1U;
    TMPR002 = 1U;
    
    /* Channel 0 used as interval timer */
    TMR00 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0000_TAU_TRIGGER_SOFTWARE | _0000_TAU_MODE_INTERVAL_TIMER | _0000_TAU_START_INT_UNUSED;
    TDR00 = _B71A_TAU_TDR00_VALUE;
    TO0 &= ~_0001_TAU_CH0_OUTPUT_VALUE_1;
    TOE0 &= ~_0001_TAU_CH0_OUTPUT_ENABLE;
    
    /* Channel 1 used as interval timer */
    TMR01 = _C000_TAU_CLOCK_SELECT_CKM3 | _0000_TAU_CLOCK_MODE_CKS | _0800_TAU_8BITS_MODE | _0000_TAU_TRIGGER_SOFTWARE |
            _0000_TAU_MODE_INTERVAL_TIMER | _0001_TAU_START_INT_USED;
    TDR01H = _48_TAU_TDR01H_VALUE;
    TOM0 &= ~_0002_TAU_CH1_OUTPUT_COMBIN;
    TOL0 &= ~_0002_TAU_CH1_OUTPUT_LEVEL_L;
    TO0 &= ~_0002_TAU_CH1_OUTPUT_VALUE_1;
    TOE0 &= ~_0002_TAU_CH1_OUTPUT_ENABLE;
    
    /* Channel 2 used as interval timer */
    TMR02 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0000_TAU_TRIGGER_SOFTWARE | _0000_TAU_MODE_INTERVAL_TIMER | _0000_TAU_START_INT_UNUSED;
    TDR02 = _DBB9_TAU_TDR02_VALUE;
    TOM0 &= ~_0004_TAU_CH2_OUTPUT_COMBIN;
    TOL0 &= ~_0004_TAU_CH2_OUTPUT_LEVEL_L;
    TO0 &= ~_0004_TAU_CH2_OUTPUT_VALUE_1;
    TOE0 &= ~_0004_TAU_CH2_OUTPUT_ENABLE;
}
/***********************************************************************************************************************
* End of function R_TAU0_Create
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel0_Start
* Description  : This function starts TAU0 channel 0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel0_Start (void)
{
    /* clear INTTM00 interrupt flag */
    TMIF00 = 0U;
    
    /* enable INTTM00 interrupt */
    TMMK00 = 0U;
    
    /* Start channel 0 operations */
    TS0 |= _0001_TAU_CH0_START_TRG_ON;
}
/***********************************************************************************************************************
* End of function R_TAU0_Channel0_Start
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel0_Stop
* Description  : This function stops TAU0 channel 0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel0_Stop (void)
{
    /* Stop channel 0 operations */
    TT0 |= _0001_TAU_CH0_STOP_TRG_ON;
    
    /* Mask channel 0 interrupt */
    /* disable INTTM00 interrupt */
    TMMK00 = 1U;
    
    /* clear INTTM00 interrupt flag */
    TMIF00 = 0U;
}
/***********************************************************************************************************************
* End of function R_TAU0_Channel0_Stop
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel1_Higher8bits_Start
* Description  : This function starts TAU0 channel 1 higher 8 bits counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel1_Higher8bits_Start (void)
{
    /* clear INTTM01H interrupt flag */
    TMIF01H = 0U;
    
    /* enable INTTM01H interrupt */
    TMMK01H = 0U;
    
    /* Start channel 1 operations */
    TS0 |= _0200_TAU_CH1_H8_START_TRG_ON;
}
/***********************************************************************************************************************
* End of function R_TAU0_Channel1_Higher8bits_Start
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel1_Higher8bits_Stop
* Description  : This function stops TAU0 channel 1 higher 8 bits counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel1_Higher8bits_Stop (void)
{
    /* Stop channel 1 operations */
    TT0 |= _0200_TAU_CH1_H8_STOP_TRG_ON;
    
    /* Mask channel 1 interrupt */
    /* disable INTTM01H interrupt */
    TMMK01H = 1U;
    
    /* clear INTTM01H interrupt flag */
    TMIF01H = 0U;
}
/***********************************************************************************************************************
* End of function R_TAU0_Channel1_Higher8bits_Stop
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel2_Start
* Description  : This function starts TAU0 channel 2 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel2_Start (void)
{
    /* clear INTTM02 interrupt flag */
    TMIF02 = 0U;
    
    /* enable INTTM02 interrupt */
    TMMK02 = 0U;
    
    /* Start channel 2 operations */
    TS0 |= _0004_TAU_CH2_START_TRG_ON;
}
/***********************************************************************************************************************
* End of function R_TAU0_Channel2_Start
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel2_Stop
* Description  : This function stops TAU0 channel 2 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel2_Stop (void)
{
    /* Stop channel 2 operations */
    TT0 |= _0004_TAU_CH2_STOP_TRG_ON;
    
    /* Mask channel 2 interrupt */
    TMMK02 = 1U;
    
    /* clear INTTM02 interrupt flag */
    TMIF02 = 0U;
}
/***********************************************************************************************************************
* End of function R_TAU0_Channel2_Stop
***********************************************************************************************************************/

