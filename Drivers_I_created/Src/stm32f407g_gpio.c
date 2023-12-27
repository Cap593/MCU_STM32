/*
 * stm32f407g.c
 *
 *  Created on: Oct 3, 2023
 *      Author: a1081962
 */

#include "stm32f407g.h"								// MCU specific header file
#include "stm32f407g_gpio.h"						// GPIO driver specific header file


/*********************************************************************************************************************
 * @fn								- 	GPIO_PeriClockControl
 *
 * @brief							-	This API is used for enabling and disabling the peripheral clock for the GPIO
 *
 * @parameter[i/p]					-	GPIOx base address
 * @parameter[i/p]					-	ENABLE/DISABLE Macro
 *
 * return							-	None
 *
 * Note								-	None
 **********************************************************************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DI();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DI();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_DI();
		}
	}
}


/*********************************************************************************************************************
 * @fn								- 	GPIO_Init
 *
 * @brief							-	Initialize the GPIO port and Pin configuration
 *
 * @parameter[i/p]					-	address of the GPIO handle structure
 * @parameter[i/p]					-
 *
 * return							-	None
 *
 * Note								-	None
 **********************************************************************************************************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;

	//1) Configure the mode of GPIO pin

	if((pGPIOHandle->GPIO_PinConfig.GPIO_PinMode) <= GPIO_MODE_ANALOG)
	{
		// Pin mode to the selected pin - Pin Mode takes 2 bit field for each pin
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

		// clearing the register
		(pGPIOHandle->pGPIOx->MODER)  &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		// Moving the pin mode data to the actual register
		pGPIOHandle->pGPIOx->MODER |= temp;
		temp = 0;
	}
	else
	{
		//Interrupt mode
	}


	//2) Configure the speed of the GPIO pin
	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	// clearing the register
	(pGPIOHandle->pGPIOx->OSPEEDR)  &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

	// Moving the pin mode data to the actual register
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	//3) Configure the pupd settings
	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	// clearing the register
	(pGPIOHandle->pGPIOx->PUPDR)  &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	// Moving the pin mode data to the actual register
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	//4) Configure the output type
	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	// clearing the register
	(pGPIOHandle->pGPIOx->OTYPER)  &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	// Moving the pin mode data to the actual register
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	//5) Configure the Alt Functionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		uint32_t temp1, temp2;
		// configure alternate functionality registers

		// for selecting the alternate functionality array, AFR[0] or AFR[1]
		temp1 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8);
		temp2 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8);
		// clearing the register
		(pGPIOHandle->pGPIOx->AFR[temp1])  &= ~(15 << (4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] = (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2 ));
	}

}

/*********************************************************************************************************************
 * @fn								- 	GPIO_DeInit
 *
 * @brief							-	Reset the GPIOx / Deinitialize the GPIOx
 *
 * @parameter[i/p]					-	GPIOx base address
 * @parameter[i/p]					-
 *
 * return							-	None
 *
 * Note								-	None
 **********************************************************************************************************************/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

	if(pGPIOx == GPIOA)
			{
				GPIOA_REG_RESET();
			}
			else if(pGPIOx == GPIOB)
			{
				GPIOB_REG_RESET();
			}
			else if(pGPIOx == GPIOC)
			{
				GPIOC_REG_RESET();
			}
			else if(pGPIOx == GPIOD)
			{
				GPIOD_REG_RESET();
			}
			else if(pGPIOx == GPIOE)
			{
				GPIOE_REG_RESET();
			}
			else if(pGPIOx == GPIOF)
			{
				GPIOF_REG_RESET();
			}
			else if(pGPIOx == GPIOG)
			{
				GPIOG_REG_RESET();
			}
			else if(pGPIOx == GPIOH)
			{
				GPIOH_REG_RESET();
			}
			else if(pGPIOx == GPIOI)
			{
				GPIOI_REG_RESET();
			}

}


/*********************************************************************************************************************
 * @fn								- 	GPIO_ReadFromInputPin
 *
 * @brief							-	Read the Pin status
 *
 * @parameter[i/p]					-	GPIOx base address
 * @parameter[i/p]					-	Pin Number
 *
 * return							-	SET or CLEAR
 *
 * Note								-	None
 **********************************************************************************************************************/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;

	value = (uint8_t)(((pGPIOx->IDR) >> PinNumber) & 0x00000001);

	return value;
}

/*********************************************************************************************************************
 * @fn								- 	GPIO_ReadFromInputPort
 *
 * @brief							-	Read the input value from the GPIO port
 *
 * @parameter[i/p]					-	GPIOx base address
 * @parameter[i/p]					-
 *
 * return							-	input data register value
 *
 * Note								-	None
 **********************************************************************************************************************/
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;

	value = (uint16_t)pGPIOx->IDR;

	return value;
}

/*********************************************************************************************************************
 * @fn								- 	GPIO_WriteToOutputPin
 *
 * @brief							-	Write to GPIO Pin
 *
 * @parameter[i/p]					-	GPIOx base address
 * @parameter[i/p]					-	Pin Number
 * @parameter[i/p]					-	Value to be written
 *
 * return							-	None
 *
 * Note								-	None
 **********************************************************************************************************************/
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber , uint8_t value)
{
	if(value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}

}

/*********************************************************************************************************************
 * @fn								- 	GPIO_WriteToOutputPort
 *
 * @brief							-	Write to GPIO port
 *
 * @parameter[i/p]					-	GPIOx base address
 * @parameter[i/p]					-	value to be written
 *
 * return							-	None
 *
 * Note								-	None
 **********************************************************************************************************************/
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value)
{

	pGPIOx->ODR = value;
}

/*********************************************************************************************************************
 * @fn								- 	GPIO_ToggleOutputPin
 *
 * @brief							-	Toggle bit of GPIO Pin
 *
 * @parameter[i/p]					-	GPIOx base address
 * @parameter[i/p]					-	Pin Number
 *
 * return							-	None
 *
 * Note								-	None
 **********************************************************************************************************************/
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}


/*********************************************************************************************************************
 * @fn								- 	GPIO_IRQConfig
 *
 * @brief							-	Configure the GPIO Interrupt
 *
 * @parameter[i/p]					-	IRQNumber
 * @parameter[i/p]					-	IRQPriority
 * @parameter[i/p]					-	ENABLE or DISABLE
 *
 * return							-	None
 *
 * Note								-	None
 **********************************************************************************************************************/
void GPIO_IRQConfig(uint8_t IRQNumber , uint8_t IRQPriority , uint8_t EnOrDi)
{

}

/*********************************************************************************************************************
 * @fn								- 	GPIO_IRQhandling
 *
 * @brief							-	When Interrupt is triggered this function is called
 *
 * @parameter[i/p]					-	Pin Number
 * @parameter[i/p]					-
 *
 * return							-	None
 *
 * Note								-	None
 **********************************************************************************************************************/
void GPIO_IRQhandling(uint8_t PinNumber)
{

}
