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
* File Name    : r_cg_rtc.h
* Version      : Applilet3 for RL78/L12 V1.00.00 [23 Mar 2012]
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file implements device driver for RTC module.
* Creation Date: 21/01/2013
***********************************************************************************************************************/

#ifndef RTC_H
#define RTC_H

/* Includes widely used macro definitions */
#include "r_cg_macrodriver.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral enable register 0 (PER0)
*/
/* Control of real-time clock (RTC) input clock (RTCEN) */

/* stops supply of input clock */
#define _00_RTC_CLOCK_STOP            (0x00U) 

/* supplies input clock */
#define _80_RTC_CLOCK_SUPPLY          (0x80U) 

/*
    Real-time clock register 0 (RTCC0)
*/
/* Real-time clock operation control (RTCE) */

/* stops clock operation */
#define _00_RTC_COUNTER_STOP          (0x00U)

/* starts clock operation */
#define _80_RTC_COUNTER_START         (0x80U)

/* RTC1HZ pin output control (RCLOE1) */

/* disables output of RTC1HZ pin (1 Hz) */
#define _00_RTC_RTC1HZ_DISABLE        (0x00U)

/* enable output of RTC1HZ pin (1 Hz) */
#define _20_RTC_RTC1HZ_ENABLE         (0x20U)

/* Selection of 12-/24-hour system (AMPM) */

/* clear the AMPM bit */
#define _08_RTC_HOURSYSTEM_CLEAR      (0x08U)

/* AMPM bit status detect */
#define _08_RTC_RTCC0_AMPM            (0x08U)

/* 12-hour system (a.m. and p.m.. are displayed.) */
#define _00_RTC_12HOUR_SYSTEM         (0x00U)

/* 24-hour system */
#define _08_RTC_24HOUR_SYSTEM         (0x08U)


/* Interrupt (INTRTC) selection (CT2 - CT0) */

/* clear constant-period interrupt function */
#define _F8_RTC_INTRTC_CLEAR          (0xF8U)

/* does not use constant-period interrupt function */
#define _00_RTC_INTRTC_NOT_GENERATE   (0x00U)

/* once per 0.5s */
#define _01_RTC_INTRTC_CLOCK_0        (0x01U)

/* once per 1 s */
#define _02_RTC_INTRTC_CLOCK_1        (0x02U)

/* once per 1 minute */
#define _03_RTC_INTRTC_CLOCK_2        (0x03U)

/* once per 1 hour */
#define _04_RTC_INTRTC_CLOCK_3        (0x04U)

/* once per 1 day */
#define _05_RTC_INTRTC_CLOCK_4        (0x05U)

/* once per 1 month */
#define _06_RTC_INTRTC_CLOCK_5        (0x06U)

/* Real-time clock control register 1 (RTCC1) */
/* Alarm operation control (WALE) */

/* alarm match operation is invalid */
#define _00_RTC_ALARM_DISABLE         (0x00U)

/* alarm match operation is valid */
#define _80_RTC_ALARM_ENABLE          (0x80U)

/* Control of alarm interrupt function operation (WALIE) */

/* does not generate interrupt on matching of alarm */
#define _00_RTC_ALARM_INT_DISABLE     (0x00U)

/* generates interrupt on matching of alarm */
#define _40_RTC_ALARM_INT_ENABLE      (0x40U)

/* Alarm detection status flag (WAFG) */

/* alarm mismatch */
#define _00_RTC_ALARM_MISMATCH        (0x00U)

/* detection of matching of alarm */
#define _10_RTC_ALARM_MATCH           (0x10U)

/* Constant-period interrupt status flag (RIFG) */

/* constant-period interrupt is not generated */
#define _00_RTC_INTC_NOTGENERATE_FALG (0x00U)

/* generated constant-period interrupt */
#define _08_RTC_INTC_GENERATE_FLAG    (0x08U)


/* Wait status flag of real-time clock (RWST) */

/* clock is operating */
#define _00_RTC_COUNTER_OPERATING     (0x00U)

/* mode to read or write clock value */
#define _02_RTC_COUNTER_STOP          (0x02U)

/* Wait control of real-time clock (RWAIT) */

/* sets clock operation */
#define _00_RTC_COUNTER_SET           (0x00U)

/* stops SEC to YEAR counters. Mode to read or write counter value */
#define _01_RTC_COUNTER_PAUSE         (0x01U)

/* Setting of watch error correction timing (DEV) */

/* corrects watch error when the second digits are at 00, 20, or 40 */
#define _00_RTC_CORRECTION_EVERY20S   (0x00U)

/* corrects watch error when the second digits are at 00 */
#define _80_RTC_CORRECTION_EVERY60S   (0x80U)

/* Setting of watch error correction method (F6) */

/* increase */
#define _00_RTC_CORRECTION_INCREASE   (0x00U)

/* decrease */
#define _40_RTC_CORRECTION_DECREASE   (0x40U)

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _12_RTC_COUNTER_YEAR          (0x12U)
#define _11_RTC_COUNTER_MONTH         (0x11U)
#define _13_RTC_COUNTER_DAY           (0x13U)
#define _01_RTC_COUNTER_WEEK          (0x01U)
#define _00_RTC_COUNTER_HOUR          (0x00U)
#define _00_RTC_COUNTER_MIN           (0x00U)
#define _00_RTC_COUNTER_SEC           (0x00U)
#define _01_RTC_ALARM_MIN             (0x01U)
#define _00_RTC_ALARM_HOUR            (0x00U)
#define _02_RTC_ALARM_WEEK            (0x02U)
#define RTC_WAITTIME                  (320U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef struct 
{
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
    uint8_t day;
    uint8_t week;
    uint8_t month;
    uint8_t year;
    uint8_t _pad;
}rtc_counter_value_t;

typedef struct
{
    uint8_t alarmwm;
    uint8_t alarmwh;
    uint8_t alarmww;
    uint8_t _pad:5;
}rtc_alarm_value_t;

typedef enum
{ 
    HOUR12,
    HOUR24
}rtc_hour_system_t;

typedef enum 
{
    HALFSEC = 1U,
    ONESEC,
    ONEMIN,
    ONEHOUR,
    ONEDAY,
    ONEMONTH
}rtc_int_period_t;


/***********************************************************************************************************************
Global functions and variables
***********************************************************************************************************************/
void R_RTC_Create (void);
void R_RTC_Start (void);
void R_RTC_Stop (void);
MD_STATUS R_RTC_Get_Counter_Value (rtc_counter_value_t * const counter_read_val);
MD_STATUS R_RTC_Set_Counter_Value (rtc_counter_value_t counter_write_val);
void R_RTC_Set_Alarm_On (void);
void R_RTC_Set_Alarm_Off (void);
void R_RTC_Set_Alarm_Value (rtc_alarm_value_t alarm_val);
MD_STATUS R_RTC_Set_Const_Period_Interrupt_On (rtc_int_period_t period);
void R_RTC_Set_Const_Period_Interrupt_Off (void);
void r_rtc_callback_alarm (void);
void r_rtc_callback_const_period (void);
void INT_RTC (void);

/* RTC alarm interrupt flag */
extern uint8_t g_rtc_status_alarm;
/* RTC constant period interrupt flag */
extern uint8_t g_rtc_status_int;
/* Alarm status indicator */
extern uint8_t g_alarm_status;

#endif


