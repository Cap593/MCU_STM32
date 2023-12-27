/*
 * 003_LED_Toggle.c
 *
 *  Created on: Oct 5, 2023
 *      Author: a1081962
 */

/*
 *    EX3 - Handling LED with button/switch - onboard
 *    Button - PA0 Pin
 */


#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"
#include "stdio.h"

#define BTN_PRESSED		ENABLE

void delay(void)
{
	uint32_t i;

	for(i=0;i<500000/2;i++);
}

int main(void)
{

	GPIO_Handle_t GpioLED1;
	GPIO_Handle_t BtnLED;

	// LED pin configuration
	GpioLED1.pGPIOx = GPIOD;	// selecting the GPIO port i.e. port D
	GpioLED1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;			// PD12 pin number
	GpioLED1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;					// output mode
	GpioLED1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;				// push pull output type
	GpioLED1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;				// as in push pull , no pull up / down registers are needed
	GpioLED1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;


	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLED1);

	// Switch pin configuration
	GpioLED1.pGPIOx = GPIOA;											// selecting the GPIO port i.e. port D
	GpioLED1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;				// PD12 pin number
	GpioLED1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;				// output mode
	GpioLED1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;			// as in push pull , no pull up / down registers are needed
	GpioLED1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_PeriClockControl(GPIOA,ENABLE);


	GPIO_Init(&BtnLED);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0) == BTN_PRESSED )
		{
			delay();				// debouncing delay
			GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,ENABLE);
		}
		else
		{
			GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,DISABLE);
		}


	}

return 0;
}
