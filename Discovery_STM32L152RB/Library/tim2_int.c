#include <stm32l1xx.h>

void SystemInit(){};
void  TIM2_IRQHandler(void)
{
	TIM2->SR=0;	
	GPIOB->ODR ^=3UL << 6;
}


int main()
{
	NVIC_EnableIRQ(TIM2_IRQn);
	
	RCC->AHBENR |=RCC_AHBENR_GPIOBEN;
	RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;
	GPIOB->MODER |=0X5000;
	TIM2->CR1 |=TIM_CR1_ARPE;
	TIM2->CR1 |=TIM_CR1_CEN;
	TIM2->PSC =2000;
	TIM2->ARR =1000;
	TIM2->DIER |=TIM_DIER_UIE;
	TIM2->EGR |=TIM_EGR_UG;

while(1);
}
