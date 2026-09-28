/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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

/* USER CODE BEGIN PV */
uint8_t state_ex5 = 0;
uint8_t timer_ex5 = 0;
uint8_t countdown_ex5 = 3;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int num)
{
    // Turn off all segments first
    HAL_GPIO_WritePin(GPIOB,
                      GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 |
                      GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 |
                      GPIO_PIN_6,
                      GPIO_PIN_SET);

    switch (num)
    {
        case 0:
            // a b c d e f
            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 |
                              GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5,
                              GPIO_PIN_RESET);
            break;

        case 1:
            // b c
            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_1 | GPIO_PIN_2,
                              GPIO_PIN_RESET);
            break;

        case 2:
            // a b d e g
            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 | GPIO_PIN_1 |
                              GPIO_PIN_3 | GPIO_PIN_4 |
                              GPIO_PIN_6,
                              GPIO_PIN_RESET);
            break;

        case 3:
            // a b c d g
            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 | GPIO_PIN_1 |
                              GPIO_PIN_2 | GPIO_PIN_3 |
                              GPIO_PIN_6,
                              GPIO_PIN_RESET);
            break;

        case 4:
            // b c f g
            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_1 | GPIO_PIN_2 |
                              GPIO_PIN_5 | GPIO_PIN_6,
                              GPIO_PIN_RESET);
            break;

        case 5:
            // a c d f g
            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 | GPIO_PIN_2 |
                              GPIO_PIN_3 | GPIO_PIN_5 |
                              GPIO_PIN_6,
                              GPIO_PIN_RESET);
            break;

        case 6:
            // a c d e f g
            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 | GPIO_PIN_2 |
                              GPIO_PIN_3 | GPIO_PIN_4 |
                              GPIO_PIN_5 | GPIO_PIN_6,
                              GPIO_PIN_RESET);
            break;

        case 7:
            // a b c
            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 | GPIO_PIN_1 |
                              GPIO_PIN_2,
                              GPIO_PIN_RESET);
            break;

        case 8:
            // a b c d e f g
            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 | GPIO_PIN_1 |
                              GPIO_PIN_2 | GPIO_PIN_3 |
                              GPIO_PIN_4 | GPIO_PIN_5 |
                              GPIO_PIN_6,
                              GPIO_PIN_RESET);
            break;

        case 9:
            // a b c d f g
            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 | GPIO_PIN_1 |
                              GPIO_PIN_2 | GPIO_PIN_3 |
                              GPIO_PIN_5 | GPIO_PIN_6,
                              GPIO_PIN_RESET);
            break;

        default:
            break;
    }
}


void setTrafficState(uint8_t state)
{
    switch (state)
    {
        case 0:
            // Group 1: GREEN
            HAL_GPIO_WritePin(LED_RED1_GPIO_Port,
                              LED_RED1_Pin,
                              GPIO_PIN_RESET);

            HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port,
                              LED_YELLOW1_Pin,
                              GPIO_PIN_RESET);

            HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port,
                              LED_GREEN1_Pin,
                              GPIO_PIN_SET);

            // Group 2: RED
            HAL_GPIO_WritePin(LED_RED2_GPIO_Port,
                              LED_RED2_Pin,
                              GPIO_PIN_SET);

            HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port,
                              LED_YELLOW2_Pin,
                              GPIO_PIN_RESET);

            HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port,
                              LED_GREEN2_Pin,
                              GPIO_PIN_RESET);
            break;


        case 1:
            // Group 1: YELLOW
            HAL_GPIO_WritePin(LED_RED1_GPIO_Port,
                              LED_RED1_Pin,
                              GPIO_PIN_RESET);

            HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port,
                              LED_YELLOW1_Pin,
                              GPIO_PIN_SET);

            HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port,
                              LED_GREEN1_Pin,
                              GPIO_PIN_RESET);

            // Group 2: RED
            HAL_GPIO_WritePin(LED_RED2_GPIO_Port,
                              LED_RED2_Pin,
                              GPIO_PIN_SET);

            HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port,
                              LED_YELLOW2_Pin,
                              GPIO_PIN_RESET);

            HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port,
                              LED_GREEN2_Pin,
                              GPIO_PIN_RESET);
            break;


        case 2:
            // Group 1: RED
            HAL_GPIO_WritePin(LED_RED1_GPIO_Port,
                              LED_RED1_Pin,
                              GPIO_PIN_SET);

            HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port,
                              LED_YELLOW1_Pin,
                              GPIO_PIN_RESET);

            HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port,
                              LED_GREEN1_Pin,
                              GPIO_PIN_RESET);

            // Group 2: GREEN
            HAL_GPIO_WritePin(LED_RED2_GPIO_Port,
                              LED_RED2_Pin,
                              GPIO_PIN_RESET);

            HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port,
                              LED_YELLOW2_Pin,
                              GPIO_PIN_RESET);

            HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port,
                              LED_GREEN2_Pin,
                              GPIO_PIN_SET);
            break;


        case 3:
            // Group 1: RED
            HAL_GPIO_WritePin(LED_RED1_GPIO_Port,
                              LED_RED1_Pin,
                              GPIO_PIN_SET);

            HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port,
                              LED_YELLOW1_Pin,
                              GPIO_PIN_RESET);

            HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port,
                              LED_GREEN1_Pin,
                              GPIO_PIN_RESET);

            // Group 2: YELLOW
            HAL_GPIO_WritePin(LED_RED2_GPIO_Port,
                              LED_RED2_Pin,
                              GPIO_PIN_RESET);

            HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port,
                              LED_YELLOW2_Pin,
                              GPIO_PIN_SET);

            HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port,
                              LED_GREEN2_Pin,
                              GPIO_PIN_RESET);
            break;
    }
}


