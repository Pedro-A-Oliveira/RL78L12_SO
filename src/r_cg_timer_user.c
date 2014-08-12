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
* File Name    : r_cg_timer_user.c
* Version      : Applilet3 for RL78/L12 V1.00.00 [23 Mar 2012]
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file implements device driver for TAU module.
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
#include "r_cg_timer.h"
#include "r_cg_cgc.h"
#include "r_cg_adc.h"
#include "r_cg_rtc.h"
#include "r_cg_intc.h"
#include "lcd_panel.h"
#include "r_main.h"
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* String to be scrolled across the star-burst segments.
   Leave at least one space following the last alphabetic/numeric character in the string*/
char g_scroll_data[SCROLL_LINES][SCROLL_BUFF_SIZE] =
{
    " YRPB RL78/L12 Demo ",
    " RL78 True Low Power ",
    " On Board LCD Driver "
};

/* Pointer used to specify the start address of buffer 
arrays containing data to be scrolled on the LCD panel */
char * g_scroll_data_pointer = g_scroll_data[0];

/* Holds statuses for enabling/disabling text scrolling on the LCD panel */
uint8_t g_enable_scroll = 0u;


/***********************************************************************************************************************
* Function Name: INT_TM00
* Description  : This function is INTTM00 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void INT_TM00 (void)
{
    /* Declare count variables */
    static uint8_t i = 0;
    static uint8_t j = 0;

    /* Update the LCD every second timer interrupt */
	if (1u == i++)
	{
		/* Display the text on the LCD panel.
		   Casting to ensure correct data type */
		Display_Panel_String(PANEL_LCD_LINE1, g_scroll_data_pointer);

		/* Reset the count */
		i = 0;

		/* Increment the address */
		g_scroll_data_pointer++;
	}

	/* Check if the NULL character has been encountered */
	if (0u == *g_scroll_data_pointer)
	{
		/* Copy the start address of the text to be scrolled */
		g_scroll_data_pointer = g_scroll_data[j];

		/* Reset the counter after all scroll sentences have been displayed */
		if (SCROLL_LINES == ++j)
		{
			j = 0;
		}

		/* Stop scrolling? */
		if (FINITE_SCROLL & g_enable_scroll)
		{
			/* Disable scrolling */
			g_enable_scroll &= ~ENABLE_SCROLL;
		}
	}

    /* Clear the interrupt flag */
    TMIF00 = 0x0;
}
/***********************************************************************************************************************
* End of function INT_TM00
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: INT_TM01H
* Description  : This function is INTTM01H interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void INT_TM01H (void)
{
	/* Variable used to alternate between the Cool and Heat symbols */
	static uint8_t j = 0u;
	static uint8_t k = FALSE;
	static uint8_t l = 0u;

	/* Max ADC value is 1023. Scaling ADC values less than 100 will result in 0 */
	if (99 < g_adc_value)
	{
		/* Scale the ADC value to a figure between 0 and 11 */
	    l = g_adc_value / 100;
	}
	else
	{
		/* Set the count interval to 1, when the ADC value is less than 100 */
		l = 1;
	}
	/* Alternate between the Heat and Cool symbols */
    if ((TRUE == k) && (l == ++j))
    {
    	/* Turn on the Heat symbol and turn off the Cool symbol */
    	Symbol_Map(LCD_HEAT_ON);
    	Symbol_Map(LCD_COOL_OFF);

    	k = FALSE;
    	j = 0;
    }
    else if ((FALSE == k) && (l == ++j))
	{
		/* Turn off the Heat symbol and turn on the Cool symbol */
		Symbol_Map(LCD_HEAT_OFF);
		Symbol_Map(LCD_COOL_ON);

		k = TRUE;
		j = 0;
	}
    else
    {
    	/* Reset the count when it reaches 10 */
    	if (10u == j)
    	{
    		j = 0;
    	}
    }
    
    /* Clear the interrupt flag */
    TMIF01 = 0u;
}
/***********************************************************************************************************************
* End of function INT_TM01H
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: INT_TM02
* Description  : This function is INTTM02 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void INT_TM02 (void)
{
    /* Declare a count variable used to turn on battery level bars in sequence */
    static uint8_t bat_level_indicator = 1u;
    static uint8_t count_direction     = FALSE;
    
    /* Flag used to control the LCD segment changes */
    uint8_t  segment_changer = FALSE;
    
    /* Variable used to count interrupt occurrences */
    static uint8_t segment_change_update = 0u;
    
    /* Used to point to a 2-dimensional array element containing string literals */
    static uint8_t string_counter = 0u;

    /* Set the flag for every two counts of the interrupt occurrence */
    if (0x50u == ++segment_change_update)
    {
        /* Indicates that the segment needs updating */
    	segment_changer = TRUE;
        
        /* Reset the string counter */
        if (4u == string_counter)
        {
            string_counter = 0u;
        }
    }
    
    /* Turn on the number of bars indicated by the counter then increment the counter */
	switch (bat_level_indicator)
	{
		case BATT_LEVEL_1:
		{
			/* Turn on 1 battery bars */
			SECTD_Glyph_Map(BATT_LEVEL_1, BATTERY_OUTLINE_OFF);

			/* Turn off the battery outline */
			SEG17_DEF &= (uint8_t)(~0x01u);

			/* Change the count direction */
			count_direction = TRUE;
		}
		break;

		case BATT_LEVEL_2:
		{
			/* Turn on 2 battery bars */
			SECTD_Glyph_Map(BATT_LEVEL_2, BATTERY_OUTLINE_OFF);

			/* Turn off the battery outline */
			SEG17_DEF &= (uint8_t)(~0x01u);
		}
		break;

		case BATT_LEVEL_3:
		{
			/* Turn on 3 battery bars */
			SECTD_Glyph_Map(BATT_LEVEL_3, BATTERY_OUTLINE_OFF);

			/* Turn off the battery outline */
			SEG17_DEF &= (uint8_t)(~0x01u);
		}
		break;

		case BATT_LEVEL_4:
		{
			/* Turn on 4 battery bars */
			SECTD_Glyph_Map(BATT_LEVEL_4, BATTERY_OUTLINE_OFF);

			/* Change the count direction */
			count_direction = FALSE;
		}
		break;

		default:
		{
			/* Do nothing */
		}
		break;
	}

	/* Check if the counter is greater than the available number of bars */
	if (TRUE == count_direction)
	{
		bat_level_indicator++;
	}
	else
	{
		bat_level_indicator--;
	}
    
	/* Clear the interrupt flag */
    TMIF02 = 0x0;
}
/***********************************************************************************************************************
* End of function INT_TM02
***********************************************************************************************************************/

