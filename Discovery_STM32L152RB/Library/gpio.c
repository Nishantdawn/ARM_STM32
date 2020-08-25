#include <stm32l1xx.h>

void SystemInit(){};
int main()
{
	RCC->AHBENR |=RCC_AHBENR_GPIOBEN;
	GPIOB->MODER |=0X5000;
	
GPIOB->ODR ^=3UL << 6;	

while(1){

	
}
}
