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
* File Name    : r_cg_adc.c
* Version      : Applilet3 for RL78/L12 V1.00.00 [23 Mar 2012]
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file implements device driver for ADC module.
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
#include "r_cg_adc.h"
#include "r_cg_userdefine.h"


/***********************************************************************************************************************
* Function Name: R_ADC_Create
* Description  : This function initializes the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Create (void)
{
    /* Supply AD clock */
    ADCEN = 1U;
    
    /* Disable AD conversion and clear ADM0 register */
    ADM0 = 0x00;
    
    /* disable INTAD interrupt */
    ADMK = 1U;
    
    /* Clear INTAD interrupt flag */
    ADIF = 0U;
    
    /* Set INTAD low priority */
    ADPR1 = 1U;
    ADPR0 = 1U;
    
    /* Set ANI0 pin as analog input */
    PM2 |= 0x01U;
    
    /* ADC conversion time set to 30us */
    ADM0 = _08_AD_CONVERSION_CLOCK_32 | _00_AD_TIME_MODE_NORMAL_1;
    
    /* Select software triggering and one-shot conversion mode */
    //ERRADO, tava 0x00;
    ADM1 = 0x20;
    
    /* Set conversion resolution to 10-bit */
    ADM2 = 0x00;
    
    /* Upper limit set to 0xFF */
    ADUL = _FF_AD_ADUL_VALUE;
    
    /* Lower limit set to 0x00 */
    ADLL = _00_AD_ADLL_VALUE;
    
    /* Select channel 0 as the input channel to sample */
    ADS = _00_AD_INPUT_CHANNEL_0;
}
/***********************************************************************************************************************
* End of function R_ADC_Create
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_ADC_Start
* Description  : This function starts the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Start (void)
{
	/* clear INTAD interrupt flag */
    ADIF = 0U;

    /* enable INTAD interrupt */
    ADMK = 0U;

    /* enable AD conversion */
    ADCS = 1U;
}
/***********************************************************************************************************************
* End of function R_ADC_Start
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_ADC_Stop
* Description  : This function stops the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Stop (void)
{
	/* disable AD conversion */
	ADCS = 0U;

	/* disable INTAD interrupt */
	ADMK = 1U;

	/* clear INTAD interrupt flag */
	ADIF = 0U;
}
/***********************************************************************************************************************
* End of function R_ADC_Stop
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_ADC_Set_Operation_On
* Description  : This function enables comparator operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Set_Operation_On(void)
{
	/* enable AD comparator */
	ADCE = 1U;
}
/***********************************************************************************************************************
* End of function R_ADC_Set_Operation_On
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_ADC_Set_Operation_Off
* Description  : This function stops comparator operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Set_Operation_Off(void)
{
	/* disable AD comparator */
	ADCE = 0U;
}
/***********************************************************************************************************************
* End of function R_ADC_Set_Operation_Off
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_ADC_Get_Result
* Description  : This function returns the conversion result in the buffer.
* Arguments    : buffer
*                    the address where to write the conversion result
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Get_Result(uint16_t * const buffer)
{
	while(ADCS != 0U);
    *buffer = (uint16_t)(ADCR >> 6U);
}
/***********************************************************************************************************************
* End of function R_ADC_Get_Result
***********************************************************************************************************************/


