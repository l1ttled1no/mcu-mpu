/*
 * global.h
 *
 *  Created on: Nov 11, 2024
 *      Author: l1ttled1no
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "main.h"
#include "timer.h"
#include "segment.h"
#include "led.h"

#define RED		11
#define YEL		22
#define GRN		33
#define ALL 	44
#define NONE	0
//#define delay 	HAL_Delay
#define INIT 1

#define MAN_RED 10
#define MAN_YEL	20
#define	MAN_GRN 30

#define IDLE 	-1

void segmentUpdateAuto();

//void button0Signal();

void fsm_run();
void fsm_auto_hor();
void fsm_auto_ver();
void fsm_man();

#endif /* INC_GLOBAL_H_ */
