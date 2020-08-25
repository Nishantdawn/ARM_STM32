typedef unsigned int uint32_t;
#define RCC_AHBENR 	(uint32_t*)   	(0x40023800+0x1C)
#define GPIOB_MODER 	(uint32_t*)   	(0x40020400+0x00)
#define GPIOB_ODR	(uint32_t*)	(0x40020400+0x14)

void SystemInit(void){


}

int main(void)
{ 	
	*RCC_AHBENR = 0x00000002; 	// clock enable 
		
	*GPIOB_MODER = 0x00005000;	// General Purpose Output
	
	*GPIOB_ODR = 0x000000C0;     	// turn both LED on

while (1){}

}
