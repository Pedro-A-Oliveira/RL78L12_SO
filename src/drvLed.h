#ifndef drvLed_H
	#define drvLed_H
	#include "dd_types.h"
	#include "r_cg_userdefine.h"
	
	//lista de funções do driver
	enum {
		LIGA_LED, DESL_LED, TOG_LED, LED_END
	};
	
	//função de acesso ao driver
	driver* getLedDriver(void);
#endif
