/*
 * fsm.c
 *
 *  Created on: Nov 11, 2024
 *      Author: l1ttled1no
 */


/*
 * FSM Horizontal
 * state name: hor_state
 * State: RED, GREEN, YELLOW, default
 *
 */


#include "global.h"

int autoState_H = INIT;
int autoState_V = INIT;
int manState = IDLE;

int redDur = 5;
int yelDur = 2;
int grnDur = 3;

int tempRed = 1;
int tempYel = 1;
int tempGrn = 1;

int horCount = 0;
int verCount = 0;
int scan = 0;
void segmentUpdateAuto(){
	updateSegment2Digits(horCount, verCount);
}

void fsm_run(){
	fsm_auto_hor();
	fsm_auto_ver();
	fsm_man();
}

void button0Signal(){
	if (isButtonNoPressed(0) == 1){
		resetTimer(-1);
		horCount = 0, verCount = 0;
		updateSegment(IDLE, IDLE, IDLE, IDLE);
		scan = 0;
		setLedH(IDLE);
		setLedV(IDLE);
		autoState_H = IDLE;
		autoState_V = IDLE;
		manState = MAN_RED;
		set1(100);
		set3(100);
		return;
	}
}

void fsm_auto_hor(){
	switch(autoState_H){
	case INIT:
		set1(redDur * 1000); //timer1 is for the hor_state
		set2(1000); //counter
		set3(100);  //scanning LED, does not need at fsm_auto_ver
		horCount = redDur - 1;
		autoState_H = RED;
		break;
	case RED:
		setLedH(RED);
		if (flag2 == 1){
			horCount--;
//			verCount--; //sync with vertical
			if (verCount < 0) verCount = 9;
			set2(1000);
		}
		if (flag1 == 1){ //switch state
			set1(grnDur * 1000);
			horCount = grnDur - 1;
			autoState_H = GRN;
		}
		if (flag3 == 1){
			segmentUpdateAuto();
			scan = (scan == 1) ? 0 : 1;
			scan7Seg(scan);
			set3(100);
		}
		button0Signal();
		break;
	case GRN:
		setLedH(GRN);
		if (flag2 == 1){
			horCount--;
//			verCount--; //sync with vertical
			if (verCount < 0) verCount = 9;
			set2(1000);
		}

		if (flag1 == 1){
			set1(yelDur * 1000);
			horCount = yelDur - 1;
			autoState_H = YEL;
		}
		if (flag3 == 1){
			segmentUpdateAuto();
			scan = (scan == 1) ? 0 : 1;
			scan7Seg(scan);
			set3(100);
		}
		button0Signal();
		break;
	case YEL:
		setLedH(YEL);
		if (flag2 == 1){
			horCount--;
//			verCount--;
			if (verCount < 0) verCount = 9;//sync with vertical
			set2(1000);
		}

		if (flag1 == 1){
			set1(redDur * 1000);
			horCount = redDur - 1;
			autoState_H = RED;
		}
		if (flag3 == 1){
			segmentUpdateAuto();
			scan = (scan == 1) ? 0 : 1;
			scan7Seg(scan);
			set3(100);
		}
		button0Signal();
		break;
	default: //IDLE
		break;
	}
}

void fsm_auto_ver(){
    switch(autoState_V){
    case INIT: 
        set4(grnDur * 1000); //timer4 is for the ver_state
        set5(1000);
        verCount = grnDur - 1;
        autoState_V = GRN;
        break;
    case GRN:
    	setLedV(GRN);
    	if (flag5 == 1){
    		verCount--;
    		set5(1000);
    	}
    	if (flag4 == 1){
    		set4(yelDur * 1000);
    		verCount = yelDur - 1;
    		autoState_V = YEL;
    	}
    	break;
    case YEL:
    	setLedV(YEL);
    	if (flag5 == 1){
    		verCount--;
    		set5(1000);
    	}
    	if (flag4 == 1){
    		set4(redDur * 1000);
    		verCount = redDur - 1;
    		autoState_V = RED;
    	}
    	break;
    case RED: 
    	setLedV(RED);
    	if (flag5 == 1){
    		verCount--;
    		set5(1000);
    	}
    	if (flag4 == 1){
    		set4(grnDur * 1000);
    		verCount = grnDur - 1;
    		autoState_V = GRN;
    	}
    	break;
    default: break;
    }
}


