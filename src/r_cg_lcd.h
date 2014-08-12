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
* File Name    : r_cg_lcd.h
* Version      : Applilet3 for RL78/L12 V1.00.00 [23 Mar 2012]
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file implements device driver for LCD module.
* Creation Date: 21/01/2013
***********************************************************************************************************************/

#ifndef LCD_H
#define LCD_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral enable register 0 (PER0)
*/
/* Control of LCD input clock (RTCEN) */
#define _00_LCD_CLOCK_STOP                (0x00U) /* stops supply of input clock */
#define _80_LCD_CLOCK_SUPPLY              (0x80U) /* supplies input clock */

/*
    LCD mode register 0 (LCDM0)
*/
/* LCD drive voltage generator selection (MDSET1, MDSET0) */
#define _00_LCD_VOLTAGE_MODE_EXTERNAL     (0x00U) /* external resistance division method */
#define _40_LCD_VOLTAGE_MODE_INTERNAL     (0x40U) /* internal voltage boosting method */
#define _80_LCD_VOLTAGE_MODE_CAPACITOR    (0x80U) /* capacitor split method */
#define _C0_LCD_VOLTAGE_MODE_INITIALVALUE (0xC0U)
/* LCD display waveform selection (LWAVE) */
#define _00_LCD_DISPLAY_WAVEFORM_A        (0x00U) /* A waveform */
#define _20_LCD_DISPLAY_WAVEFORM_B        (0x20U) /* B waveform */
/* LCD time slices and bias mode (LDTY2 - LDTY0, LBAS1, LBAS0) */
#define _16_LCD_DISPLAY_MODE0             (0x16U) /* 8 time slices, 1/4 bias mode */
#define _0D_LCD_DISPLAY_MODE1             (0x0DU) /* 4 time slices, 1/3 bias mode */
#define _09_LCD_DISPLAY_MODE2             (0x09U) /* 3 time slices, 1/3 bias mode */
#define _08_LCD_DISPLAY_MODE3             (0x08U) /* 3 time slices, 1/2 bias mode */
#define _04_LCD_DISPLAY_MODE4             (0x04U) /* 2 time slices, 1/2 bias mode */
#define _00_LCD_DISPLAY_STATIC            (0x00U) /* A waveform external resistance division method: static */

/*
    LCD mode register 1 (LCDM1)
*/
/* LCD display enable/disable (LCDON, SCOC) */
#define _00_LCD_DISPLAY_GROUNG            (0x00U) /* output ground level to segment/common pin */
#define _40_LCD_DISPLAY_OFF               (0x40U) /* display off (all segment outputs are deselected) */
#define _C0_LCD_DISPLAY_ON                (0xC0U) /* display on */
/* Voltage boost circuit and capacitor split circuit operation enable/disable (VLCON) */
#define _00_LCD_BOOST_CAPACITOR_DISABLE   (0x00U) /* stops voltage boost and capacitor split operation */
#define _20_LCD_BOOST_CAPACITOR_ENABLE    (0x20U) /* enables voltage boost and capacitor split operation */
/* Display data area control (BLON, LCDSEL) */
#define _00_LCD_DISPLAY_PATTERN_A         (0x00U) /* displaying an A-pattern area data */
#define _08_LCD_DISPLAY_PATTERN_B         (0x08U) /* displaying a B-pattern area data */
#define _10_LCD_DISPLAY_PATTERN_AB        (0x10U) /* blinking display alternately A-pattern and B-pattern area data */
/* Control of default value of voltage boosting pin (LCDVLM) */
#define _00_LCD_VOLTAGE_HIGH              (0x00U) /* VDD voltage is larger than 3.8V */
#define _01_LCD_VOLTAGE_LOW               (0x01U) /* VDD voltage is less than 3.8V */

