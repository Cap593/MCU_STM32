/*
 * ButtonExtInterrupt.c
 *
 *  Created on: Oct 7, 2023
 *      Author: a1081962
 */

#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"
#include "string.h"

#define IRQ_NO_EXTI9_5_PRIORITY		30


void delay(void)
{
	uint32_t i;

	for(i=0;i<500000/2;i++);
}



int main(void)
{

/* EX5 - LED Blinking with External Button Interrupt
*/

	GPIO_Handle_t GpioLED1,BtnLED;

	memset(&GpioLED1,0,sizeof(GpioLED1));
	memset(&BtnLED,0,sizeof(BtnLED));

	GpioLED1.pGPIOx = GPIOD;	// selecting the GPIO port i.e. port D
	GpioLED1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;			// PD12 pin number
	GpioLED1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;					// output mode
	GpioLED1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;				// push pull output type
	GpioLED1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;				// as in push pull , no pull up / down registers are needed
	GpioLED1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	// 1st step : enable the peripheral clock for the GPIO
	GPIO_PeriClockControl(GPIOD,ENABLE);

	// 2nd step : To initialize the peripheral
	GPIO_Init(&GpioLED1);

	// Switch pin configuration
	BtnLED.pGPIOx = GPIOD;											// selecting the GPIO port i.e. port D
	BtnLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;				// PD5 pin number
	BtnLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;				// Falling Edge
	BtnLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;			// as in push pull , no pull up / down registers are needed
	BtnLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_PeriClockControl(GPIOD,ENABLE);


	GPIO_Init(&BtnLED);

	//GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5,IRQ_NO_EXTI9_5_PRIORITY);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5,ENABLE);

	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
	while(1)
		{
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
		};

	return 0;

}

void EXTI9_5_IRQHandler(void)
{

	GPIO_IRQHandling(GPIO_PIN_NO_5);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, ENABLE);
	delay();
}

