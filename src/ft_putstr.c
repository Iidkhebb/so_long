#include "so_long.h"

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str, 1);
        i++;
    }
}