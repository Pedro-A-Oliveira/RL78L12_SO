/*
 * drvBot.c
 *
 *  Created on: Jun 26, 2014
 *      Author: Pedro
 */
#include "dd_types.h"
#include "drvBot.h"
#include "r_cg_userdefine.h"
#include "kernel.h"

static driver thisDriver;

static ptrFuncDrv this_functions[BOT_END];

char return_bot;


char initBot(void *parameters){
	return_bot = 0;
	return sucesso;
}

//#define BitSet(var,pos) (var |=1<<pos)
//#define BitClr(var,pos) (var &=~(1<<pos))
//#define BitFlp(var,pos) (var ^=1<<pos)
//#define BitTst(var,pos) (var&(1<<pos))

//Envia-se os parametros por ponteiro tipo:     callDriver(DRV_BOT, BOT_PUSH,&tecla);
												//if (tecla&CH2){
												//	callDriver(DRV_LCD,LCD_DIAS,SATURDAY);
												//}


char botPush(void *parameters){
	unsigned char val=0;
	if(!SW1){
		val = val | 0x01;
	}
	if(!SW2){
		val = val | 0x02;
		}
	if(!SW3){
		val = val | 0x04;
		}
   *((unsigned char *)parameters) = val;
   return sucesso;
}

char botSelect(void *parameters){
   //utilizando o valor de prm via referencia
	switch(*(unsigned char *)parameters){
		case 1:
			if(!SW1){
				return_bot = 1;
			}
			else return_bot = 0;
			break;
		case 2:
			if(!SW2){
				return_bot = 1;
			}
			else return_bot = 0;
			break;
		case 3:
			if(!SW3){
				return_bot = 1;
			}
			else return_bot = 0;
			break;
		default:
		return_bot = 0;
	}
	*(unsigned char *)parameters = return_bot;
	return sucesso;
}


//Função para acesso ao driver

driver* getBotDriver(void){
	thisDriver.drv_init = initBot;

//Funções do driver
	this_functions[BOT_PUSH] = botPush;
	this_functions[BOT_SEL] = botSelect;

	thisDriver.drv_func = &this_functions;
	return &thisDriver;
}
