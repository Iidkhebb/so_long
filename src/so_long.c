#include "so_long.h"

int map_extention_validator(char *map_name)
{
    int i = 0;
    while (map_name[i] != '.')
    {
        i++;
    }
    if (map_name[i+1] != 'b')
    {
        ft_putstr("an error occurred !\n");
        ft_putstr("Please choose a valid map name\n");
        return (-1);
    }
    if (map_name[i+1] == 'b' && map_name[i+2] == 'e' && map_name[i+3] == 'r' && map_name[i+4] == '\n')
        return (0);
    return(-1);
}

int main(int ac, char const *av[])
{
    int map_size;

    map_size = 0;
    if (ac != 2)
    {
        ft_putstr("An Error Occurred !\n");
        ft_putstr("INVALID ARGUMENTS, Please choose a only one map name.\n");
        return (-1);
    }
    if (ac == 2)
    {
        if (map_extention_validator(av[1]) == -1)
            return (-1);
        else
        {
            ft_open_map(av[1], &map_size);
        }    
    }
}