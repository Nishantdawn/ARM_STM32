// tim3 polling with flag

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
/* initializing PORT B for led    */
#define RCC_AHBENR (uint32_t*) (0x40023800 + 0x00001C)
#define RCC_APB1ENR (uint32_t*) (0x40023800 + 0x24)    
#define RCC_CR (uint32_t*) (0x40023800 + 0x00)
#define RCC_CFGR (uint32_t*) (0x40023800 + 0x08)

#define GPIOB_MODER (uint32_t*) (0x40020400 + 0x00)
#define GPIOB_OTYPER (uint32_t*) (0x40020400 + 0x04)
#define GPIOB_OSPEEDR (uint32_t*) (0x40020400 + 0x08)
#define GPIOB_PUPDR (uint32_t*) (0x40020400 + 0x0C)
#define GPIOB_BSRRL (uint32_t*) (0x40020400 + 0x18)
#define GPIOB_ODR (uint32_t*) (0x40020400 + 0x14)
/* initializing Timmer 3   */
#define TIM3_CR1 (uint32_t*) (0x40000400 + 0x00)
#define TIM3_CNT (uint32_t*) (0x40000400 + 0x24)
#define TIM3_ARR (uint32_t*) (0x40000400 + 0x2C)
#define TIM3_PSC (uint32_t*) (0x40000400 + 0x28)
#define TIM3_DIER (uint16_t*) (0x40000400 + 0x0C)
#define TIM3_SR (uint32_t*) (0x40000400 + 0x10)
#define TIM3_EGR (uint32_t*) (0x40000400 + 0x14)
//void SystemInit(){}

int main (void)
{
*RCC_AHBENR =  0x00000003 ;                 /* Enable GPIOB  */
*RCC_APB1ENR = 0x00000002 ;                /* Selecting TIM3    */
*RCC_CR         =    0x00000003 ;
*RCC_CFGR        =    0x00000001;
*GPIOB_MODER   &=  ~(0x0000F000);
*GPIOB_MODER   |=   (0x00005000);             /* General purpose outputmode*/
*GPIOB_OTYPER  &=  ~(0x000000C0);             /* Output push-pull*/
*GPIOB_OSPEEDR &=  ~(0x0000F000);
*GPIOB_OSPEEDR |=   (0x00005000);             /* 2 MHz Low speed */
*GPIOB_PUPDR   &=  ~(0x0000F000);
*TIM3_CR1 = 0x0091;//---- for interupt 0x0091
*TIM3_DIER = 0X0141;//-- ENABLE TRIGGER INT AND IE
*TIM3_PSC = 0x00ff;
*TIM3_ARR = 0xffff;        // Auto Reload register
*TIM3_EGR =    0X0001;


while(1)
{
while(*TIM3_SR & 0X01)
{
*TIM3_EGR =    0X0001;
*TIM3_SR    &= ~(0XFF);
*GPIOB_ODR = ~(*GPIOB_ODR );    /* toggle led */
}
}
}

