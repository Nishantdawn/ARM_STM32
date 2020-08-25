// For receiving 

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;

/*CONFIGURATION OF  USART*/
#define RCC_APB2ENR (uint32_t*) (0x40023800 + 0x20)
#define USART_SR (uint32_t*) (0x40013800+0x00)   // using USART1
#define USART_DR (uint32_t*) (0x40013800+0x04)		//status register
#define USART_CR1 (uint32_t*) (0x40013800+0x0C)		//set transmission,wordlength
#define USART_CR2 (uint32_t*) (0x40013800+0x10)    // based on clock
#define USART_BRR (uint32_t*) (0x40013800+0x08)		//set baud rate


/*for configuring alternate functions*/
#define RCC_AHBENR (uint32_t*) (0x40023800 + 0x00001C)
#define GPIOA_MODER (uint32_t*) (0x40020000 + 0x00)
#define GPIOA_AFRH (uint32_t*) (0x40020000 + 0x24)


 
char a;

void SystemInit(){}
int main (void)
{
	//initilaisation for led
  *RCC_AHBENR = 0x00000001; /* Enable GPIOB clock */
	*RCC_APB2ENR =0x0004000;	/*enable clock for usart*/

	//initialisation for USART1
	*RCC_APB2ENR = (1UL << 14); 
	
	*USART_CR1=0x00002004; 	/*enable usart, set the ue bit and set word length*/
	*USART_CR2=0x00000000;	/*enable no: of stop bit=1*/
	*USART_BRR=0x000000d0;	/*set the baud rate= 9600, over8=0,*/
	*USART_CR1 |= (1UL << 2); // RE bit enable	

	*GPIOA_MODER &= ~(0x0000F000);
	*GPIOA_MODER |= 0x00280000;   // set alternate function A9  to RX and A10 to TX on the convertor

	*GPIOA_AFRH = 0x00000770; // alternate functions das USART1 at pin Pa9 and PA10. 
	*USART_SR &= ~0x0000020;
	

	while(1)
	{	

				
		// CHECK FOR RXNE FLAG  PICK THE DATA
 		if (*USART_SR & 0x0000020)
		a = *USART_DR;		// transfer into a variable
	

	}
}
