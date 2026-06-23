#include "ch32v30x_syscalls.h"

int _read(int file, char* ptr, int len) {
    char c;
    if (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
    {
        c = USART_ReceiveData(USART1);
        *ptr++ = c;
        return 1;
    }

    return -1;
}

int _write(int file, char* ptr, int len) {
    (void)file;
    for (int i = 0; i < len; i++) {
        char c = (char)(*ptr++);

        while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
        USART_SendData(USART1, c);
    }

    return len;
}