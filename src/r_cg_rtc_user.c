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
* File Name    : r_cg_rtc_user.c
* Version      : Applilet3 for RL78/L12 V1.00.00 [23 Mar 2012]
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file implements device driver for RTC module.
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
#include "interrupt_handlers.h"
#include "r_cg_macrodriver.h"
#include "r_cg_rtc.h"
#include "r_cg_intc.h"
#include "r_cg_adc.h"
#include "r_cg_cgc.h"
#include "r_cg_userdefine.h"
#include "lcd_panel.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Create a new instance of data structure RTCCounterValue */
rtc_counter_value_t st_rtc_data;

/* RTC alarm interrupt flag */
uint8_t g_rtc_status_alarm      = FALSE;

/* RTC constant period interrupt flag */
uint8_t g_rtc_status_int        = FALSE;

/* Alarm status indicator */
uint8_t g_alarm_status          = FALSE;

/* Declare a buffer to hold the time for displaying on the LCD panel */
int8_t  g_lcd_buffer[10] = "00:00:00";


/***********************************************************************************************************************
* Function Name: INT_RTC
* Description  : This function is INTRTC interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void INT_RTC (void)
{
    /* Check the alarm match flag */
    if (1u == WAFG)
    {
        /* clear WAFG */
        RTCC1 &= (uint8_t)~_10_RTC_ALARM_MATCH;
        r_rtc_callback_alarm();
    }
    
    /* Check the constant period flag */
    if (1u == RIFG)
    {
        /* clear RIFG */
        RTCC1 &= (uint8_t)~_08_RTC_INTC_GENERATE_FLAG;
        
        /* Call the constant period call-back function */
        r_rtc_callback_const_period();
    }
}
/***********************************************************************************************************************
* End of function INT_RTC
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: r_rtc_callback_const_period
* Description  : This function is real-time clock constant-period interrupt service handler.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_rtc_callback_const_period (void)
{
    /* Variable used to alternate the alarm symbol on/off */
    static uint8_t symbol_alt = 0xFF;
    
    /* Read the RTC time */
    R_RTC_Get_Counter_Value(&st_rtc_data);
        
    /* Check if the constant period flag was set */
    if (1u != (ADM2 & 4u))
    {
        /* Toggle LED1 */
        LED1 = (uint8_t)(~LED1);
    }

    /* Read the day of the week value */
    g_lcd_buffer[8] = (int8_t)(st_rtc_data.week & 0x0F);

    /* Read the seconds value */
	g_lcd_buffer[7] = (int8_t)((st_rtc_data.sec & 0x0F) + 0x30);
	g_lcd_buffer[6] = (int8_t)((st_rtc_data.sec >> 4) + 0x30);

    /* Read the minutes value */
    g_lcd_buffer[4] = (int8_t)((st_rtc_data.min & 0x0F) + 0x30);
    g_lcd_buffer[3] = (int8_t)((st_rtc_data.min >> 4) + 0x30);

    /* Read the hours value */
    g_lcd_buffer[1] = (int8_t)((st_rtc_data.hour & 0x0F) + 0x30);
    g_lcd_buffer[0] = (int8_t)(((st_rtc_data.hour >> 4) & 0x03) + 0x30);

    /* Update the time on the LCD panel.
       Casting to ensure use of correct data type.*/
    Display_Panel_String(PANEL_LCD_LINE2, g_lcd_buffer);
    Display_Panel_String(PANEL_LCD_LINE3, (g_lcd_buffer + 6u));

    /* Display the day of the week symbol */
    SECTF_Glyph_Map(g_lcd_buffer[8]);

    /* Clear the INTRTC interrupt flag */
    RTCIF = 0u;
}
/***********************************************************************************************************************
* End of function r_rtc_callback_const_period
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: r_rtc_callback_alarm
* Description  : This function is alarm interrupt service handler.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_rtc_callback_alarm (void)
{
    /* Turn on the alarm symbol */
    Symbol_Map(LCD_ALARM_ON);
    
    /* Set flag to record detection of alarm interrupt */
    g_rtc_status_alarm = TRUE;
    
    /* Disable INTRTC on matching of alarm */
    WALIE = 0u;
    
    /* Clear the INTRTC interrupt flag */
    RTCIF = 0u;
}
/***********************************************************************************************************************
* End of function r_rtc_callback_alarm
***********************************************************************************************************************/

