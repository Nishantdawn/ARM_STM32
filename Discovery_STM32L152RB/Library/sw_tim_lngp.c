//#include <stm32l1xx.h>

//void SystemInit(){};
//int main()
//{
//	RCC->AHBENR |=RCC_AHBENR_GPIOBEN;
//	RCC->AHBENR |=RCC_AHBENR_GPIOAEN;
//	GPIOB->MODER |=0X5000;
//	GPIOA->PUPDR |=GPIO_PUPDR_PUPDR0_1;


//while(1){
//	if(GPIOA->IDR & 0x01)
//	GPIOB->ODR ^=3UL << 6;	
//	while(GPIOA->IDR & 0x01);
//}
//}


#include <stm32l1xx.h>
int i;
void SystemInit(){};
void  TIM2_IRQHandler(void)
{
	TIM2->SR=0;	
	i++;
}


int main()
{
	NVIC_EnableIRQ(TIM2_IRQn);
	
	RCC->AHBENR |=RCC_AHBENR_GPIOBEN;
	RCC->AHBENR |=RCC_AHBENR_GPIOAEN;
	RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;
	GPIOB->MODER |=0X5000;
	GPIOA->PUPDR |=GPIO_PUPDR_PUPDR0_1;
	TIM2->CR1 |=TIM_CR1_ARPE;
	TIM2->CR1 |=TIM_CR1_CEN;
	TIM2->PSC =0x20;
	TIM2->ARR =0xFFFF;
	TIM2->DIER |=TIM_DIER_UIE;
	TIM2->EGR |=TIM_EGR_UG;

while(1){
	
	
	if(GPIOA->IDR & 0x01){
	while(GPIOA->IDR & 0x01);
		if(i>2)
			GPIOB->ODR ^=1UL << 6;	
		else
			GPIOB->ODR ^=1UL << 7;	
		i=0;
	}
	
}
}
