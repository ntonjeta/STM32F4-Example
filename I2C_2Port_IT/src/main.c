/**
  ******************************************************************************
  * @file    main.c
  * @author  Gruppo 3 Sistemi Embedded
  * @date    02-March-2015
  * @brief   main program Body
  ******************************************************************************
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "i2c.h"
#include "gpio.h"
#include "stm32f4_discovery.h"

uint8_t *txBuffer, *rxBuffer;


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);



int main(void)
{



  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
	rxBuffer = (uint8_t*)malloc(sizeof(uint8_t)*1);
	rxBuffer[0]=0x00;
	txBuffer = (uint8_t*)malloc(sizeof(uint8_t)*1);
	txBuffer[0]=0x01;
  MX_GPIO_Init();
  setupBsp();
  MX_I2C1_Init();
  MX_I2C2_Init();

  loop();

  /* Infinite loop */

  while (1)
  {




  }


}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;

  __PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

}

/**
  * @}
  */ 


void loop(void){

	while (BSP_PB_GetState(BUTTON_KEY) != 1)
	  {
	  }

/**	   Wait for User Button release before starting the Communication
**/
	  while (BSP_PB_GetState(BUTTON_KEY) != 0)
	  {
	  }


	  while(HAL_I2C_Slave_Receive_IT(&hi2c2,(uint8_t *)rxBuffer,(uint16_t*) 1) != HAL_OK)
	    {
	      /* Error_Handler() function is called when Timout error occurs.
	         When Acknowledge failure ocucurs (Slave don't acknowledge it's address)
	         Master restarts communication */
	      if (HAL_I2C_GetError(&hi2c2) != HAL_I2C_ERROR_AF)
	      {
	    	//  finalize();
	      }
	    }


	  while(HAL_I2C_Master_Transmit_IT(&hi2c1, (uint16_t)1, (uint8_t*)txBuffer,(uint16_t*) 1)!= HAL_OK)
	    {
	      if (HAL_I2C_GetError(&hi2c1))
	      {
	    	//  finalize();
	      }
	    }



/*
	  BSP_LED_Off(txBuffer[0]);
	  txBuffer[0] = rxBuffer[0];
	  BSP_LED_On(txBuffer[0]);
*/

}

/** Setup Led and Button from BSP
 *
 */

void setupBsp(void){
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
		BSP_LED_Init(LED3);
		BSP_LED_Init(LED4);
		BSP_LED_Init(LED5);
		BSP_LED_Init(LED6);
}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c2)
{

  /* Turn LED6 on: Transfer in reception process is correct */
  BSP_LED_On(LED4);
  BSP_LED_On(LED3);
  BSP_LED_On(LED5);
  BSP_LED_On(LED6);
//	rxBuffer[0]=1;
}

/**
  * @}
*/ 

/*****************************END OF FILE****/
