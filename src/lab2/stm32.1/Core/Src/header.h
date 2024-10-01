/*
 * header.h
 *
 *  Created on: Sep 28, 2024
 *      Author: l1ttled1no
 */

#ifndef SRC_HEADER_H_
#define SRC_HEADER_H_
#include "main.h"
int arr[11][7] = {
    {0, 0, 0, 0, 0, 0, 1}, //0
    {1, 0, 0, 1, 1, 1, 1}, //1
    {0, 0, 1, 0, 0, 1, 0}, //2
    {0, 0, 0, 0, 1, 1, 0}, //3
    {1, 0, 0, 1, 1, 0, 0}, //4
    {0, 1, 0, 0, 1, 0, 0}, //5
    {0, 1, 0, 0, 0, 0, 0}, //6
    {0, 0, 0, 1, 1, 1, 1}, //7
    {0, 0, 0, 0, 0, 0, 0}, //8
    {0, 0, 0, 0, 1, 0, 0}, //9
	{1, 1, 1, 1, 1, 1, 1}  //ALL LED TURN OFF
};
//	 a, b, c, d, e, f, g



void display7SEG(int num){
	if (num >= 0 && num <= 9){
		for (int state = 0; state < 7; state++){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << state, arr[num][state]);
		}
	}
	else for (int state = 0; state < 7; state++){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << state, arr[10][state]);
	}
}


void toggle(){
	HAL_GPIO_TogglePin(en0_GPIO_Port, en0_Pin);
	HAL_GPIO_TogglePin(en1_GPIO_Port, en1_Pin);
}




//void init(){
//	display7SEG(-1);
//	HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
//	HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 0);
//}
//
//int clock_1 = 50;
//void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef * htim){
//	clock_1--;
//	if (clock_1 == 0){
//		if (HAL_GPIO_ReadPin(en0_GPIO_Port, en0_Pin) == 0){
//			HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
//			HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 0);
//			display7SEG(2);
////			update7SEG(index_led++);
//		}
//		else {
//			HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 0);
//			HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 1);
//			display7SEG(1);
////			update7SEG(index_led++);
//		}
//		clock_1 = 50;
//	}
//}
// Exercise 2
//int const clockNum = 4;
//int clockArr[4] = {0, 0, 0, 0};
//int clockFlag[4] = {0, 0, 0, 0};
//int const cycle = 10;
//void clockRuns(){
//	for (int i = 0; i < clockNum; i++){
//		if (clockArr[i] > 0) clockArr[i]--;
//		else {
//			clockFlag[i] = 1;
//		}
//	}
//}

//// Exercise2
//int clock_1 = 110;
//int clock7Seg = 1;
//int stage = 0; //init stage
//void setClock (int time, int clockNo){
//	int newTime = time/cycle;
//	if (clockNo < clockNum){
//		int clockArr[clockNo] = newTime;
//		int clockFlag[clockNo] = 0;
//	}
//}
//
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){
//	clock_1 --;
//	if (clock_1 <= 0) {
//		HAL_GPIO_TogglePin(dot_GPIO_Port, dot_Pin);
//		clock_1 = 110;
//	}
//	clock7Seg--;
//	if (clock7Seg <= 0){
//		switch (stage){
//			case 0:
//			{
//				HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 0);
//				HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 1);
//				HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 1);
//				HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 1);
//				display7SEG(1);
//				stage = 1;
//				break;
//			}
//			case 1:
//			{
//				HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
//				HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 0);
//				HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 1);
//				HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 1);
//				display7SEG(2);
//				stage = 2;
//				break;
//			}
//			case 2:
//			{
//				HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
//				HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 1);
//				HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 0);
//				HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 1);
//				display7SEG(3);
//				stage = 3;
//				break;
//			}
//			case 3:
//			{
//				HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
//				HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 1);
//				HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 1);
//				HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 0);
//				display7SEG(0);
//				stage = 0;
//				break;
//			}
//		}
//		clock7Seg = 100;
//	}
//}


const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {3, 2, 1, 5};

void resetLED(){
	HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
	HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 1);
	HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 1);
	HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 1);
}

void enSelect(int idx){
	switch (idx){
		case 0:
			{
					HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 0);
					HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 1);
					HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 1);
					HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 1);
					break;
				}
				case 1:
				{
					HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
					HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 0);
					HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 1);
					HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 1);
					break;
				}
				case 2:
				{
					HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
					HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 1);
					HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 0);
					HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 1);
					break;
				}
				case 3:
				{
					HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
					HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 1);
					HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 1);
					HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 0);
					break;
				}
				default:
				{
					HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 0);
					HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 0);
					HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 0);
					HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 0);
					break;
				}
			}
}

void update7SEG (int index){
	if (index_led >= MAX_LED) index_led = 0; //Check index_led
	index = index % 4;
	switch (index){
		case 0:{
			enSelect(index);
			display7SEG(led_buffer[index]);
			break;
		}
		case 1:{
			enSelect(index);
			display7SEG(led_buffer[index]);
			break;
		}
		case 2:{
			enSelect(index);
			display7SEG(led_buffer[index]);
			break;
		}
		case 3:{
			enSelect(index);
			display7SEG(led_buffer[index]);
			break;
		}
		default:
			enSelect(-1);
//			display7SEG(-1); // Turn off the LED
			break;
	}
}
int clock_1 = 25;
int clockBlink = 100;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){
	clock_1--;
	clockBlink--;
	if (clock_1 <= 0) {
		update7SEG(index_led++);
		clock_1 = 25;
	}
	if (clockBlink <= 0){
		HAL_GPIO_TogglePin(dot_GPIO_Port, dot_Pin);
		clockBlink = 100;
	}
}
//int clock0 = 0; //250
//int clockBlink = 0;
//int clockBlink_flag = 0;
//int clock0_flag = 0;
//
//int const cycle = 10;
//void setBlink(int dur){
//	clockBlink = dur / cycle;
//	clockBlink_flag = 0;
//}
//
//void setclock(int dur){
//	clock0 = dur/cycle;
//	clock0_flag = 0;
//}
//
//void BlinkRun(){
//	clockBlink--;
//	if (clockBlink == 0) clockBlink_flag = 1;
//}
//
//void clockRun(){
//	clock0--;
//	if (clock0 == 0) clock0_flag = 1;
//}
//
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){
//
////	clockBlink--;
//	BlinkRun();
//	clockRun();
//}
//
//
int hrs = 21,
	min = 12,
	sec = 40;
void updateClockBuffer(){
	led_buffer[0] = hrs / 10;
	led_buffer[1] = hrs % 10;
	led_buffer[2] = min / 10;
	led_buffer[3] = min % 10;
}


#endif /* SRC_HEADER_H_ */
