#include<stm32l1xx.h>
#include<stdio.h>
#include<string.h>
int main()
{
	char c[10];
	unsigned int i,l;
	//ADC Initialisation
	RCC->CR|=RCC_CR_HSION;
	RCC->AHBENR |=RCC_AHBENR_GPIOBEN |RCC_AHBENR_GPIOAEN;
	RCC->APB2ENR|=RCC_APB2ENR_ADC1EN;// Enable ADC clock
	//RCC->CFGR|=RCC_CFGR_PPRE2_DIV4;
	ADC->CSR|=ADC_CCR_ADCPRE_0;
	GPIOA->MODER|=GPIO_MODER_MODER0;
	ADC1->CR2|=ADC_CR2_ADON;
	while((ADC->CSR&ADC_CSR_ADONS1)==0);
	ADC1->CR1|=ADC_CR1_RES_1;
	
			//GPIO Initialisation

	GPIOB->MODER &=~GPIO_MODER_MODER6;
	GPIOB->MODER |=GPIO_MODER_MODER6_0;
	GPIOB->MODER &=~GPIO_MODER_MODER7; 
	GPIOB->MODER |=GPIO_MODER_MODER7_0;
	GPIOB->OTYPER &= ~(GPIO_OTYPER_IDR_6|GPIO_OTYPER_IDR_7);//
	GPIOB->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR6|GPIO_OSPEEDER_OSPEEDR6);
	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR6|GPIO_PUPDR_PUPDR7);
	
	//UART initialisation
	RCC->APB1ENR|= RCC_APB1ENR_USART2EN;
	RCC->AHBENR|=RCC_AHBENR_GPIOAEN;
	USART2->CR1|=USART_CR1_UE;  //Enable usart
	USART2->CR1 &=~USART_CR1_M;  // Disable M bit
	USART2->CR2 &=~(USART_CR2_STOP); //Set stop bit = 1
	USART2->BRR = 208;// set baud rate=9600
	GPIOA->MODER |=GPIO_MODER_MODER2_1|GPIO_MODER_MODER3_1;//configure pins as alternate functions
	GPIOA->AFR[0] |=0x7700;// Select the alternate function as USART

	USART2->CR1|=USART_CR1_TE;
	
	while(1)
	{
		for(i=0;i<50000;i++);
		ADC1->CR2|=ADC_CR2_SWSTART;
		while((ADC1->SR&ADC_SR_EOC)==0);
		i=ADC1->DR;
		sprintf(c,"%d",i);
		ADC1->SR&=~ADC_SR_EOC;
		for(l=0;l<strlen(c);l++)
		{
		USART2->DR=c[l];
		while((USART2->SR&USART_SR_TC)==0);
		}
		USART2->DR=13;
		while((USART2->SR&USART_SR_TC)==0);
		GPIOB->ODR^=GPIO_ODR_ODR_7;
		
	}
}
void SystemInit(void)
{
}
