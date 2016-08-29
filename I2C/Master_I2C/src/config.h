/*
 * config.h
 *
 *  Created on: 02/apr/2015
 *      Author: mariobarbareschi
 */


#include "stm32f4xx_hal.h"
#include "stm32f4_discovery.h"

#ifndef CONFIG_H_
#define CONFIG_H_

#define I2C_ADDRESS        0x0F
#define I2Cx                             I2C1
#define I2Cx_CLK_ENABLE()                __I2C1_CLK_ENABLE()
#define I2Cx_SDA_GPIO_CLK_ENABLE()       __GPIOB_CLK_ENABLE()
#define I2Cx_SCL_GPIO_CLK_ENABLE()       __GPIOB_CLK_ENABLE()

#define I2Cx_FORCE_RESET()               __I2C1_FORCE_RESET()
#define I2Cx_RELEASE_RESET()             __I2C1_RELEASE_RESET()

/* Definition for I2Cx Pins */
#define I2Cx_SCL_PIN                    GPIO_PIN_6
#define I2Cx_SCL_GPIO_PORT              GPIOB
#define I2Cx_SCL_AF                     GPIO_AF4_I2C1
#define I2Cx_SDA_PIN                    GPIO_PIN_9
#define I2Cx_SDA_GPIO_PORT              GPIOB
#define I2Cx_SDA_AF                     GPIO_AF4_I2C1

#define RXBUFFERSIZE 1
#define TXBUFFERSIZE 1

#endif /* CONFIG_H_ */
