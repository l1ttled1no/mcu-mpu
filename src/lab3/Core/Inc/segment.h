/*
 * segment.h
 *
 *  Created on: Nov 11, 2024
 *      Author: l1ttled1no
 */

#ifndef INC_SEGMENT_H_
#define INC_SEGMENT_H_

#include "global.h"

//#define HOR 	0
//#define VER	1

//extern int segState;
extern int segment_buffer[4];

void set7SegH(int);
void set7SegV(int);
void scan7Seg(int);

void updateSegment(int, int, int, int);
void updateSegment2Digits(int, int);

#endif /* INC_SEGMENT_H_ */
