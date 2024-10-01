/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define dot_Pin GPIO_PIN_4
#define dot_GPIO_Port GPIOA
#define testled_Pin GPIO_PIN_5
#define testled_GPIO_Port GPIOA
#define en0_Pin GPIO_PIN_6
#define en0_GPIO_Port GPIOA
#define en1_Pin GPIO_PIN_7
#define en1_GPIO_Port GPIOA
#define aseg_Pin GPIO_PIN_0
#define aseg_GPIO_Port GPIOB
#define bseg_Pin GPIO_PIN_1
#define bseg_GPIO_Port GPIOB
#define cseg_Pin GPIO_PIN_2
#define cseg_GPIO_Port GPIOB
#define en2_Pin GPIO_PIN_8
#define en2_GPIO_Port GPIOA
#define en3_Pin GPIO_PIN_9
#define en3_GPIO_Port GPIOA
#define dseg_Pin GPIO_PIN_3
#define dseg_GPIO_Port GPIOB
#define eseg_Pin GPIO_PIN_4
#define eseg_GPIO_Port GPIOB
#define fseg_Pin GPIO_PIN_5
#define fseg_GPIO_Port GPIOB
#define gseg_Pin GPIO_PIN_6
#define gseg_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
