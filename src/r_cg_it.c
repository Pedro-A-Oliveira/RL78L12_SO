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
* File Name    : r_cg_it.c
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
#include "r_cg_userdefine.h"


/***********************************************************************************************************************
* Function Name: R_IT_Create
* Description  : This function initializes the IT module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT_Create(void)
{
	/* Call the function to initialize the IT module */
	R_IT_Create_UserInit();
}
/***********************************************************************************************************************
* End of function R_IT_Create
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_IT_Start
* Description  : This function starts IT module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT_Start(void)
{
    /* enable IT operation */
    /*  usar LOCO (15KHz)  */
    OSMC |= 0b00010000;
    /*  usar oscilador XT1 (32.768KHz)  */
    //OSMC &= 0b11101111;
    ITMC = 14u;
    ITMC |= _8000_IT_OPERATION_ENABLE;

    /* clear INTIT interrupt flag */
    ITIF = 0U;

    /* enable INTIT interrupt */
    ITMK = 0U;
}
/***********************************************************************************************************************
* End of function R_IT_Start
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_IT_Stop
* Description  : This function stops IT module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT_Stop(void)
{
	/* disable INTIT interrupt */
	ITMK = 1u;

	/* clear INTIT interrupt flag */
	ITIF = 0u;

	/* disable IT operation    */
    ITMC &= (uint16_t)~_8000_IT_OPERATION_ENABLE;
}
/***********************************************************************************************************************
* End of function R_IT_Stop
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_IT_Set_Power_Off
* Description  : This function stops the clock supplied for IT.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT_Set_Power_Off (void)
{
    /* stop IT clock */
    RTCEN = 0U;
}
/***********************************************************************************************************************
* End of function R_IT_Set_Power_Off
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: IT_Change_Timer_Condition
* Description  : This function changes IT register value.
* Arguments    : reg_value -  value for data register
* Return Value : None
***********************************************************************************************************************/
void IT_Change_Timer_Condition(uint16_t reg_value)
{
	/* Ensure the desired value is only 12-bits */
	reg_value &= 0x0FFFU;

	/* Stop the count */
	ITMC &= 0x8000U;

	/* Change the count value */
	ITMC |= reg_value;
}
/***********************************************************************************************************************
* End of function IT_Change_Timer_Condition
***********************************************************************************************************************/


