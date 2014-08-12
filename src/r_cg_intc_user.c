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
* File Name    : r_cg_intc_user.c
* Version      : Applilet3 for RL78/L12 V1.00.00 [23 Mar 2012]
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file implements device driver for INTC module.
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
#include "r_cg_intc.h"
#include "interrupt_handlers.h"
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Declare a switch status variable flag */
volatile uint8_t g_switch_press = 0;


/***********************************************************************************************************************
* Function Name: INT_P0
* Description  : This function is INTP0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void INT_P0 (void)
{
    /* Set bit to indicate that SW1 has been pressed */
    g_switch_press |= SWITCH_PRESS_1;

    /* Clear SW1's (INTP0) interrupt flag */
    PIF0 = 0;
}
/***********************************************************************************************************************
* End of function INT_P0
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: INT_P3
* Description  : This function is INTP3 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void INT_P3 (void)
{
    /* Set bit to indicate that SW2 has been pressed */
    g_switch_press |= SWITCH_PRESS_2;
    
    /* Clear SW2's (INTP3) interrupt flag */
    PIF3 = 0;
}
/***********************************************************************************************************************
* End of function INT_P3
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: INT_P4
* Description  : This function is INTP4 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void INT_P4 (void)
{
    /* Set bit to indicate that SW3 has been pressed */
    g_switch_press |= SWITCH_PRESS_3;
    

    /* Clear SW3's (INTP4) interrupt flag */
	PIF4 = 0;
}
/***********************************************************************************************************************
* End of function INT_P4
***********************************************************************************************************************/

