/**
  ******************************************************************************
  * @file gpio.c
  * @author Gruppo 3 Sistemi Embedded
  * @date 02-March-2015
  * @brief This file provides code for the configuration of all used GPIO pins.
  *
  ******************************************************************************
  *General-purpose input/output (GPIO) is a generic pin on an integrated circuit
  *General-purpose whose behavior, including whether it is an input or output pin,
  *General-purpose can be controlled by the user at run time.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/

/** Pinout Configuration
*/
void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __GPIOB_CLK_ENABLE();

}

/**
  * @}
  */

/**
  * @}
  */

/*****************************END OF FILE****/