void EX5_RUN(void)
{
    timer_ex5++;

    switch (state_ex5)
    {
        case 0:
            // Group 1 GREEN - 3 seconds

            if (timer_ex5 >= 3)
            {
                state_ex5 = 1;
                timer_ex5 = 0;

                setTrafficState(state_ex5);

                // Group 1 YELLOW starts at 2
                countdown_ex5 = 2;
            }
            else
            {
                countdown_ex5--;
            }
            break;


        case 1:
            // Group 1 YELLOW - 2 seconds

            if (timer_ex5 >= 2)
            {
                state_ex5 = 2;
                timer_ex5 = 0;

                setTrafficState(state_ex5);

                // Group 1 RED total time = 5 seconds
                countdown_ex5 = 5;
            }
            else
            {
                countdown_ex5--;
            }
            break;


        case 2:
            // Group 1 RED
            // Group 2 GREEN - first 3 seconds

            countdown_ex5--;

            if (timer_ex5 >= 3)
            {
                state_ex5 = 3;
                timer_ex5 = 0;

                setTrafficState(state_ex5);

                // Do NOT reset countdown here
                // RED1 continues: 2 -> 1
            }
            break;


        case 3:
            // Group 1 RED
            // Group 2 YELLOW - last 2 seconds

            if (timer_ex5 >= 2)
            {
                state_ex5 = 0;
                timer_ex5 = 0;

                setTrafficState(state_ex5);

                // New GREEN cycle
                countdown_ex5 = 3;
            }
            else
            {
                countdown_ex5--;
            }
            break;
    }

    display7SEG(countdown_ex5);
}

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
  /* USER CODE BEGIN 2 */
  setTrafficState(state_ex5);
  display7SEG(countdown_ex5);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  HAL_Delay(1000);
	      EX5_RUN();
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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_YELLOW1_Pin|LED_YELLOW2_Pin|LED_GREEN2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin|LED_RED2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG_A_Pin|SEG_B_Pin|SEG_C_Pin|SEG_D_Pin
                          |SEG_E_Pin|SEG_F_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED1_Pin LED_YELLOW1_Pin LED_GREEN1_Pin LED_RED2_Pin
                           LED_YELLOW2_Pin LED_GREEN2_Pin */
  GPIO_InitStruct.Pin = LED_RED1_Pin|LED_YELLOW1_Pin|LED_GREEN1_Pin|LED_RED2_Pin
                          |LED_YELLOW2_Pin|LED_GREEN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_A_Pin SEG_B_Pin SEG_C_Pin SEG_D_Pin
                           SEG_E_Pin SEG_F_Pin SEG_G_Pin */
  GPIO_InitStruct.Pin = SEG_A_Pin|SEG_B_Pin|SEG_C_Pin|SEG_D_Pin
                          |SEG_E_Pin|SEG_F_Pin|SEG_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
