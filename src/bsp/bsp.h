/*
 * bsp.h
 *
 *  Created on: 2 de ene. de 2017
 *      Author: facun
 */

#ifndef BSP_BSP_H_
#define BSP_BSP_H_

#include "stm32f4xx.h"

typedef enum {
				LED_ROJO,
				LED_VERDE,
				LED_NARANJA,
				LED_AZUL
			} leds_TypeDef;


#define LED_NARANJA 		GPIO_PIN_13
#define LED_VERDE 			GPIO_PIN_12
#define LED_ROJO 			GPIO_PIN_14
#define LED_AZUL 			GPIO_PIN_15
#define ALL_LEDS 			LED_AZUL | LED_ROJO | LED_NARANJA | LED_VERDE
#define LEDS_PORT 			GPIOD



typedef enum {
				SW_UP,
				SW_LEFT,
				SW_DOWN,
				SW_RIGHT
			} SW_TypeDef;

#define SWn		4


#define SW_UP_PIN                         	GPIO_PIN_4
#define SW_LEFT_PIN                         GPIO_PIN_5
#define SW_DOWN_PIN                         GPIO_PIN_6
#define SW_RIGHT_PIN                        GPIO_PIN_2
#define ALL_SW 								SW_UP_PIN | SW_LEFT_PIN | SW_DOWN_PIN | SW_RIGHT_PIN
#define SW_PORT 							GPIOE

#define SW_GPIO_CLK_ENABLE()           		__GPIOE_CLK_ENABLE()
#define EXP_BOARD_POT_PIN				   	GPIO_PIN_2
#define EXP_BOARD_POT_PORT                  GPIOC
#define EXP_BOARD_POT_PIN_CLK_ENABLE()      __GPIOC_CLK_ENABLE()
#define EXP_BOARD_POT_ADC_CLK_ENABLE()		__ADC1_CLK_ENABLE()
#define EXP_BOARD_POT_CHANNEL				ADC_CHANNEL_12

void BSP_Init(void);

uint32_t BSP_SW_GetState(SW_TypeDef sw);
uint32_t Get_LED_State(uint16_t led);
uint16_t BSP_ADC_GetValue(void);
void LedToggle(uint16_t led);


void TransmitData(uint8_t *buffer, uint8_t size);

#endif /* BSP_BSP_H_ */