/*
    LCD clock control register (LCDC0)
*/
/* LCD source clock (fLCD) selection (LCDC05, LCDC04) */
#define _00_LCD_SOURCE_CLOCK_FSUB         (0x00U) /* fSUB or fIL */
#define _10_LCD_SOURCE_CLOCK_FMAIN_64     (0x10U) /* fMAIN/2^6 */
#define _20_LCD_SOURCE_CLOCK_FMAIN_128    (0x20U) /* fMAIN/2^7 */
#define _30_LCD_SOURCE_CLOCK_FMAIN_256    (0x30U) /* fMAIN/2^8 */
/* LCD clock (LCDCL) selection (LCDC03 - LCDC00) */
#define _01_LCD_CLOCK_FLCD_4              (0x01U) /* fLCD/2^2 */
#define _02_LCD_CLOCK_FLCD_8              (0x02U) /* fLCD/2^3 */
#define _03_LCD_CLOCK_FLCD_16             (0x03U) /* fLCD/2^4 */
#define _04_LCD_CLOCK_FLCD_32             (0x04U) /* fLCD/2^5 */
#define _05_LCD_CLOCK_FLCD_64             (0x05U) /* fLCD/2^6 */
#define _06_LCD_CLOCK_FLCD_128            (0x06U) /* fLCD/2^7 */
#define _07_LCD_CLOCK_FLCD_256            (0x07U) /* fLCD/2^8 */
#define _08_LCD_CLOCK_FLCD_512            (0x08U) /* fLCD/2^9 */
#define _09_LCD_CLOCK_FLCD_1024           (0x09U) /* fLCD/2^10 */
#define _0A_LCD_CLOCK_FLCD_2048           (0x0AU) /* fLCD/2^11 */
#define _0B_LCD_CLOCK_FLCD_4096           (0x0BU) /* fLCD/2^12 */

/*
    LCD memory liquid crystal control register (MLCD)
*/
/* LCD display waveform selection (MLCDEN) */
#define _00_LCD_LED_WAVEFORM_UNUSED       (0x00U) /* memory liquid crystal waveform unused */
#define _80_LCD_LED_WAVEFORM_USED         (0x80U) /* memory liquid crystal waveform used */
/* SEG/COMEXP combination terminal output selection (COMEXP) */
#define _00_LCD_SEGMENT_OUTPUT            (0x00U) /* segment waveform output */
#define _40_LCD_COMEXP_OUTPUT             (0x40U) /* COMEXP waveform output */
/* Option clock (OPTCKE) */
#define _00_LCD_OPTION_CLOCK_UNUSED       (0x00U) /* option clock invalidity (with no minute circumference) */
#define _10_LCD_OPTION_CLOCK_USED         (0x10U) /* option clock validity */
/* Division ratio of LCD clock (LCDCL) selection (OPTCK2 - OPTCK0) */
#define _00_LCD_OPTION_CLOCK_2            (0x00U) /* 2 dividing */
#define _01_LCD_OPTION_CLOCK_3            (0x01U) /* 3 dividing */
#define _02_LCD_OPTION_CLOCK_4            (0x02U) /* 4 dividing */
#define _03_LCD_OPTION_CLOCK_5            (0x03U) /* 5 dividing */
#define _04_LCD_OPTION_CLOCK_6            (0x04U) /* 6 dividing */
#define _05_LCD_OPTION_CLOCK_7            (0x05U) /* 7 dividing */
#define _06_LCD_OPTION_CLOCK_8            (0x06U) /* 8 dividing */
#define _07_LCD_OPTION_CLOCK_9            (0x07U) /* 9 dividing */

