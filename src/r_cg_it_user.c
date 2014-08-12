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
* File Name    : r_cg_it_user.c
* Version      : Applilet3 for RL78/L12 V1.00.00 [23 Mar 2012]
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file implements device driver for IT module.
* Creation Date: 21/01/2013
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
/* Header files inclusion */
#include "r_cg_macrodriver.h"
#include "r_cg_it.h"
#include "interrupt_handlers.h"
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
* Function Name: R_IT_Create_UserInit
* Description  : This function adds user code after initializing IT module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT_Create_UserInit (void)
{
	/* supply IT clock */
	RTCEN = 1U;

	/* disable IT operation */
	ITMC = _0000_IT_OPERATION_DISABLE;

	/* disable INTIT interrupt */
	ITMK = 1U;

	/* clear INTIT interrupt flag */
	ITIF = 0U;

	/* Set INTIT low priority */
	ITPR1 = 1U;
	ITPR0 = 1U;

	/* Set the compare value */
	ITMC = _0FFF_ITMCMP_VALUE;
}
/***********************************************************************************************************************
* End of function R_IT_Create_UserInit
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: INT_IT
* Description  : This function is INTIT interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void INT_IT (void)
{
    /* Toggle LED output */
	KernelClock();

	/* Clear the IT interrupt flag */
	ITIF = 0u;
}
/***********************************************************************************************************************
* End of function INT_IT
***********************************************************************************************************************/

