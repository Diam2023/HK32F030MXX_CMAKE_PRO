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

int main(void)
{
    printf("HK32F030MF4P6 INIT");
    fflush(stdout);
    /* Infinite loop */
    while (1)
    {
        printf("RUNNING\n");
    }
}

#ifdef __GNUC__  // GNU编译器

/**
 * @brief GNU编译期下的重定向printf函数
 * @param  fd               文件指针
 * @param  pBuffer          buffer
 * @param  size             字符串大小
 * @return int
 */
int _write(int fd, char *pBuffer, int size)
{
    // 如果printf函数最后不添加"\n"，信息不会打印出来，需要添加fflush(stdout);
    while (size--)
    {
        while ((USART1->ISR & USART_ISR_TXE) == 0)
            ;
        USART1->TDR = *(uint8_t *)pBuffer++;
    }
    return size;
}

#endif  // __GNUC__

#ifndef __GNUC__

/**
 * @brief KEIL
 * @param  ch               desc
 * @param  f                desc
 * @return int
 */
int fputc(int ch, FILE *f)
{
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
    {
    }
    while ((USART1->ISR & USART_ISR_TXE) == 0)
        ;
    USART1->TDR = (uint8_t)ch;
    return (ch);
}

#endif  // !__GNUC__

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
