/*
 * timer.h
 *
 *  Created on: Nov 11, 2024
 *      Author: l1ttled1no
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "global.h"
#define CYCLE 	10
extern int flag1,
		   flag2,
		   flag3,
		   flag4,
		   flag5; 


void set1(int);
void set2(int);
void set3(int);
void set4(int);
void set5(int); 
void resetTimer(int);

void timerRun();


#endif /* INC_TIMER_H_ */
