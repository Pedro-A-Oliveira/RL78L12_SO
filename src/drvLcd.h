/*
 * drvLcd.h
 *
 *  Created on: Jun 12, 2014
 *      Author: Pedro
 */
#ifndef drvLcd_H
	#define drvLcd_H
	#include "dd_types.h"
	#include "lcd_panel.h"

	char initLcd(void *parameters);
	char lcdClear(void *parameters);
	char lcdOn(void *parameters);
	char lcdOff(void *parameters);
	char lcdDelay(void *parameters);
	char lcdString(void *parameters);
	char lcdSimbolos(void *parameters);
	char lcdDias(void *parameters);
	char lcdBateria(void *parameters); //LEVEL_0,LEVEL_1,LEVEL_2,LEVEL_3,LEVEL_4
	char ledSecb(void *parameters);
	char ledSeca(void *parameters);


//lista de funções do driver
	enum {
		LCD_CLEAR,LCD_ON,LCD_OFF,LCD_SECA,LCD_SECB,LCD_BAT,LCD_DIAS,LCD_SIMB,LCD_STG,LCD_DELAY,LCD_END
	};
	//LCD_SECA -> XX.X
	//LCD_SECB -> XX:XX RELOGIO
	//LCD_SECC -> XXXX NÚMEROS E LETRAS
	//LCD_SECD -> BATERIA
	//LCD_SECF -> DIAS
	//LCD_SIMB -> SIMBOLOS

	//função de acesso ao driver
		driver* getLcdDriver(void);
#endif