/*
    LCD boost level control register (VLCD)
*/
/* Reference voltage selection (contrast adjustment) (VLCD4 - VLCD0) */
#define _02_LCD_BOOST_VOLTAGE_090V        (0x02U) /* 0.90 V (1/3 bias: 2.70 V; 1/4 bias: 3.60 V) */
#define _03_LCD_BOOST_VOLTAGE_095V        (0x03U) /* 0.95 V (1/3 bias: 2.85 V; 1/4 bias: 3.80 V) */
#define _04_LCD_BOOST_VOLTAGE_100V        (0x04U) /* 1.00 V (1/3 bias: 3.00 V; 1/4 bias: 4.00 V) */
#define _05_LCD_BOOST_VOLTAGE_105V        (0x05U) /* 1.05 V (1/3 bias: 3.15 V; 1/4 bias: 4.20 V) */
#define _06_LCD_BOOST_VOLTAGE_110V        (0x06U) /* 1.10 V (1/3 bias: 3.30 V; 1/4 bias: 4.40 V) */
#define _07_LCD_BOOST_VOLTAGE_115V        (0x07U) /* 1.15 V (1/3 bias: 3.45 V; 1/4 bias: 4.60 V) */
#define _08_LCD_BOOST_VOLTAGE_120V        (0x08U) /* 1.20 V (1/3 bias: 3.60 V; 1/4 bias: 4.80 V) */
#define _09_LCD_BOOST_VOLTAGE_125V        (0x09U) /* 1.25 V (1/3 bias: 3.75 V; 1/4 bias: 5.00 V) */
#define _0A_LCD_BOOST_VOLTAGE_130V        (0x0AU) /* 1.30 V (1/3 bias: 3.90 V; 1/4 bias: 5.20 V) */
#define _0B_LCD_BOOST_VOLTAGE_135V        (0x0BU) /* 1.35 V (1/3 bias: 4.05 V; 1/4 bias: setting prohibited) */
#define _0C_LCD_BOOST_VOLTAGE_140V        (0x0CU) /* 1.40 V (1/3 bias: 4.20 V; 1/4 bias: setting prohibited) */
#define _0D_LCD_BOOST_VOLTAGE_145V        (0x0DU) /* 1.45 V (1/3 bias: 4.35 V; 1/4 bias: setting prohibited) */
#define _0E_LCD_BOOST_VOLTAGE_150V        (0x0EU) /* 1.50 V (1/3 bias: 4.50 V; 1/4 bias: setting prohibited) */
#define _0F_LCD_BOOST_VOLTAGE_155V        (0x0FU) /* 1.55 V (1/3 bias: 4.65 V; 1/4 bias: setting prohibited) */
#define _10_LCD_BOOST_VOLTAGE_160V        (0x10U) /* 1.60 V (1/3 bias: 4.80 V; 1/4 bias: setting prohibited) */
#define _11_LCD_BOOST_VOLTAGE_165V        (0x11U) /* 1.65 V (1/3 bias: 4.95 V; 1/4 bias: setting prohibited) */
#define _12_LCD_BOOST_VOLTAGE_170V        (0x12U) /* 1.70 V (1/3 bias: 5.10 V; 1/4 bias: setting prohibited) */
#define _13_LCD_BOOST_VOLTAGE_175V        (0x13U) /* 1.75 V (1/3 bias: 5.25 V; 1/4 bias: setting prohibited) */

/* 
    LCD input switch control register (ISCLCD)
*/
/* VL3/P125 pin schmitt trigger buffer control (ISCVL3) */
#define _02_LCD_VL3_BUFFER_VALID          (0x02U) /* VL3/P125 pin buffer control valid */
#define _00_LCD_VL3_BUFFER_INVALID        (0x00U) /* VL3/P125 pin buffer control invalid */
/* CAPL/P126, CAPH/P127 pins schmitt trigger buffer control (ISCCAP) */
#define _01_LCD_CAPLH_BUFFER_VALID        (0x01U) /* CAPL/P126, CAPH/P127 pins buffer control valid */
#define _00_LCD_CAPLH_BUFFER_INVALID      (0x00U) /* CAPL/P126, CAPH/P127 pins buffer control invalid */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define LCD_VOLTAGE_WAITTIME              (2400000U) /* capacitor split wait time (100 ms) */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_LCD_Create(void);
void R_LCD_Start(void);
void R_LCD_Stop(void);
void R_LCD_Set_Voltage_On(void);
void R_LCD_Set_Voltage_Off(void);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
