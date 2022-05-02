/**
 * @file main.c
 *
 * @brief 固件库HK32F030MF4P6固件库 CMake版本
 *
 * @author monoliths (monoliths-uni@outlook.com)
 * @version 1.0
 * @date 2022-04-30
 *
 * *********************************************************************************
 *
 * @note version: 1.0
 *
 *
 * @description: 固件库HK32F030MF4P6固件库 CMake版本
 *
 * *********************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

#include <stdio.h>

/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

int main(void)
{
    init_gpio();
    init_usart();
    
    printf("HK32F030MF4P6 INIT");
    fflush(stdout);
    
    /* Infinite loop */
    while (1)
    {
        printf("RUNNING\n");
    }
}

/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE {
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  USART_SendData(USART1, (uint8_t) ch);

  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
  {}

  return ch;
}

#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(char *file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line
       number, tex: printf("Wrong parameters value: file %s on line %d\r\n",
       file, line)
    */
    printf("error in file: %s\n line:%ld\n", file, line);
}

#endif /* USE_FULL_ASSERT */
