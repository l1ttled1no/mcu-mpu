/*
 * led.c
 *
 *  Created on: Nov 11, 2024
 *      Author: l1ttled1no
 */
#include "led.h"
int horState = NONE;
int verState = NONE;
void setLedH(int color){
	switch(color){
	case RED:
		HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, LED_ON);
		HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, LED_OFF);
		HAL_GPIO_WritePin(grn_h_GPIO_Port, grn_h_Pin, LED_OFF);
		horState = RED;
		break;
	case YEL:
		HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, LED_OFF);
		HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, LED_ON);
		HAL_GPIO_WritePin(grn_h_GPIO_Port, grn_h_Pin, LED_OFF);
		horState = YEL;
		break;
	case GRN:
		HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, LED_OFF);
		HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, LED_OFF);
		HAL_GPIO_WritePin(grn_h_GPIO_Port, grn_h_Pin, LED_ON);
		horState = GRN;
		break;
	case ALL:
		HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, LED_ON);
		HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, LED_ON);
		HAL_GPIO_WritePin(grn_h_GPIO_Port, grn_h_Pin, LED_ON);
		horState = ALL;
		break;
	default:
		HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, LED_OFF);
		HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, LED_OFF);
		HAL_GPIO_WritePin(grn_h_GPIO_Port, grn_h_Pin, LED_OFF);
		horState = NONE;
		break;
	}
}

void setLedV(int color){
	switch(color){
	case RED:
		HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, LED_ON);
		HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, LED_OFF);
		HAL_GPIO_WritePin(grn_v_GPIO_Port, grn_v_Pin, LED_OFF);
		verState = RED;
		break;
	case YEL:
		HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, LED_OFF);
		HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, LED_ON);
		HAL_GPIO_WritePin(grn_v_GPIO_Port, grn_v_Pin, LED_OFF);
		verState = YEL;
		break;
	case GRN:
		HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, LED_OFF);
		HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, LED_OFF);
		HAL_GPIO_WritePin(grn_v_GPIO_Port, grn_v_Pin, LED_ON);
		verState = GRN;
		break;
	case ALL:
		HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, LED_ON);
		HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, LED_ON);
		HAL_GPIO_WritePin(grn_v_GPIO_Port, grn_v_Pin, LED_ON);
		verState = ALL;
		break;
	default:
		HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, LED_OFF);
		HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, LED_OFF);
		HAL_GPIO_WritePin(grn_v_GPIO_Port, grn_v_Pin, LED_OFF);
		verState = NONE;
		break;
	}
}
