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
#include "stm32h7xx_hal.h"

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
#define IO_8_Pin GPIO_PIN_1
#define IO_8_GPIO_Port GPIOD
#define SPI2_CS_Pin GPIO_PIN_4
#define SPI2_CS_GPIO_Port GPIOE
#define IO_1_Pin GPIO_PIN_3
#define IO_1_GPIO_Port GPIOE
#define FRAM_CS_Pin GPIO_PIN_13
#define FRAM_CS_GPIO_Port GPIOG
#define IO_9_Pin GPIO_PIN_14
#define IO_9_GPIO_Port GPIOH
#define IO_2_Pin GPIO_PIN_13
#define IO_2_GPIO_Port GPIOC
#define FRAM_WP_Pin GPIO_PIN_5
#define FRAM_WP_GPIO_Port GPIOB
#define IO_10_Pin GPIO_PIN_13
#define IO_10_GPIO_Port GPIOH
#define IO_0_Pin GPIO_PIN_11
#define IO_0_GPIO_Port GPIOA
#define IO_5_Pin GPIO_PIN_5
#define IO_5_GPIO_Port GPIOE
#define LCD_BL_CTRL_Pin GPIO_PIN_15
#define LCD_BL_CTRL_GPIO_Port GPIOG
#define IO_6_Pin GPIO_PIN_6
#define IO_6_GPIO_Port GPIOE
#define DtoACS3_Pin GPIO_PIN_8
#define DtoACS3_GPIO_Port GPIOG
#define UART3_ADDR0_Pin GPIO_PIN_4
#define UART3_ADDR0_GPIO_Port GPIOG
#define TOUCH_INT_Pin GPIO_PIN_2
#define TOUCH_INT_GPIO_Port GPIOG
#define TOUCH_INT_EXTI_IRQn EXTI2_IRQn
#define UART3_ADDR1_Pin GPIO_PIN_3
#define UART3_ADDR1_GPIO_Port GPIOG
#define IO_7_Pin GPIO_PIN_9
#define IO_7_GPIO_Port GPIOF
#define IO_4_Pin GPIO_PIN_0
#define IO_4_GPIO_Port GPIOC
#define LCD_DISP_Pin GPIO_PIN_10
#define LCD_DISP_GPIO_Port GPIOD
#define LED2_Pin GPIO_PIN_2
#define LED2_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_3
#define LED1_GPIO_Port GPIOC
#define IO_3_Pin GPIO_PIN_0
#define IO_3_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
