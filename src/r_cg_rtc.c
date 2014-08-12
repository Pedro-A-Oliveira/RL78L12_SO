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
* File Name    : r_cg_rtc.c
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
#include "r_cg_macrodriver.h"
#include "r_cg_rtc.h"
#include "r_cg_userdefine.h"


/***********************************************************************************************************************
* Function Name: R_RTC_Create
* Description  : This function initializes the real-time clock module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_RTC_Create (void)
{
    /* supply RTC clock */
    RTCEN = 1U;
    
    /* disable RTC clock operation */
    RTCE = 0U;
    
    /* disable INTRTC interrupt */
    RTCMK = 1U;
    
    /* clear INTRTC interrupt flag */
    RTCIF = 0U;
    
    /* Set INTRTC low priority */
    RTCPR1 = 1U;
    RTCPR0 = 1U;
    
    /* Disable 1Hz output signal, select 12hr mode */
    RTCC0 = _00_RTC_RTC1HZ_DISABLE | _00_RTC_12HOUR_SYSTEM | _02_RTC_INTRTC_CLOCK_1;
    
    /* Set real-time clock */
    SEC = _00_RTC_COUNTER_SEC;
    MIN = _00_RTC_COUNTER_MIN;
    HOUR = _00_RTC_COUNTER_HOUR;
    WEEK = _01_RTC_COUNTER_WEEK;
    DAY = _13_RTC_COUNTER_DAY;
    MONTH = _11_RTC_COUNTER_MONTH;
    YEAR = _12_RTC_COUNTER_YEAR;
    
    /* Set alarm function */
    /* invalidate alarm match operation */
    WALE = 0U;
    
    /* generate INTRTC on matching of alarm */
    WALIE = 1U;
    
    /* Alarm function setting */
    ALARMWM = _01_RTC_ALARM_MIN;
    ALARMWH = _00_RTC_ALARM_HOUR;
    ALARMWW = _02_RTC_ALARM_WEEK;
}
/***********************************************************************************************************************
* End of function R_RTC_Create
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_RTC_Start
* Description  : This function enables the real-time clock.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_RTC_Start (void)
{
    /* enable INTRTC interrupt */
    RTCMK = 0U;
    
    /* enable RTC clock operation */
    RTCE = 1U;
}
/***********************************************************************************************************************
* End of function R_RTC_Start
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_RTC_Stop
* Description  : This function disables the real-time clock.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_RTC_Stop (void)
{
    /* disable RTC clock operation */
    RTCE = 0U;
    
    /* disable INTRTC interrupt */
    RTCMK = 1U;
}/***********************************************************************************************************************
* End of function R_RTC_Stop
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_RTC_Get_Counter_Value
* Description  : This function reads the results of real-time clock and store them in the variables.
* Arguments    : counter_read_val -
*                    the current real-time clock value(BCD code)
* Return Value : status -
*                    MD_OK, MD_BUSY1 or MD_BUSY2
***********************************************************************************************************************/
MD_STATUS R_RTC_Get_Counter_Value (rtc_counter_value_t * const counter_read_val)
{
    MD_STATUS status = MD_OK;
    
    /* Delay counter */
    volatile uint32_t  w_count;
    
    /* Stop the RTC */
    RTCC1 |= _01_RTC_COUNTER_PAUSE;

    /* Change the waiting time according to the system */
    for (w_count = 0U; w_count < RTC_WAITTIME; w_count++)
    {
        asm("nop");
    }

    /* Check if the counter is operating */
    if (0U == RWST)
    {
        status = MD_BUSY1;
    }
    else
    {
        counter_read_val->sec = SEC;
        counter_read_val->min = MIN;
        counter_read_val->hour = HOUR;
        counter_read_val->week = WEEK;
        counter_read_val->day = DAY;
        counter_read_val->month = MONTH;
        counter_read_val->year = YEAR;

        /* Restart the counter */
        RTCC1 &= (uint8_t)~_01_RTC_COUNTER_PAUSE;

        /* Change the waiting time according to the system */
        for (w_count = 0U; w_count < RTC_WAITTIME; w_count++)
        {
            asm("nop");
        }

        /* Check if the counter is not operating */
        if (1U == RWST)
        {
            status = MD_BUSY2;
        }
    }

    return (status);
}
/***********************************************************************************************************************
* End of function R_RTC_Get_Counter_Value
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_RTC_Set_Counter_Value
* Description  : This function changes the real-time clock value.
* Arguments    : counter_write_val -
*                    the expected real-time clock value(BCD code)
* Return Value : status -
*                    MD_OK, MD_BUSY1 or MD_BUSY2
***********************************************************************************************************************/
MD_STATUS R_RTC_Set_Counter_Value (rtc_counter_value_t counter_write_val)
{
    MD_STATUS status = MD_OK;
    volatile uint32_t  w_count;
    
    /* Stop the RTC */
    RTCC1 |= _01_RTC_COUNTER_PAUSE;

    /* Change the waiting time according to the system */
    for (w_count = 0U; w_count < RTC_WAITTIME; w_count++)
    {
        asm("nop");
    }

    /* Check if the counter is operating */
    if (0u == RWST)
    {
        status = MD_BUSY1;
    }
    else
    {
        SEC = counter_write_val.sec;
        MIN = counter_write_val.min;
        HOUR = counter_write_val.hour;
        WEEK = counter_write_val.week;
        DAY = counter_write_val.day;
        MONTH = counter_write_val.month;
        YEAR = counter_write_val.year;
        RTCC1 &= (uint8_t)~_01_RTC_COUNTER_PAUSE;

        /* Change the waiting time according to the system */
        for (w_count = 0U; w_count < RTC_WAITTIME; w_count++)
        {
            asm("nop");
        }

        /* Check if the counter is not operating */
        if (1u == RWST)
        {
            status = MD_BUSY2;
        }
    }

    return (status);
}
/***********************************************************************************************************************
* End of function R_RTC_Set_Counter_Value
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_RTC_Set_Alarm_On
* Description  : This function starts the alarm operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_RTC_Set_Alarm_On (void)
{
    /* disable INTRTC interrupt */
    RTCMK = 1U;
    
    /* enable RTC alarm operation */
    RTCC1 |= _80_RTC_ALARM_ENABLE;
    
    /* Turn on alarm detection */
    RTCC1 &= (uint8_t)~_10_RTC_ALARM_MATCH;
    
    /* clear INTRTC interrupt flag */
    RTCIF = 0U;
    
    /* enable INTRTC interrupt */
    RTCMK = 0U;
}
/***********************************************************************************************************************
* End of function R_RTC_Set_Alarm_On
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_RTC_Set_Alarm_Off
* Description  : This function stops the alarm operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_RTC_Set_Alarm_Off (void)
{
    /* disable INTRTC interrupt */
    RTCMK = 1U;
    
    /* disable RTC alarm operation */
    RTCC1 &= (uint8_t)~_80_RTC_ALARM_ENABLE;
    
    /* Turn of alarm detection */
    RTCC1 &= (uint8_t)~_10_RTC_ALARM_MATCH;
    
    /* clear INTRTC interrupt flag */
    RTCIF = 0U;
}
/***********************************************************************************************************************
* End of function R_RTC_Set_Alarm_Off
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_RTC_Set_Alarm_Value
* Description  : This function sets alarm value.
* Arguments    : alarm_val -
*                    the expected alarm value(BCD code)
* Return Value : None
***********************************************************************************************************************/
void R_RTC_Set_Alarm_Value (rtc_alarm_value_t alarm_val)
{
    /* disable INTRTC interrupt */
    RTCMK = 1U;
    
    /* disable RTC alarm operation */
    RTCC1 &= (uint8_t)~_80_RTC_ALARM_ENABLE;
    RTCC1 |= _40_RTC_ALARM_INT_ENABLE;
    ALARMWM = alarm_val.alarmwm;
    ALARMWH = alarm_val.alarmwh;
    ALARMWW = alarm_val.alarmww;
    
    /* enable RTC alarm operation */
    RTCC1 |= _80_RTC_ALARM_ENABLE;
    RTCC1 &= (uint8_t)~_10_RTC_ALARM_MATCH;
    
    /* clear INTRTC interrupt flag */
    RTCIF = 0U;
    
    /* enable INTRTC interrupt */
    RTCMK = 0U;
}
/***********************************************************************************************************************
* End of function R_RTC_Set_Alarm_Value
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_RTC_Set_Const_Period_Interrupt_On
* Description  : This function enables constant-period interrupt.
* Arguments    : period -
*                    the constant period of INTRTC
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_RTC_Set_Const_Period_Interrupt_On (rtc_int_period_t period)
{
    MD_STATUS status = MD_OK;

    if ((period < HALFSEC) || (period > ONEMONTH))
    {
        /* Wrong period selected */
        status = MD_ARGERROR;
    }
    else
    {
        /* disable INTRTC */
        RTCMK = 1U;
        RTCC0 = (uint8_t)((RTCC0 & _F8_RTC_INTRTC_CLEAR) | period);
        RTCC1 &= (uint8_t)~_08_RTC_INTC_GENERATE_FLAG;
        
        /* clear INTRTC interrupt flag */
        RTCIF = 0U;
        
        /* enable INTRTC interrupt */
        RTCMK = 0U;
    }
    
    return (status);
}
/***********************************************************************************************************************
* End of function R_RTC_Set_Const_Period_Interrupt_On
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_RTC_Set_Const_Period_Interrupt_Off
* Description  : This function disables constant-period interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_RTC_Set_Const_Period_Interrupt_Off (void)
{
    RTCC0 &= _F8_RTC_INTRTC_CLEAR;
    RTCC1 &= (uint8_t)~_08_RTC_INTC_GENERATE_FLAG;
    
    /* clear INTRTC interrupt flag */
    RTCIF = 0U;
}
/***********************************************************************************************************************
* End of function R_RTC_Set_Const_Period_Interrupt_Off
***********************************************************************************************************************/

