#include "gpio.h"

void init_gpio()
{
    // usart
    GPIO_InitTypeDef usart_gpio;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);
    // PA3 TXD
    usart_gpio.GPIO_Mode = GPIO_Mode_AF;
    usart_gpio.GPIO_OType = GPIO_OType_PP;
    usart_gpio.GPIO_Pin = GPIO_Pin_3;
    usart_gpio.GPIO_PuPd = GPIO_PuPd_NOPULL;
    usart_gpio.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOA, &usart_gpio);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1);

    // PD6 RXD
    usart_gpio.GPIO_Pin = GPIO_Pin_6;
    GPIO_Init(GPIOD, &usart_gpio);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource6, GPIO_AF_1);
}
