/*
 * stm32f407g_gpio.h
 *
 *  Created on: Oct 3, 2023
 *      Author: a1081962
 */

#ifndef INC_STM32F407G_GPIO_H_
#define INC_STM32F407G_GPIO_H_

/*
 * This is a configuration structure for the GPIO pin
 */

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t	GPIO_PinMode;
	uint8_t	GPIO_PinSpeed;
	uint8_t	GPIO_PinPuPdControl;
	uint8_t	GPIO_PinOPType;
	uint8_t	GPIO_PinAltFunMode;

}GPIO_PinConfig_t;

/*
 * This is a handle structure for the GPIO
 */

typedef struct
{
	GPIO_RegDef_t *pGPIOx;						// this pointer holds the base address of the GPIO port to which the pin belong
	GPIO_PinConfig_t GPIO_PinConfig;			// holds the GPIO pin configuration settings


}GPIO_Handle_t;

/*
 * GPIO PIN Modes
 */

#define GPIO_MODE_IN							0
#define GPIO_MODE_OUT							1
#define GPIO_MODE_ALTFN							2
#define GPIO_MODE_ANALOG						3
#define GPIO_MODE_IT_FT							4
#define GPIO_MODE_IT_RT							5
#define GPIO_MODE_IT_RFT						6


/*
 * GPIO Pin Possible output types
 */

#define GPIO_OP_TYPE_PP							0
#define GPIO_OP_TYPE_OD							1

/*
 * GPIO Output possible speeds
 */
#define GPIO_SPEED_LOW							0
#define GPIO_SPEED_MEDIUM						1
#define GPIO_SPEED_FAST							2
#define GPIO_SPEED_HIGH							3

/*
 * GPIO Output possible speeds
 */
#define GPIO_NO_PUPD							0
#define GPIO_PIN_PU								1
#define GPIO_PIN_PD								2

/*
 * GPIO PIN Numbers
 */
#define GPIO_PIN_NUMBER_0						0
#define GPIO_PIN_NUMBER_1						1
#define GPIO_PIN_NUMBER_2						2
#define GPIO_PIN_NUMBER_3						3
#define GPIO_PIN_NUMBER_4						4
#define GPIO_PIN_NUMBER_5						5
#define GPIO_PIN_NUMBER_6						6
#define GPIO_PIN_NUMBER_7						7
#define GPIO_PIN_NUMBER_8						8
#define GPIO_PIN_NUMBER_9						9
#define GPIO_PIN_NUMBER_10						10
#define GPIO_PIN_NUMBER_11						11
#define GPIO_PIN_NUMBER_12						12
#define GPIO_PIN_NUMBER_13						13
#define GPIO_PIN_NUMBER_14						14
#define GPIO_PIN_NUMBER_15						15


/********************************************************************************************
 * API supported by this driver
 *********************************************************************************************/

/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi);

/*
 * Init and Deninit
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Read and Write Operations
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber , uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * Interrupt supports
 */

void GPIO_IRQConfig(uint8_t IRQNumber , uint8_t IRQPriority , uint8_t EnOrDi);
void GPIO_IRQhandling(uint8_t PinNumber);

#endif /* INC_STM32F407G_GPIO_H_ */


