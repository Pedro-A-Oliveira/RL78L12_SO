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
* File Name    : r_cg_intc.c
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
#include "r_cg_userdefine.h"


/***********************************************************************************************************************
* Function Name: R_INTC_Create
* Description  : This function initializes INTP module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTC_Create (void)
{
    /* Set INTP0 level 1 priority */
    PPR10 = 0U;
    PPR00 = 1U;
    
    /* Set INTP3 level 1 priority */
    PPR13 = 0U;
    PPR03 = 1U;
    
    /* Set INTP4 level 1 priority */
    PPR14 = 0U;
    PPR04 = 1U;
    
    EGN0 = _01_INTP0_EDGE_FALLING_SEL | _08_INTP3_EDGE_FALLING_SEL | _10_INTP4_EDGE_FALLING_SEL;
    
    /* Set INTP3 pin */
    PFSEG2 &= 0xFBU;
    PM3 |= 0x02U;
    
    /* Set INTP4 pin */
    PFSEG2 &= 0xFDU;
    PM3 |= 0x04U;
}
/***********************************************************************************************************************
* End of function R_INTC_Create
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_INTC0_Start
* Description  : This function clears INTP0 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTC0_Start (void)
{
    /* clear INTP0 interrupt flag */
    PIF0 = 0U;
    
    /* enable INTP4 interrupt */
    PMK0 = 0U;
}
/***********************************************************************************************************************
* End of function R_INTC0_Start
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_INTC0_Stop
* Description  : This function disables INTP0 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTC0_Stop (void)
{
    /* disable INTP0 interrupt */
    PMK0 = 1U;
    
    /* clear INTP0 interrupt flag */
    PIF0 = 0U;
}
/***********************************************************************************************************************
* End of function R_INTC0_Stop
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_INTC3_Start
* Description  : This function clears INTP3 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTC3_Start (void)
{
    /* clear INTP3 interrupt flag */
    PIF3 = 0U;
    
    /* enable INTP3 interrupt */
    PMK3 = 0U;
}
/***********************************************************************************************************************
* End of function R_INTC3_Start
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_INTC3_Stop
* Description  : This function disables INTP3 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTC3_Stop (void)
{
    /* disable INTP3 interrupt */
    PMK3 = 1U;
    
    /* clear INTP3 interrupt flag */
    PIF3 = 0U;
}
/***********************************************************************************************************************
* End of function R_INTC3_Stop
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_INTC4_Start
* Description  : This function clears INTP4 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTC4_Start (void)
{
    /* clear INTP4 interrupt flag */
    PIF4 = 0U;
    
    /* enable INTP4 interrupt */
    PMK4 = 0U;
}
/***********************************************************************************************************************
* End of function R_INTC4_Start
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_INTC4_Stop
* Description  : This function disables INTP4 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTC4_Stop (void)
{
    /* disable INTP4 interrupt */
    PMK4 = 1U;
    
    /* clear INTP4 interrupt flag */
    PIF4 = 0U;
}
/***********************************************************************************************************************
* End of function R_INTC4_Stop
***********************************************************************************************************************/

