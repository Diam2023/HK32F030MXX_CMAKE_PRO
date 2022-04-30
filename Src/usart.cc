#include "usart.h"

void init_usart(void)
{
	USART_InitTypeDef usart1;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	usart1.USART_BaudRate = 115200;
	usart1.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usart1.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	usart1.USART_Parity = USART_Parity_No;
	usart1.USART_StopBits = USART_StopBits_1;
	usart1.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &usart1);
	USART_Cmd(USART1, ENABLE);
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}
