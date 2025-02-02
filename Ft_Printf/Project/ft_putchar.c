
#include "ft_printf.h"

void ft_putchar(char c, int *x)
{
    write(1, &c, 1);
    (*x)++;
}