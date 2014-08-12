/*
 * drvLcd.c
 *
 *  Created on: Jun 12, 2014
 *      Author: Pedro
 */
#include "dd_types.h"
#include "drvLcd.h"
#include "r_cg_userdefine.h"
#include "kernel.h"

static driver thisDriver;

static ptrFuncDrv this_functions[LCD_END];



char initLcd(void *parameters){
	Init_Display_Panel();
	return sucesso;
}

char lcdClear(void *parameters){
	Clear_Display();
	return sucesso;
}

char lcdOn(void *parameters){
	Lcd_On();
	return sucesso;
}

char lcdOff(void *parameters){
	Lcd_Off();
	return sucesso;
}

//Delay em microsegundos
char lcdDelay(void *parameters){
	Display_Panel_Delay((uint32_t)parameters);
	return sucesso;
}

char lcdString(void *parameters){
	Display_Panel_String (PANEL_LCD_LINE1, (char * const)parameters);
	return sucesso;
}

char lcdSimbolos(void *parameters){
	Symbol_Map ((uint16_t const) parameters);
	return sucesso;
}

char lcdDias(void *parameters){
	SECTF_Glyph_Map ((uint8_t const) parameters);
	return sucesso;
}

//Parametros para a bateria LEVEL_0,LEVEL_1,LEVEL_2,LEVEL_3,LEVEL_4
char lcdBateria(void *parameters){
	SECTD_Glyph_Map ((uint8_t const) parameters, BATTERY_OUTLINE_ON);
	return sucesso;
}
/*
char lcdRelogio(void *parameters){
	SECTB_Glyph_Map ((uint8_t const) parameters, BATTERY_OUTLINE_ON);
	return sucesso;
}*/

char lcdSeca(void *parameters){
	char val = 0;
	int valor = (int*)parameters;
	if(valor>=100){
		SECTA_Glyph_Map(0,CASE_2);
		while(valor >=100){
			val++;
			valor-=100;
		}
		SECTA_Glyph_Map((uint8_t const)val,CASE_0);
		val=0;
		while(valor>=10){
			val++;
			valor-=10;
		}
		SECTA_Glyph_Map((uint8_t const)val,CASE_1);
		val = valor;
		SECTA_Glyph_Map((uint8_t const)val,CASE_3);
	}else{
		SECTA_Glyph_Map((uint8_t const)'.',CASE_2);
		val=0;
		while(valor>=10){
			val++;
			valor-=10;
			}
		SECTA_Glyph_Map((uint8_t const)val,CASE_0);
		val=0;
		while(valor>=1){
			val++;
			valor-=1;
		}
		SECTA_Glyph_Map((uint8_t const)val,CASE_1);
		val = 0;
		while(valor>=0.1){
			val++;
			valor-=0.1;
		}
		SECTA_Glyph_Map((uint8_t const)val,CASE_3);

	}
}

char ledSecb(void *parameters){//Relogio envia os 4 digitos a serem mostrados ex:1230 (12:30)
	char val = 0;
	int valor = (int*)parameters;

	SECTB_Glyph_Map(':',CASE_3);
	while(valor >=1000){
			val++;
			valor-=1000;
		}
	SECTB_Glyph_Map((uint8_t const)val,CASE_1);
	val=0;
	while(valor>=100){
			val++;
			valor-=100;
		}
	SECTB_Glyph_Map((uint8_t const)val,CASE_2);
	val = 0;
	while(valor>=10){
				val++;
				valor-=10;
			}
	SECTB_Glyph_Map((uint8_t const)val,CASE_4);
	val = valor;
	SECTB_Glyph_Map((uint8_t const)val,CASE_5);
}

//Função para acesso ao driver

driver* getLcdDriver(void){
	thisDriver.drv_init = initLcd;

//Funções do driver
	this_functions[LCD_CLEAR] = lcdClear;
	this_functions[LCD_ON] = lcdOn;
	this_functions[LCD_OFF] = lcdOff;
	this_functions[LCD_DELAY] = lcdDelay;
	this_functions[LCD_STG] = lcdString;
	this_functions[LCD_SIMB] = lcdSimbolos;
	this_functions[LCD_DIAS] = lcdDias;
	this_functions[LCD_BAT] = lcdBateria;
	this_functions[LCD_SECA] = lcdSeca;
	this_functions[LCD_SECB] = ledSecb;

	thisDriver.drv_func = &this_functions;
	return &thisDriver;
}

