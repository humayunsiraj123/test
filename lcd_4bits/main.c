/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 I2C_HandleTypeDef hi2c1;


/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);

void led_deinit(void);
void led_init(void);
void SEND_TO_LCD(char DATA,int RS);
void LCD_SEND_CMD(char CMD);
void LCD_SEND_DATA(char DATA);
void LCD_CLEAR(void);
void SET_CURSOR(int row,int col);
void LCD_INIT(void);
void LCD_SEND_STRING(char *str);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */

 	HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();


  /* USER CODE BEGIN 2 */
led_init();
HAL_Delay(2000);
led_deinit();

LCD_INIT();
SET_CURSOR(0,0);

LCD_SEND_STRING("HELLO WORLD");
HAL_Delay(5000);
LCD_CLEAR();
//SETCURSOR(0,0);
LCD_SEND_STRING("STM 32 BOARD");
HAL_Delay(500);
LCD_CLEAR();

SET_CURSOR(1,0);
LCD_SEND_STRING("TESTING LCH");


HAL_Delay(5000);

SET_CURSOR(0,5);

LCD_SEND_STRING("HEELO");
HAL_Delay(5000);
LCD_CLEAR();

LCD_SEND_DATA("A");

SET_CURSOR(1, 5);



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
LCD_SEND_DATA("&");
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x2000090E;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA1 PA2 PA3 PA4
                           PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */


void led_init(void)
{HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,1);

	}
void led_deinit(void)
{HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,0);
	}

void SEND_TO_LCD(char DATA,int RS)
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,RS);


	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,((DATA>>0)&0x01));
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,((DATA>>1)&0x01));
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,((DATA>>2)&0x01));
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,((DATA>>3)&0x01));

	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,1);
	HAL_Delay(50);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,0);
	HAL_Delay(50);


	}

void LCD_SEND_CMD(char CMD){
	char datatosend;
	datatosend=((CMD>>4)&0x0f);
	SEND_TO_LCD(datatosend,0);

	datatosend=((CMD)&0x0f);
	SEND_TO_LCD(datatosend,0);
}


void LCD_SEND_DATA(char DATA){


	char datatosend;
	datatosend=((DATA>>4)&0x0f);
	SEND_TO_LCD(datatosend,1);

	datatosend=((DATA)&0x0f);
	SEND_TO_LCD(datatosend,1);
}



void LCD_CLEAR(void){
	LCD_SEND_CMD(0x01);
	HAL_Delay(2);
}

void SET_CURSOR(int row,int col){

	switch(row){
	case(0):
			col|=0x80;
			break;
	case(1):
			col|=0xC0;
			break;

	case(2):
			col|=0xC0;
			break;
	case(3):
			col|=0xC0;
			break;


	}

	LCD_SEND_CMD(col);
}

void LCD_INIT(void){

	HAL_Delay(50);
	LCD_SEND_CMD(0x30);

	HAL_Delay(5);
	LCD_SEND_CMD(0x30);
	HAL_Delay(1);
	LCD_SEND_CMD(0x30);
	HAL_Delay(10);
	LCD_SEND_CMD(0x30);
	HAL_Delay(10);
	LCD_SEND_CMD(0x28); //4bit mode

	//DISPLAY init
	LCD_SEND_CMD(0x28);
	HAL_Delay(1);

	LCD_SEND_CMD(0x08);
	HAL_Delay(1);

	LCD_SEND_CMD(0x01);
	HAL_Delay(2);

	LCD_SEND_CMD(0x06);
	HAL_Delay(10);

	LCD_SEND_CMD(0x0C);
	HAL_Delay(10);

}

void LCD_SEND_STRING(char *str)
{
	while(*str) LCD_SEND_DATA(*str++);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
