#include "stm32l1xx_gpio.h"
#include "stm32l1xx_rcc.h"
GPIO_InitTypeDef ledInit; // New object ledInit for Structure GPIO_InitTypeDef
void SystemInit(){}
int main() 
	{

 	// enable the GPIOB peripheral clock
 RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE); 

ledInit.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_6 ;  // configure pins 6 and 7
ledInit.GPIO_OType = GPIO_OType_PP;	//Output type as pushpull
ledInit.GPIO_PuPd = GPIO_PuPd_UP;	// output Pull up
ledInit.GPIO_Speed = GPIO_Speed_400KHz;	// GPIO Speed 
ledInit.GPIO_Mode = GPIO_Mode_OUT; 	// GPIO pin as output

// initialize the peripheral
GPIO_Init(GPIOB, &ledInit);	



// loop forever
	
while(1) {

    GPIO_SetBits(GPIOB, GPIO_Pin_7);
    GPIO_SetBits(GPIOB, GPIO_Pin_6);  	        

}
}
