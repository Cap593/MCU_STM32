/*
 * 004_LED_Toggle_ExtButton.c
 *
 *  Created on: Oct 5, 2023
 *      Author: a1081962
 */


// toggle LED using ext button

#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"
#include "stdio.h"

#define BTN_PRESSED		DISABLE

void delay(void)
{
	uint32_t i;

	for(i=0;i<500000/2;i++);
}

int main(void)
{

	GPIO_Handle_t GpioLED1;			// PA12
	GPIO_Handle_t BtnLED;			// PB12

	// LED pin configuration
	GpioLED1.pGPIOx = GPIOA;	// selecting the GPIO port i.e. port D
	GpioLED1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1;
	GpioLED1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;					// output mode
	GpioLED1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;				// push pull output type
	GpioLED1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;				// as in push pull , no pull up / down registers are needed
	GpioLED1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;


	GPIO_PeriClockControl(GPIOA,ENABLE);

	GPIO_Init(&GpioLED1);

	// Switch pin configuration
	BtnLED.pGPIOx = GPIOB;											// selecting the GPIO port i.e. port D
	BtnLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;				// PD12 pin number
	BtnLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;				// output mode
	BtnLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;			// as in push pull , no pull up / down registers are needed
	BtnLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_PeriClockControl(GPIOB,ENABLE);


	GPIO_Init(&BtnLED);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOB,GPIO_PIN_NO_12) == BTN_PRESSED )
		{
			delay();				// debouncing delay
			GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_1,ENABLE);
		}
		else
		{
			GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_1,DISABLE);
		}


	}

return 0;
}
