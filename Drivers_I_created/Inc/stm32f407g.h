/*
 * stm32f407g.h
 *
 *  Created on: Oct 3, 2023
 *      Author: a1081962
 */

#ifndef INC_STM32F407G_H_
#define INC_STM32F407G_H_

#include "stdint.h"

#define __VO volatile

/*
 * Base Address of Flash and SRAM Memories
 */

#define FLASH_BASEADDR							0x08000000U					// main memory
#define SRAM1_BASEADDR							0x20000000U
#define SRAM2_BASEADDR							0x2001C000U
#define ROM_BASEADDR							0x1FFF0000U					// system memory
#define SRAM									SRAM1_BASEADDR

/*
 * AHBx and APBx bus peripheral base address
 */

#define PERIPH_BASEADDR							0x40000000U					// Peripheral base address
#define APB1PERIPH_BASEADDR						PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR						0x40010000U
#define AHB1PERIPH_BASEADDR						0x40020000U
#define AHB2PERIPH_BASEADDR						0x50000000U
#define AHB3PERIPH_BASEADDR						0xA0000000U

/*
 * Addresses of Peripherals handled by AHB1 Bus
 */

#define GPIOA_BASEADDR							(AHB1PERIPH_BASEADDR + 0x0000U)
#define GPIOB_BASEADDR							(AHB1PERIPH_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR							(AHB1PERIPH_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR							(AHB1PERIPH_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR							(AHB1PERIPH_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR							(AHB1PERIPH_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR							(AHB1PERIPH_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR							(AHB1PERIPH_BASEADDR + 0x1C00U)
#define GPIOI_BASEADDR							(AHB1PERIPH_BASEADDR + 0x2000U)

#define RCC_BASEADDR							(AHB1PERIPH_BASEADDR + 0x3800U)

/*
 * Addresses of Peripherals handled by APB1 Bus
 */

#define I2C1_BASEADDR							(APB1PERIPH_BASEADDR + 5400U)
#define I2C2_BASEADDR							(APB1PERIPH_BASEADDR + 5800U)
#define I2C3_BASEADDR							(APB1PERIPH_BASEADDR + 5C00U)

#define SPI2_BASEADDR							(APB1PERIPH_BASEADDR + 3800U)
#define SPI3_BASEADDR							(APB1PERIPH_BASEADDR + 3C00U)

#define USART2_BASEADDR							(APB1PERIPH_BASEADDR + 4400U)
#define USART3_BASEADDR							(APB1PERIPH_BASEADDR + 4800U)
#define UART4_BASEADDR							(APB1PERIPH_BASEADDR + 4C00U)
#define UART5_BASEADDR							(APB1PERIPH_BASEADDR + 5000U)


/*
 * Addresses of Peripherals handled by APB2 Bus
 */

#define EXTI_BASEADDR							(APB2PERIPH_BASEADDR + 3C00U)
#define SPI1_BASEADDR							(APB2PERIPH_BASEADDR + 3000U)
#define SYSCFG_BASEADDR							(APB2PERIPH_BASEADDR + 3800U)
#define USART1_BASEADDR							(APB2PERIPH_BASEADDR + 1000U)
#define USART6_BASEADDR							(APB2PERIPH_BASEADDR + 1400U)

/*
 * Peripheral Register definition structure for GPIO
 *
 * Usage:
 *
 * GPIO_RegDef_t *GPIO_RegDef_Ptr =  (*GPIO_RegDef_t)GPIOA_BASEADDR ; //storing the base address of GPIOA registers
 *
 */

typedef struct
{

	__VO uint32_t MODER;				//GPIO port mode register
	__VO uint32_t OTYPER;			//GPIO port output type register
	__VO uint32_t OSPEEDR;			//GPIO port output speed register
	__VO uint32_t PUPDR;				//GPIO port pull-up/pull-down register
	__VO uint32_t IDR;				//GPIO port input data register
	__VO uint32_t ODR;				//GPIO port output data register
	__VO uint32_t BSRR;				//GPIO port bit set/reset register
	__VO uint32_t LCKR;				//GPIO port configuration lock register
	__VO uint32_t AFR[2];			//AFR[0] : GPIO alternate function low register , AFR[1] : GPIO alternate function high register

}GPIO_RegDef_t;


#define GPIOA						((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB						((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC						((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD						((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE						((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF						((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG						((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define GPIOH						((GPIO_RegDef_t *)GPIOH_BASEADDR)
#define GPIOI						((GPIO_RegDef_t *)GPIOI_BASEADDR)

/*
 * usage : GPIO_RegDef_t *GPIO_RegDef_Ptr =  GPIOA ;
 */



/*
 * Peripheral Register definition structure for RCC (Reset and Clock Control) Register
 *
*/

