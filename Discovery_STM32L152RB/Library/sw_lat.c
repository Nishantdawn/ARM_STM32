#include <stm32l1xx.h>

void SystemInit(){};
int main()
{
	RCC->AHBENR |=RCC_AHBENR_GPIOBEN;
	RCC->AHBENR |=RCC_AHBENR_GPIOAEN;
	GPIOB->MODER |=0X5000;
	GPIOA->PUPDR |=GPIO_PUPDR_PUPDR0_1;


while(1){
	if(GPIOA->IDR & 0x01)
	{
	GPIOB->ODR ^=3UL << 6;	
	while(GPIOA->IDR & 0x01);
	}
}
}
