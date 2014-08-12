/*
 * drvBot.h
 *
 *  Created on: Jun 26, 2014
 *      Author: Pedro
 */

#ifndef DRVBOT_H_
	#define DRVBOT_H_

	#include "dd_types.h"
	#include "r_cg_userdefine.h"

	#define CH1 1
	#define CH2 2
	#define CH3 4

	//lista de funções do driver
	enum {
		BOT_PUSH, BOT_SEL, BOT_END
	};

	//função de acesso ao driver
	driver* getBotDriver(void);

#endif /* DRVBOT_H_ */
