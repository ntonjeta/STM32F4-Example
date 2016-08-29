/**
  ******************************************************************************
  * @file i2c.h
  * @author Gruppo 3 Sistemi Embedded
  * @date 02-March-2015
  * @brief This file provides code for the configuration of the I2C instances.
  *
  ******************************************************************************
  *I2C (Inter-Integrated Circuit), pronounced I-squared-C, is a multi-master,
  *I2C multi-slave, single-ended, serial computer bus It is used for attaching
  *I2C lower-speed peripherals to processors on computer motherboards and embedded systems.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __i2c_H
#define __i2c_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

void MX_I2C1_Init(void);
void MX_I2C2_Init(void);

#ifdef __cplusplus
}
#endif
#endif /*__ i2c_H */

/**
  * @}
  */

/**
  * @}
  */

/****************************END OF FILE****/
