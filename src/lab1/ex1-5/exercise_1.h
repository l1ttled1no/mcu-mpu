/*
 * exercise_1.c
 *
 *  Created on: Sep 12, 2024
 *      Author: l1ttled1no
 */

#ifndef SRC_EXERCISE_1_C_
#define SRC_EXERCISE_1_C_
#include "main.h"

unsigned int setIni = 0;
unsigned int count = 0;

void toggle_LED() {
	HAL_GPIO_TogglePin(red_led_GPIO_Port, red_led_Pin);
	HAL_GPIO_TogglePin(yel_led_GPIO_Port, yel_led_Pin);
}

void set_initial_LED(){
	HAL_GPIO_WritePin(red_led_GPIO_Port, red_led_Pin, 0);
	HAL_GPIO_WritePin(yel_led_GPIO_Port, yel_led_Pin, 1);
}

void exercise1(){
//	static unsigned int setIni = 0;
//	static unsigned int count = 0;
	if (setIni == 0){
		set_initial_LED(); //set initial LED
		setIni ++;
	}
	if (count >= 3){
		count = 0;
		toggle_LED(); //toggle LED
	}
	else ++count;
}


#endif /* SRC_EXERCISE_1_C_ */
