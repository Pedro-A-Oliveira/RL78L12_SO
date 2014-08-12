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
* File Name    : r_systeminit.c
* Version      : Applilet3 for RL78/L12 V1.00.00 [23 Mar 2012]
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file implements system initializing function.
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
#include "r_cg_cgc.h"
#include "r_cg_intc.h"
#include "r_cg_adc.h"
#include "r_cg_it.h"
#include "r_cg_userdefine.h"


/***********************************************************************************************************************
* Function Name: R_Systeminit
* Description  : This function initializes all peripherals used in this demo.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Systeminit (void)
{
    /* Configure port pin assignments */
    PIOR = 0x00U;
    
    /* Configure the LCD */
    R_LCD_Create();
    
    /* Configure system clocks */
    R_CGC_Create();
    
    /* Configure ADC */
    R_ADC_Create();
    
    /* Configure timer unit 0 */
    R_TAU0_Create();
    
	/* Configure the interval timer */
    R_IT_Create();
    
    /* Configure RTC */
    R_RTC_Create();
    
    /* Configure external interrupts */
    R_INTC_Create();
    
    /* Disable CRC operations */
    CRC0CTL = 0x00U;
    
    /* Disable RAM and SFR protections */
    IAWCTL = 0x00U;
    
    /* Disable RAM parity */
    RPECTL = 0x80;
}
/***********************************************************************************************************************
* End of function R_Systeminit
***********************************************************************************************************************/

