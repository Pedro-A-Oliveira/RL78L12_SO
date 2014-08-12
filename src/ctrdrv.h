/*
 * ctrdrv.h
 *
 *  Created on: May 18, 2014
 *      Author: Pedro
 */
#ifndef ctrdrv_h
    #define ctrdrv_h
	#define QNTD_DRV 20

	#include "dd_types.h"
	#include "drvLed.h"
	#include "drvLcd.h"
	#include "drvBot.h"
	#include "drvADC.h"


char initCtrDrv(void);
char callDriver(char drv_id, char func_id, void *parameters);
char initDriver(char newDriver);

enum{
	DRV_LED,
	DRV_LCD,
	DRV_BOT,
	DRV_ADC,
	DRV_END
};
static ptrGetDrv drvGetFunc[DRV_END] = {
	getLedDriver,
	getLcdDriver,
	getBotDriver,
	getAdcDriver,
};
#endif // ddCtr_h
