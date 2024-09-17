/*
 * exercise_2.h
 *
 *  Created on: Sep 12, 2024
 *      Author: l1ttled1no
 */

#ifndef SRC_EXERCISE_2_H_
#define SRC_EXERCISE_2_H_
#include "main.h"

unsigned int ini = 0;
unsigned int count = 0;
unsigned int stage = 0;

void iniStage(){
	HAL_GPIO_WritePin(red_led_GPIO_Port, red_led_Pin, 0);
	HAL_GPIO_WritePin(yel_led_GPIO_Port, yel_led_Pin, 1);
	HAL_GPIO_WritePin(grn_led_GPIO_Port, grn_led_Pin, 1);
}

void Stage2(){
	// Switch red light to off, switch yellow light to on
	HAL_GPIO_TogglePin(red_led_GPIO_Port, red_led_Pin);
	HAL_GPIO_TogglePin(yel_led_GPIO_Port, yel_led_Pin);

}

void Stage3(){
	//Stage 2 -> 3: switch yellow to off; switch green to on
	HAL_GPIO_TogglePin(yel_led_GPIO_Port, yel_led_Pin);
	HAL_GPIO_TogglePin(grn_led_GPIO_Port, grn_led_Pin);
}

void Stage1(){
	//Stage 3 -> 1: switch green to off; switch red to on;
	HAL_GPIO_TogglePin(grn_led_GPIO_Port, grn_led_Pin);
	HAL_GPIO_TogglePin(red_led_GPIO_Port, red_led_Pin);
}


void exercise2(){
	if (ini == 0){
		iniStage();
		stage = 1;
		ini++;
	}

	switch (stage){
	case 1:
	{
		if (count ==5){
			stage = 2;
			Stage2();
			count = 0;
		}
		break;
	}
	case 2:
	{
		if (count == 3){
			stage = 3;
			Stage3();
			count = 0;
		}
		break;
	}
	case 3:
		{
		if (count == 2){
			stage = 1;
			Stage1();
			count = 0;
		}
		break;
	}
	}
	++count;


}
#endif /* SRC_EXERCISE_2_H_ */
