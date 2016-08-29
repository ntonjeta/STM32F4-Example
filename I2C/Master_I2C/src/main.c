//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>
#include "diag/Trace.h"

#include "config.h"
// ----------------------------------------------------------------------------
//
// Standalone STM32F4 empty sample (trace via NONE).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the NONE output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

I2C_HandleTypeDef I2cHandle;

uint8_t *txBuffer, *rxBuffer;

void setup();
void loop();
uint8_t isLoop();
void finalize();

int main(int argc, char* argv[]){
	setup();
	while(isLoop()){
		loop();
	}
	finalize();
}

void setup(){

	  RCC_ClkInitTypeDef RCC_ClkInitStruct;
	  RCC_OscInitTypeDef RCC_OscInitStruct;

	  /* Enable Power Control clock */
	  __PWR_CLK_ENABLE();

	  /* The voltage scaling allows optimizing the power consumption when the device is
	     clocked below the maximum system frequency, to update the voltage scaling value
	     regarding system frequency refer to product datasheet.  */
	  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	  /* Enable HSE Oscillator and activate PLL with HSE as source */
	  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	  RCC_OscInitStruct.PLL.PLLM = 8;
	  RCC_OscInitStruct.PLL.PLLN = 336;
	  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	  RCC_OscInitStruct.PLL.PLLQ = 7;
	  HAL_RCC_OscConfig(&RCC_OscInitStruct);

	  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	     clocks dividers */
	  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

	  I2cHandle.Instance             = I2Cx;

	  I2cHandle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	  I2cHandle.Init.ClockSpeed      = 400000;
	  I2cHandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLED;
	  I2cHandle.Init.DutyCycle       = I2C_DUTYCYCLE_16_9;
	  I2cHandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLED;
	  I2cHandle.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLED;
	  I2cHandle.Init.OwnAddress1     = I2C_ADDRESS;
	  I2cHandle.Init.OwnAddress2     = 0xFE;

	  if(HAL_I2C_Init(&I2cHandle) != HAL_OK)
	    {
	      /* Initialization Error */
	      finalize();
	    }

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	BSP_LED_Init(LED3);
	BSP_LED_Init(LED4);
	BSP_LED_Init(LED5);
	BSP_LED_Init(LED6);


	txBuffer = (uint8_t*)malloc(sizeof(uint8_t)*TXBUFFERSIZE);
	rxBuffer = (uint8_t*)malloc(sizeof(uint8_t)*RXBUFFERSIZE);

	txBuffer[0]=0x00;
	rxBuffer[0]=0x00;
}

void loop(){
	while (BSP_PB_GetState(BUTTON_KEY) != 1)
	  {
	  }

	  /* Wait for User Button release before starting the Communication */
	  while (BSP_PB_GetState(BUTTON_KEY) != 0)
	  {
	  }

	  while(HAL_I2C_Master_Transmit(&I2cHandle, (uint16_t)I2C_ADDRESS, (uint8_t*)txBuffer, TXBUFFERSIZE, 10000)!= HAL_OK)
	    {
	      if (HAL_I2C_GetError(&I2cHandle) != HAL_I2C_ERROR_AF)
	      {
	    	  finalize();
	      }
	    }

	  while(HAL_I2C_Master_Receive(&I2cHandle, (uint16_t)I2C_ADDRESS, (uint8_t *)rxBuffer, RXBUFFERSIZE, 10000) != HAL_OK)
	    {
	      /* Error_Handler() function is called when Timout error occurs.
	         When Acknowledge failure ocucurs (Slave don't acknowledge it's address)
	         Master restarts communication */
	      if (HAL_I2C_GetError(&I2cHandle) != HAL_I2C_ERROR_AF)
	      {
	    	  finalize();
	      }
	    }

	  BSP_LED_Off(txBuffer[0]);
	  txBuffer[0] = rxBuffer[0];
	  BSP_LED_On(txBuffer[0]);

}

uint8_t isLoop(){
	return 1;
}

void finalize(){
	HAL_I2C_DeInit(I2cHandle);
	free(rxBuffer);
	free(txBuffer);
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
