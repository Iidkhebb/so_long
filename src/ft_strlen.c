#include "so_long.h"

int ft_strlen2(char *str)
{
    int i = 0;

    while (str[i])
    {
        i++;
    }
    return(i); 
}