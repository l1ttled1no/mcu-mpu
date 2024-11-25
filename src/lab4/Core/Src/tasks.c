/*
 * tasks.c
 *
 *  Created on: Nov 25, 2024
 *      Author: l1ttled1no
 */


#include "tasks.h"

void task1 (void){
    HAL_GPIO_TogglePin(led0_GPIO_Port, led0_Pin);
}

void task2 (void){
	HAL_GPIO_TogglePin(led1_GPIO_Port, led1_Pin);
}

void task3(void){
	HAL_GPIO_TogglePin(led2_GPIO_Port, led2_Pin);
}

void task4(void){
	HAL_GPIO_TogglePin(led3_GPIO_Port, led3_Pin);
}


