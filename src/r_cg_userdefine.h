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
* File Name    : r_cg_userdefine.h
* Version      : Applilet3 for RL78/L12 V1.00.00 [23 Mar 2012]
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file includes user definition.
* Creation Date: 21/01/2013
***********************************************************************************************************************/

#ifndef _USER_DEF_H
#define _USER_DEF_H

#include "iodefine.h"

/***********************************************************************************************************************
Macro Definitions
***********************************************************************************************************************/

/* Commonly used macros */
#define	MD_ON		            1U
#define	MD_OFF		            0U

#define	MD_TRUE		            1U
#define	MD_FALSE	            0U

#define MD_SET		            1U
#define MD_CLEAR	            0U

/* Logical values  */
#define TRUE                    (1u)
#define FALSE                   (0u)

/* LEDs */
#define LED0                    P13_bit.no0
#define LED1                    P2_bit.no1
#define LED2                    P12_bit.no5

/* LEDs Port Direction */
#define LED1_DIR                PM2_bit.no1
#define LED2_DIR                PM12_bit.no5

#define LED_ON                  (0u)
#define LED_OFF                 (1u)

/* Switches */
#define SW1                     P13_bit.no7
#define SW2                     P3_bit.no1
#define SW3                     P3_bit.no2

#endif
