#include "main.h"
#include "shell.h"

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */

int main(void)
{
    HWInit();

    if (!Shell_Init("ch32v307vct6"))
        Error_Handler();


    for(;;)
    {
        int symbol = getchar();

        if (symbol == EOF)
            continue;

        Shell_SendChar((char)symbol);
    }
}

void Error_Handler(void) 
{
    __disable_irq();
    while (1) { }
}
