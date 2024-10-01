/*
 * header.h
 *
 *  Created on: Oct 1, 2024
 *      Author: l1ttled1no
 */

#ifndef SRC_HEADER_H_
#define SRC_HEADER_H_
#include "main.h"
//int matrix_idx = 0;
//uint8_t matrix_buffer_A[8] = {0x00, 0xc0, 0x80, 0x33, 0x33, 0x80, 0xc0, 0x00};
//uint8_t constMat[8] = {0x00, 0xc0, 0x80, 0x33, 0x33, 0x80, 0xc0, 0x00};
///* TIMER STARTS HERE */
//int counter = 0, flag = 0;
//
//int const cycle = 10;
//
//void set(int duration){
//	counter = duration / cycle;
//	flag = 0;
//}
//
//void run(void){
//	counter--;
//	if (counter == 0) flag = 1;
//}
//
///* TIMER ENDS HERE */
//
//int convertedBinary[8] = {0, 0, 0, 0, 0 ,0 ,0 ,0};
//
//void convertToBinary(uint8_t num){
//    for(int i = 7; i >= 0; i--){
//        convertedBinary[i] = num % 2;
//        num = num / 2;
//        if (convertedBinary[i] == 1) convertedBinary[i] = 0;
//        else convertedBinary[i] = 1;
//    }
//}
//
//void displayLEDMatrix(uint8_t value){
//	for (int a = 0; a < 8; a++){
//		if(value == constMat[a]){
//			convertToBinary(constMat[a]);
//			for (int i = 0; i < 8; i++){
//				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8 << i, convertedBinary[i]); //Write Rows
//			}
//			break; //Break the for loop
//		}
//	}
//}
//
//
//void updateLEDMatrix(int index){
//	for (int i = 0; i < 8; i++){
//		if (i == index) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 << i, 0);
//		else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 << i, 1);
//	}
//	displayLEDMatrix(matrix_buffer_A[index]);
//}

int matrix_idx = 0;
//uint8_t matrix_buffer_A[8] = {0x00, 0xc0, 0x80, 0x33, 0x33, 0x80, 0xc0, 0x00};
uint8_t matrix_buffer_A[8] = {0x3C, 0x66, 0x66,0x7E,0x66,0x66,0x66,0x00};

/* TIMER STARTS HERE */
int counter = 0, flag = 0;

int const cycle = 10;

void set(int duration){
	counter = duration / cycle;
	flag = 0;
}

void run(void){
	counter--;
	if (counter == 0) flag = 1;
}

/* TIMER ENDS HERE */
int convertedBinary[8] = {0,0,0,0,0,0,0,0};
int arr[16]; //16-bit array
int arr2[16];
int shift_counter = 0;
void convertToBinary(uint8_t num){
    for(int i = 7; i >= 0; i--){
        convertedBinary[i] = num % 2;
        num = num / 2;
    }
}
void convertShift(uint8_t num){
	for(int i = 15; i >= 0; i--){
		arr[i] = num % 2;
		arr2[i] = arr[i];
		num = num / 2;
	}
	for (int i = 0; i < 16; i++){
		int newidx = i - shift_counter;
		if (newidx >= 0) arr[newidx] = arr2[i];
		else arr[15 - shift_counter + 1] = arr2[i];
	}
}

//void shiftMatrixBuffer(){
//    for (int i = 0; i < 8; i++) {
//        matrix_buffer_A[i] = (matrix_buffer_A[i] << 1) | (matrix_buffer_A[i] >> 7); // Left shift
//    }
//}
void updateLEDMatrix(int index){
	for (int i = 0; i < 8; i++){
		if (index == i){
//			convertToBinary(matrix_buffer_A[i]);
			convertShift(matrix_buffer_A[i]);
			for(int j = 0; j < 8; j++){
				HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin << j, arr[j + 4]);
			}
			break;
		}
	}
}

void resetState(){
	for (int i = 0; i < 8; i++){
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin << i, 0);
	}
}
void displayLEDMatrix(){
	if (matrix_idx >= 8) {
		matrix_idx = matrix_idx % 8;
		shift_counter++;
		if (shift_counter >= 16) shift_counter = shift_counter%16;
	}
	resetState();
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin << matrix_idx, SET);
	updateLEDMatrix(matrix_idx);
}


#endif /* SRC_HEADER_H_ */
