/**
  ******************************************************************************
  * @file    stm32f4xx_it.h
  * @date    21/04/2015 20:01:31
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void RCC_IRQHandler(void);
void I2C2_ER_IRQHandler(void);
void SysTick_Handler(void);
void I2C1_EV_IRQHandler(void);
void BusFault_Handler(void);
void MemManage_Handler(void);
void I2C1_ER_IRQHandler(void);
void I2C2_EV_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_IT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
