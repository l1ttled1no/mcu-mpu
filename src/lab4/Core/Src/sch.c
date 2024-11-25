/*
 * sch.c
 *
 *  Created on: Nov 25, 2024
 *      Author: l1ttled1no
 */


#include "sch.h"

//Tasks *taskList = {.funcPtr = NULL, .delay = 0, .period = 0, .runme = 0, .taskID = 0, .nextTask = NULL};

uint8_t currentTasks = 0;
uint32_t ERROR_CODE_G = 0;
// uint8_t ERROR_CODE = 0;
Tasks taskList[SCH_MAX_TASKS];

void SCH_Init(void){
	deleteAllTasks();
	currentTasks = 0;
	HAL_GPIO_WritePin(led0_GPIO_Port, led0_Pin, 1);
	HAL_GPIO_WritePin(led1_GPIO_Port, led1_Pin, 1);
	HAL_GPIO_WritePin(led2_GPIO_Port, led2_Pin, 1);
	HAL_GPIO_WritePin(led3_GPIO_Port, led3_Pin, 1);

}

uint32_t SCH_Add_Task(void (*task)(), uint32_t delay, uint32_t period){
//	int taskIdx = 0;
	HAL_GPIO_TogglePin(debug_GPIO_Port, debug_Pin);
//	while (taskIdx < SCH_MAX_TASKS && taskList[taskIdx].isEmpty == false){
//		taskIdx++;
//	}
//	for (taskIdx = 0; taskIdx < SCH_MAX_TASKS; taskIdx++){
//		if (taskList[taskIdx].isEmpty == 1) break;
//	}
	if (currentTasks == SCH_MAX_TASKS){
		ERROR_CODE_G = ERROR_SCH_TOO_MANY_TASKS;
		HAL_GPIO_TogglePin(debug_GPIO_Port, debug_Pin);
		return ERROR_CODE_G;
	}
	taskList[currentTasks].funcPtr = task;
	taskList[currentTasks].delay = delay;
	taskList[currentTasks].period = period;
	taskList[currentTasks].runme = 0;
	taskList[currentTasks].taskID = currentTasks;
	taskList[currentTasks].isEmpty = false;
	taskList[currentTasks].isOneShot = (period == 0);
	currentTasks++;
	return currentTasks;
}
void SCH_Update(void){ //Update the delay/period
	for (int i = 0; i < SCH_MAX_TASKS; i++){
		if (taskList[i].delay > 0 && taskList[i].isEmpty == false){
//			if (i == 1)
			taskList[i].delay--;
			if (taskList[i].delay == 0){
				taskList[i].runme ++;
				taskList[i].delay = taskList[i].period;
			}
		}
	}
}

void SCH_Dispatch_Tasks(void){
	for (int i = 0; i < SCH_MAX_TASKS; i++){
		if (taskList[i].runme > 0 && taskList[i].isEmpty == false){
//			HAL_GPIO_TogglePin(debug_GPIO_Port, debug_Pin);
			taskList[i].runme--;
			(*taskList[i].funcPtr)();

			if (taskList[i].isOneShot == true){
				SCH_Delete_Task(taskList[i].taskID);
			}
		}
	}
}

uint32_t SCH_Delete_Task (uint32_t taskID){
	if (taskID >= SCH_MAX_TASKS){
		ERROR_CODE_G = ERROR_SCH_INVALID_INDEX;
		return ERROR_CODE_G;
	}
	if (taskList[taskID].funcPtr == NULL){
		ERROR_CODE_G = ERROR_SCH_INVALID_INDEX;
		return ERROR_CODE_G;
	}
	if (taskID == SCH_MAX_TASKS - 1){
		taskList[taskID].funcPtr = NULL;
		taskList[taskID].delay = 0;
		taskList[taskID].period = 0;
		taskList[taskID].runme = 0;
		taskList[taskID].taskID = 0;
		taskList[taskID].isEmpty = true;
		taskList[taskID].isOneShot = false;
		currentTasks--;
	} else {
		for (int i = taskID; i < SCH_MAX_TASKS - 1; i++){
			taskList[i] = taskList[i + 1];
		}
		taskList[SCH_MAX_TASKS - 1].funcPtr = NULL;
		taskList[SCH_MAX_TASKS - 1].delay = 0;
		taskList[SCH_MAX_TASKS - 1].period = 0;
		taskList[SCH_MAX_TASKS - 1].runme = 0;
		taskList[SCH_MAX_TASKS - 1].taskID = 0;
		taskList[SCH_MAX_TASKS - 1].isEmpty = true;
		taskList[SCH_MAX_TASKS - 1].isOneShot = false;
		currentTasks--;
	}
	return taskID;
}

void deleteAllTasks(void){
	for (int i = 0; i < SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i);
	}
}
