/**
  ******************************************************************************
  * @file gpio.h
  * @author Gruppo 3 Sistemi Embedded
  * @date 02-March-2015
  * @brief This file contains all the functions prototypes for the gpio
  *
  ******************************************************************************
  *General-purpose input/output (GPIO) is a generic pin on an integrated circuit
  *General-purpose whose behavior, including whether it is an input or output pin,
  *General-purpose can be controlled by the user at run time.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
void MX_GPIO_Init(void);
#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/*****************************END OF FILE****/
