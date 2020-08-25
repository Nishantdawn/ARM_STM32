#include "stm32l1xx_gpio.h"
#include "stm32l1xx_rcc.h"

	unsigned int t;

	GPIO_InitTypeDef ledInit; // New object ledInit for Structure GPIO_InitTypeDef
	GPIO_InitTypeDef swInit;
void SystemInit(){}
int main() 
	{

 	// enable the GPIOB peripheral clock
 RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE); 
 RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

ledInit.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_6 ;  // configure pins 6 and 7
ledInit.GPIO_OType = GPIO_OType_PP;					//Output type as pushpull
ledInit.GPIO_PuPd = GPIO_PuPd_UP;						// output Pull up
ledInit.GPIO_Speed = GPIO_Speed_400KHz;			// GPIO Speed 
ledInit.GPIO_Mode = GPIO_Mode_OUT; 					// GPIO pin as output
	
swInit.GPIO_Pin = GPIO_Pin_0 ;  // configure A0
swInit.GPIO_OType = GPIO_OType_PP;					// pushpull
swInit.GPIO_PuPd = GPIO_PuPd_UP;					// output Pull up
swInit.GPIO_Speed = GPIO_Speed_400KHz;			// GPIO Speed 
swInit.GPIO_Mode = GPIO_Mode_IN; 					// GPIO pin as output
	
	// initialize the peripheral
	GPIO_Init(GPIOB, &ledInit);	
	GPIO_Init(GPIOA, &swInit);


  	// loop forever
	while(1) {
		
		
		t=GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
		if(t)
		{
    GPIO_SetBits(GPIOB, GPIO_Pin_7);
    GPIO_SetBits(GPIOB, GPIO_Pin_6);  	        
		}
		else
		{
	GPIO_ResetBits(GPIOB, GPIO_Pin_7);
	GPIO_ResetBits(GPIOB, GPIO_Pin_6);	
		}
	}
}
