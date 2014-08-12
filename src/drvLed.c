#include "dd_types.h"
#include "drvLed.h"
#include "r_cg_userdefine.h"
#include "kernel.h"

static driver thisDriver;

static ptrFuncDrv this_functions[LED_END];

char initLed(void *parameters);
char ligaLed(void *parameters);
char desligaLed(void *parameters);
char toggleLed(void *parameters);

char initLed(void *parameters){
	LED0 = 0;
	LED1 = 0;
	LED2 = 0;

	return sucesso;
}

char ligaLed(void *parameters){
	int  i;
	i = (char) parameters;
	switch (i){
		case 0:
			LED0 = 1; break;
		case 1:
			LED1 = 1; break;
		case 2:
			LED2 = 1; break;
	}
	return sucesso;
}

char desligaLed(void *parameters){
	int  i;
	i = (char) parameters;
	switch (i){
		case 0:
			LED0 = 0; break;
		case 1:
			LED1 = 0; break;
		case 2:
			LED2 = 0; break;
	}
	return sucesso;
}

char toggleLed(void *parameters){
	int  i;
	i = (char) parameters;
	switch (i){
		case 0:
			LED0 = ~LED0; break;
		case 1:
			LED1 = ~LED1; break;
		case 2:
			LED2 = ~LED2; break;
	}
	return repetir;
}
//Função para acesso ao driver

driver* getLedDriver(void){
	thisDriver.drv_init = initLed;
	
//Funções do driver
	this_functions[LIGA_LED] = ligaLed;
	this_functions[DESL_LED] = desligaLed;
	this_functions[TOG_LED] = toggleLed;

	thisDriver.drv_func = &this_functions;
	return &thisDriver;
}

