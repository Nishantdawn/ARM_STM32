
/*USART  DATA TRANSMISSION */
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;

/*CONFIGURATION OF  USART*/
#define RCC_APB2ENR (uint32_t*) (0x40023800 + 0x20)
#define USART_SR (uint32_t*) (0x40013800+0x00)
#define USART_DR (uint32_t*) (0x40013800+0x04)		//status register
#define USART_CR1 (uint32_t*) (0x40013800+0x0C)		//set transmission,wordlength
#define USART_CR2 (uint32_t*) (0x40013800+0x10)
#define USART_BRR (uint32_t*) (0x40013800+0x08)		//set baud rate


/*for configuring alternate functions*/
#define RCC_AHBENR (uint32_t*) (0x40023800 + 0x00001C)
#define GPIOA_MODER (uint32_t*) (0x40020000 + 0x00)
#define GPIOA_AFRH (uint32_t*) (0x40020000 + 0x24)

unsigned int i;
void SystemInit(){};
int main (void)
{
	//initilaisation for RX Tx Pin
	*RCC_AHBENR = 0x00000001; /* Enable GPIOB and A clock */ 
	*RCC_APB2ENR =0x0004000;	/*enable clock for usart*/ //*RCC_APB2ENR = (1UL << 14); 

	//initialisation for USART1
	*USART_CR1=0x00002008; 	/*enable usart, set the TE bit and set word length*/
	*USART_CR2=0x00000800;	/*enable no: of stop bit=1*/
	*USART_BRR=0x000000D0;	/*set the baud rate= 9600, over8=0,*/

	*GPIOA_MODER &= ~(0x000F0000);
	*GPIOA_MODER |= 0x00080000;
	*GPIOA_AFRH = 0x00000070;	//PA9 Tx and PA10 Rx



while(1)
{
*USART_DR='A';
while((*USART_SR & 0x00000080)==0);//wait untill txe bit and TC bit is set indicating tranmission is complete
for ( i=0; i<50000; i++);
}
}
