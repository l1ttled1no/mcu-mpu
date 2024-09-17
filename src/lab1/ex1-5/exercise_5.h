/*
 * exercise_5.h
 *
 *  Created on: Sep 15, 2024
 *      Author: l1ttled1no
 */

#ifndef SRC_EXERCISE_5_H_
#define SRC_EXERCISE_5_H_

#include "exercise_3.h"
#include "exercise_4.h"
#include "main.h"
void display7SEG2(int num){
	if (num >= 0 && num <= 9){
		for (int state = 7; state < 14; state++){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << state, arr[num - 1][state]);
		}
	}
}
void exercise5(){
	exercise_3();
	switch(ver_stage){
	case 1:
		display7SEG(3-ver_timer);
		break;
	case 2:
		display7SEG(2-ver_timer);
		break;
	case 3:
		display7SEG(5-ver_timer);
		break;
	}
	switch (hor_stage){
	case 1:
		display7SEG2(5-hor_timer);
		break;
	case 2:
		display7SEG2(3-hor_timer);
		break;
	case 3:
		display7SEG2(2-hor_timer);
		break;
	}
}
//	switch ()


#endif /* SRC_EXERCISE_5_H_ */
