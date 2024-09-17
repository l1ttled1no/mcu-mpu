/*
 * header.h
 *
 *  Created on: Sep 15, 2024
 *      Author: l1ttled1no
 */

#ifndef SRC_HEADER_H_
#define SRC_HEADER_H_

#include "main.h"

/*
 Status LED
 */

int led[12] = {0};

//int turnOnLEDAt = 0;

int clkPin = 4;
void turnOnClockSimu(){
	if (clkPin > 15) clkPin = 4;
	if (led[clkPin - 4] < 1){
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0 << clkPin);
		++led[clkPin - 4];
	}
	++clkPin;
}

void setAllClock(){
	int clearClk = 4;
	while (clearClk <= 15){
		if (led[clearClk - 4] == 0){
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0 << clearClk);
			++led[clearClk - 4];
		}
		clearClk++;
	}

}

void clearAllClock(){
	int clearClk = 4;
	while (clearClk <= 15){
		if (led[clearClk - 4] == 1){
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0 << clearClk);
			--led[clearClk - 4];
		}
		clearClk++;
	}
}

void setNumberOnClock(int num){
	if (led[num] < 1){
		++led[num];
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0 << (num + 4));
	}
	else return;
}
void clearNumberOnClock(int num){
	if (led[num] > 0){
		--led[num];
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0 << (num + 4));
	}
	else return;
}
int sec = 0,
	min = 0,
	hrs = 0;
void Clock12h(){
    ++sec;
    if (sec > 59){
        sec = 0;
        ++min;
    }
    if (min > 59){
        min = 0;
        ++hrs;
    }
    if (hrs > 23){
        hrs = 0;
    }
    clearAllClock();
    setNumberOnClock(sec/5);
    setNumberOnClock(min/5);
    if (hrs < 12) setNumberOnClock(hrs);
    else setNumberOnClock(hrs - 12);
}

#endif /* SRC_HEADER_H_ */
