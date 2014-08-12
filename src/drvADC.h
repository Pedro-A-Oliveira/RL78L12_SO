/*
 * drvADC.h
 *
 *  Created on: Jul 15, 2014
 *      Author: Pedro
 */

#ifndef DRVADC_H_
#define DRVADC_H_

	#include "dd_types.h"
	#include "r_cg_adc.h"

	enum{
		ADC_START, ADC_SGET, ADC_GET, ADC_STOP, ADC_END
	};

	//função de acesso ao driver
	driver* getAdcDriver(void);

#endif /* DRVADC_H_ */
