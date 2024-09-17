/*
 * exercise_4.h
 *
 *  Created on: Sep 15, 2024
 *      Author: l1ttled1no
 */

#ifndef SRC_EXERCISE_4_H_
#define SRC_EXERCISE_4_H_
#include "main.h"
int arr[10][7] = {
    {0, 0, 0, 0, 0, 0, 1}, //0
    {1, 0, 0, 1, 1, 1, 1}, //1
    {0, 0, 1, 0, 0, 1, 0}, //2
    {0, 0, 0, 0, 1, 1, 0}, //3
    {1, 0, 0, 1, 1, 0, 0}, //4
    {0, 1, 0, 0, 1, 0, 0}, //5
    {0, 1, 0, 0, 0, 0, 0}, //6
    {0, 0, 0, 1, 1, 1, 1}, //7
    {0, 0, 0, 0, 0, 0, 0}, //8
    {0, 0, 0, 0, 1, 0, 0}  //9
};
//	 a, b, c, d, e, f, g


void display7SEG(int num){
	if (num >= 0 && num <= 9){
		for (int state = 0; state < 7; state++){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << state, arr[num][state]);
		}
	}
	else HAL_GPIO_WritePin(GPIOB, GPIO_PIN_All, 0);
}


#endif /* SRC_EXERCISE_4_H_ */
