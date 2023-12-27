/*
 * 001_LED_Toggle.c
 *
 *  Created on: Oct 4, 2023
 *      Author: a1081962
 */


#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"
#include "stdio.h"

void delay(void)
{
	uint32_t i;

	for(i=0;i<500000;i++);
}

int main(void)
{

/* EX1 - LED Blinking with push pull configuration
*/

	GPIO_Handle_t GpioLED1;

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

	while(1)
	{
		//3rd Step :Toggling the PIN PD12
		printf("Hello\n");
		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
//		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_13);
//		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_14);
//		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_15);
		delay();
	}

return 0;
}
