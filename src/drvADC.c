/*
 * drvADC.c
 *
 *  Created on: Jul 15, 2014
 *      Author: Pedro
 */
#include "dd_types.h"
#include "drvADC.h"
#include "r_cg_userdefine.h"
#include "kernel.h"

static driver thisDriver;

static ptrFuncDrv this_functions[ADC_END];

char initAdc(void *parameters){
	R_ADC_Create();
	R_ADC_Set_Operation_On();
	return sucesso;
}

char adcStart(void *parameters){
	R_ADC_Start();
	return sucesso;
}

char adcSget(void *parameters){
	R_ADC_Start();
	R_ADC_Get_Result(parameters);
	return sucesso;
}

char adcGet(void *parameters){
	R_ADC_Get_Result(parameters);
	return sucesso;
}

char adcStop(void *parameters){
	R_ADC_Stop();
	return sucesso;
}

//Função para acesso ao driver

driver* getAdcDriver(void){
	thisDriver.drv_init = initAdc;

//Funções do driver
	this_functions[ADC_START] = adcStart;
	this_functions[ADC_SGET] = adcSget;
	this_functions[ADC_GET] = adcGet;
	this_functions[ADC_STOP] = adcStop;

	thisDriver.drv_func = &this_functions;
	return &thisDriver;
}