typedef struct
{
	__VO uint32_t CR;
	__VO uint32_t PLLCFGR;
	__VO uint32_t CFGR;
	__VO uint32_t CIR;
	__VO uint32_t AHB1RSTR;
	__VO uint32_t AHB2RSTR;
	__VO uint32_t AHB3RSTR;
	__VO uint32_t Reserved_0x1C;
	__VO uint32_t APB1RSTR;
	__VO uint32_t APB2RSTR;
	__VO uint32_t Reserved_0x28;
	__VO uint32_t Reserved_0x2C;
	__VO uint32_t AHB1ENR;
	__VO uint32_t AHB2ENR;
	__VO uint32_t AHB3ENR;
	__VO uint32_t Reserved_0x3C;
	__VO uint32_t APB1ENR;
	__VO uint32_t APB2ENR;
	__VO uint32_t Reserved_0x48;
	__VO uint32_t Reserved_0x4C;
	__VO uint32_t AHB1LPENR;
	__VO uint32_t AHB2LPENR;
	__VO uint32_t AHB3LPENR;
	__VO uint32_t Reserved_0x5C;
	__VO uint32_t APB1LPENR;
	__VO uint32_t APB2LPENR;
	__VO uint32_t Reserved_0x68;
	__VO uint32_t Reserved_0x6C;
	__VO uint32_t BDCR;
	__VO uint32_t CSR;
	__VO uint32_t Reserved_0x78;
	__VO uint32_t Reserved_0x7C;
	__VO uint32_t SSCGR;
	__VO uint32_t PLLI2SCFGR;

}RCC_RegDef_t;

#define RCC								((RCC_RegDef_t *)RCC_BASEADDR)

/*
 * Clock enable macro for GPIO Peripheral
 */

#define GPIOA_PCLK_EN()					( RCC->AHB1ENR |= ( 1<<0 ) )
#define GPIOB_PCLK_EN()					( RCC->AHB1ENR |= ( 1<<1 ) )
#define GPIOC_PCLK_EN()					( RCC->AHB1ENR |= ( 1<<2 ) )
#define GPIOD_PCLK_EN()					( RCC->AHB1ENR |= ( 1<<3 ) )
#define GPIOE_PCLK_EN()					( RCC->AHB1ENR |= ( 1<<4 ) )
#define GPIOF_PCLK_EN()					( RCC->AHB1ENR |= ( 1<<5 ) )
#define GPIOG_PCLK_EN()					( RCC->AHB1ENR |= ( 1<<6 ) )
#define GPIOH_PCLK_EN()					( RCC->AHB1ENR |= ( 1<<7 ) )
#define GPIOI_PCLK_EN()					( RCC->AHB1ENR |= ( 1<<8 ) )

/*
 * Clock disable macro for GPIO Peripheral
 */

#define GPIOA_PCLK_DI()					( RCC->AHB1ENR &= ~( 1<<0 ) )
#define GPIOB_PCLK_DI()					( RCC->AHB1ENR &= ~( 1<<1 ) )
#define GPIOC_PCLK_DI()					( RCC->AHB1ENR &= ~( 1<<2 ) )
#define GPIOD_PCLK_DI()					( RCC->AHB1ENR &= ~( 1<<3 ) )
#define GPIOE_PCLK_DI()					( RCC->AHB1ENR &= ~( 1<<4 ) )
#define GPIOF_PCLK_DI()					( RCC->AHB1ENR &= ~( 1<<5 ) )
#define GPIOG_PCLK_DI()					( RCC->AHB1ENR &= ~( 1<<6 ) )
#define GPIOH_PCLK_DI()					( RCC->AHB1ENR &= ~( 1<<7 ) )
#define GPIOI_PCLK_DI()					( RCC->AHB1ENR &= ~( 1<<8 ) )

/*
 * Macro for reseting the GPIO port
 */
#define	GPIOA_REG_RESET()					do{RCC->AHB1RSTR |= (1<<0); RCC->AHB1RSTR &= ~(1<<0);}while(0)
#define	GPIOB_REG_RESET()					do{RCC->AHB1RSTR |= (1<<1); RCC->AHB1RSTR &= ~(1<<1);}while(0)
#define	GPIOC_REG_RESET()					do{RCC->AHB1RSTR |= (1<<2); RCC->AHB1RSTR &= ~(1<<2);}while(0)
#define	GPIOD_REG_RESET()					do{RCC->AHB1RSTR |= (1<<3); RCC->AHB1RSTR &= ~(1<<3);}while(0)
#define	GPIOE_REG_RESET()					do{RCC->AHB1RSTR |= (1<<4); RCC->AHB1RSTR &= ~(1<<4);}while(0)
#define	GPIOF_REG_RESET()					do{RCC->AHB1RSTR |= (1<<5); RCC->AHB1RSTR &= ~(1<<5);}while(0)
#define	GPIOG_REG_RESET()					do{RCC->AHB1RSTR |= (1<<6); RCC->AHB1RSTR &= ~(1<<6);}while(0)
#define	GPIOH_REG_RESET()					do{RCC->AHB1RSTR |= (1<<7); RCC->AHB1RSTR &= ~(1<<7);}while(0)
#define	GPIOI_REG_RESET()					do{RCC->AHB1RSTR |= (1<<8); RCC->AHB1RSTR &= ~(1<<8);}while(0)

//Generic Macros
#define ENABLE							1
#define DISABLE							0
#define SET								ENABLE
#define CLEAR							DISABLE
#define GPIO_PIN_SET					SET
#define GPIO_PIN_CLEAR					CLEAR



#endif /* INC_STM32F407G_H_ */
