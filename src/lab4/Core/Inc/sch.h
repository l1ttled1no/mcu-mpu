/*
 * sched.h
 *
 *  Created on: Nov 14, 2024
 *      Author: l1ttled1no
 */

#ifndef INC_SCH_H_
#define INC_SCH_H_
#include "main.h"
#include "stdint.h"
#include "stdbool.h"
#define SCH_MAX_TASKS 10
// ERROR DEFINE

#define ERROR_SCH_INVALID_INDEX								101
#define ERROR_SCH_TOO_MANY_TASKS 							102
#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK 					103
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER 	104
#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START 			105
#define ERROR_SCH_LOST_SLAVE 								106
#define ERROR_SCH_CAN_BUS_ERROR 							107
#define ERROR_I2C_WRITE_BYTE_AT24C64 						108

typedef struct Tasks {
	void (*funcPtr)(void);
	uint32_t 	delay;
	uint32_t 	period;
	uint32_t 	runme;
	uint32_t 	taskID;
	bool		isEmpty;
	bool 		isOneShot;
} Tasks;
// Tasks *taskList = {.funcPtr = NULL, .delay = 0, .period = 0, .runme = 0, .taskID = 0, .nextTask = NULL};

void SCH_Init(void);
uint32_t SCH_Add_Task(void (*task)(void), uint32_t delay, uint32_t period);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Delete_Task(uint32_t taskID);

void deleteAllTasks(void);
#endif /* INC_SCH_H_ */