void fsm_man(){
	switch(manState){
	case MAN_RED:
		updateSegment2Digits(tempRed, 22);
		if (isButtonNoPressed(0) == 1){
			//switch to man yellow and discard the change
			tempRed = 1;
			manState = MAN_YEL;
			setLedV(IDLE);
			setLedH(IDLE);
			set1(100);
			set3(100);
		}

		if (isButtonNoPressed(1) == 1){
			//add the tempRed 1 unit, if tempred > 99 -> 1
			tempRed = (tempRed == 99) ? 1 : tempRed + 1;
//			updateSegment2Digits(tempRed, 2);

		}
		if (isButtonNoPressed(2) == 1){
			//save the config of the light
			redDur = tempRed;
		}
		if (flag1 == 1){ //flickering the LEDs light
			HAL_GPIO_TogglePin(red_h_GPIO_Port, red_h_Pin);
			HAL_GPIO_TogglePin(red_v_GPIO_Port, red_v_Pin);
			set1(500);
		}
		if (flag3 == 1){
			scan = (scan + 1)%2;
			scan7Seg(scan);
			//set the flag again; then displaying modes
			set3(100);
		}
		break;
	case MAN_YEL:
		updateSegment2Digits(tempYel, 33);
		if (isButtonNoPressed(0) == 1){
			//switch to man grn and discard the change
			tempYel = 1;
			manState = MAN_GRN;
			setLedV(IDLE);
			setLedH(IDLE);
			set1(100);
			set3(100);
		}

		if (isButtonNoPressed(1) == 1){
			//add the tempRed 1 unit, if tempred > 99 -> 1
			tempYel = (tempYel == 99) ? 1 : tempYel + 1;
//			updateSegment2Digits(tempRed, 2);

		}
		if (isButtonNoPressed(2) == 1){
			//save the config of the light
			yelDur = tempYel;
		}
		if (flag1 == 1){ //flickering the LEDs light
			HAL_GPIO_TogglePin(yel_h_GPIO_Port, yel_h_Pin);
			HAL_GPIO_TogglePin(yel_v_GPIO_Port, yel_v_Pin);
			set1(500);
		}
		if (flag3 == 1){
			scan = (scan + 1)%2;
			scan7Seg(scan);
			//set the flag again; then displaying modes
			set3(100);
		}
		break;
	case MAN_GRN:
		updateSegment2Digits(tempGrn, 44);
		if (isButtonNoPressed(0) == 1){

			//Checking the value of all the LED; if it is logical, it can be used; else reset back to the init.
			if (yelDur > grnDur){
				grnDur += yelDur;
			}
			if (redDur < grnDur + yelDur){
				redDur = grnDur + yelDur;
			}
			if (grnDur >= redDur + yelDur){
				grnDur = redDur - yelDur;
			}
			setLedH(ALL);
			setLedV(ALL);
			set7SegH(8);
			set7SegV(8);
			for (int i = 0; i < 4; i++){
				HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin << 1, 0);
			}
			HAL_Delay(3000);
			setLedV(IDLE);
			setLedH(IDLE);
			resetTimer(NONE); //reset all timer;
			manState = IDLE;
			autoState_H = INIT;
			autoState_V = INIT;
			return;
		}

		if (isButtonNoPressed(1) == 1){
			//add the tempRed 1 unit, if tempred > 99 -> 1
			tempGrn = (tempGrn == 99) ? 1 : tempGrn + 1;
//			updateSegment2Digits(tempRed, 2);

		}
		if (isButtonNoPressed(2) == 1){
			//save the config of the light
			grnDur = tempGrn;
		}
		if (flag1 == 1){ //flickering the LEDs light
			HAL_GPIO_TogglePin(grn_h_GPIO_Port, grn_h_Pin);
			HAL_GPIO_TogglePin(grn_v_GPIO_Port, grn_v_Pin);
			set1(500);
		}
		if (flag3 == 1){
			scan = (scan + 1)%2;
			scan7Seg(scan);
			//set the flag again; then displaying modes
			set3(100);
		}
		break;
	default:
		break;
	}
}


