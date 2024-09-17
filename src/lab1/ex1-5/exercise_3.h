/*
 * exercise_3.h
 *
 *  Created on: Sep 14, 2024
 *      Author: l1ttled1no
 */

#ifndef SRC_EXERCISE_3_H_
#define SRC_EXERCISE_3_H_

#include "main.h"


int init = 0;

/****************************************************/
//Vertical LED:
//Stage 1: GREEN - 3 sec
//Stage 2: YELLOw - 2 sec
//Stage 3: RED - 5 sec
//
//Horizontal LED:
//Stage 1: RED - 5 sec
//Stage 2: GREEN - 3 sec
//Stage 3: YELLOW - 2 sec

/****************************************************/

int ver_stage = 0, hor_stage = 0;
int ver_timer = 0, hor_timer = 0;


void ver_setup_init(){
	ver_stage = 1;
	HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, 0);
	HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, 0);
	HAL_GPIO_WritePin(grn_v_GPIO_Port, grn_v_Pin, 1);
}

void ver_stage2(){
	ver_stage = 2;
//	Turn on: YEL
	HAL_GPIO_TogglePin(yel_v_GPIO_Port, yel_v_Pin);
//	Turn off: GRN
	HAL_GPIO_TogglePin(grn_v_GPIO_Port, grn_v_Pin);
}
void ver_stage3(){
	ver_stage = 3;
//	Turn on: RED
	HAL_GPIO_TogglePin(red_v_GPIO_Port, red_v_Pin);
//	Turn off: YEL
	HAL_GPIO_TogglePin(yel_v_GPIO_Port, yel_v_Pin);
}
void ver_stage1(){
	ver_stage = 1;
//	Turn on: GRN
	HAL_GPIO_TogglePin(grn_v_GPIO_Port, grn_v_Pin);
//	Turn off: RED
	HAL_GPIO_TogglePin(red_v_GPIO_Port, red_v_Pin);
}
//Horizontal LED:
//Stage 1: RED - 5 sec
//Stage 2: GREEN - 3 sec
//Stage 3: YELLOW - 2 sec
void hor_setup_init(){
	HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, 1);
	HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, 0);
	HAL_GPIO_WritePin(grn_h_GPIO_Port, grn_h_Pin, 0);
	hor_stage = 1;
}
void hor_stage2(){
	hor_stage = 2;
//	Turn on: GRN
	HAL_GPIO_TogglePin(grn_h_GPIO_Port, grn_h_Pin);
//	Turn off: RED
	HAL_GPIO_TogglePin(red_h_GPIO_Port, red_h_Pin);
}

void hor_stage3(){
	hor_stage = 3;
//	Turn on: YEL
	HAL_GPIO_TogglePin(yel_h_GPIO_Port, yel_h_Pin);
//	Turn off: GRN
	HAL_GPIO_TogglePin(grn_h_GPIO_Port, grn_h_Pin);
}

void hor_stage1(){
	hor_stage = 1;
//	Turn on: RED
	HAL_GPIO_TogglePin(red_h_GPIO_Port, red_h_Pin);
//	Turn off: YEL
	HAL_GPIO_TogglePin(yel_h_GPIO_Port, yel_h_Pin);
}

void exercise_3(){
	if (init == 0){
		++init;
		ver_setup_init();
		hor_setup_init();
	}

	switch(ver_stage){
	case 1:
		if (ver_timer >= 3) {
			ver_stage2();
			ver_timer = 0;
		}
		break;
	case 2:
		if (ver_timer >= 2) {
			ver_stage3();
			ver_timer = 0;
		}
		break;
	case 3:
		if (ver_timer >= 5) {
			ver_stage1();
			ver_timer = 0;
		}
		break;
	}

	switch(hor_stage){
	case 1:
		if (hor_timer >= 5) {
			hor_stage2();
			hor_timer = 0;
		}
		break;
	case 2:
		if (hor_timer >= 3) {
			hor_stage3();
			hor_timer = 0;
		}
		break;
	case 3:
		if (hor_timer >= 2) {
			hor_stage1();
			hor_timer = 0;
		}
		break;
	}
	++ver_timer;
	++hor_timer;
}


#endif /* SRC_EXERCISE_3_H_ */
