/*
 * led.h
 *
 *  Created on: Nov 11, 2024
 *      Author: l1ttled1no
 */

#ifndef INC_LED_H_
#define INC_LED_H_
#include "global.h"

#define LED_ON		0
#define LED_OFF		1

extern int horState;
extern int verState;

void setLedH (int);
void setLedV (int);

#endif /* INC_LED_H_ */
