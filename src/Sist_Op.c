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
* File Name    : r_main.c
* Version      : Applilet3 for RL78/L12 V1.00.00 [23 Mar 2012]
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file implements main function.
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
#include "r_cg_it.h"
#include "r_cg_adc.h"
#include "r_cg_cgc.h"
#include "r_cg_intc.h"
#include "r_cg_timer.h"
#include "r_cg_userdefine.h"
#include "kernel.h"
#include "dd_types.h"
#include "ctrdrv.h"
#include "lcd_panel.h"


/***********************************************************************************************************************
* Global Variables and Functions
***********************************************************************************************************************/
/* Software counter variable used for debugging example */
//uint16_t  g_software_counter  = MD_CLEAR;

/* Stores the multiplication result */
//uint32_t g_result             = MD_CLEAR;
//Initialize global constructors

int tmp = 0;
char stop = 1;
char var = 0;


char procRelogio(void){
	if(stop == 0){
		if(tmp < 6000){
			callDriver(DRV_LCD, LCD_SECB, tmp);
			tmp++;
		}
		else {
			tmp = 0;
			callDriver(DRV_LCD, LCD_SECB, tmp);
			tmp++;
		}
	}
	else callDriver(DRV_LCD, LCD_SECB, tmp);
	return repetir;
}

char paraRelogio(void){
	char tecla;
	callDriver(DRV_BOT, BOT_PUSH, &tecla);
	if (tecla == 0x04) stop = 1;
	if (tecla == 0x02) stop = 0;
	if (tecla == 0x01) tmp = 0;
	return repetir;
}

char temperatura(void){
	int g_adc;
	callDriver(DRV_ADC, ADC_SGET, &g_adc);
	g_adc /= 2;
	callDriver(DRV_LCD, LCD_SECA, g_adc);
	return repetir;
}

char leds(void){
	if(var <= 3){
		callDriver(DRV_LED, TOG_LED, var);
		var++;
	}else{
		var = 0;
	}
	return repetir;
}

int main(void)
{
	process p1;
	process p2;
	process p3;
	process p4;

	R_IT_Start();
	KernelInit();
	initCtrDrv();

    initDriver(DRV_LCD);
    initDriver(DRV_BOT);
    initDriver(DRV_LED);
    initDriver(DRV_ADC);

	p1.funcao = procRelogio;
	p1.periodo = 10;
	p1.start = 0;
	p1.prioridade = 0;

	p2.funcao = paraRelogio;
	p2.periodo = 5;
	p2.start = 0;
	p2.prioridade = 1;

	p3.funcao = temperatura;
	p3.periodo = 50;
	p3.start = 0;
	p3.prioridade = 1;

	p4.funcao = leds;
	p4.periodo = 100;
	p4.start = 0;
	p4.prioridade = 1;

    KernelAddProc(&p1);
    KernelAddProc(&p2);
    KernelAddProc(&p3);
    KernelAddProc(&p4);

    KernelLoop();

}
