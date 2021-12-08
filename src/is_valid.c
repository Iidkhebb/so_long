#include "so_long.h"
void ft_validated(int fd, int *map_size)
{
    char *line;
    char *prv;

    prv = NULL;

    
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
        {
            ft_put_str("Error\n");
            exit(0);
            break;
        }
        *map_size += ft_strlen2(line + 1); // read until /n instead of /0
        if (!prv)
        {
            ft_check_horz_wall(line);
        }
        else
        {
            ft_check_sides(line);
        }
        ft_check_map_shap(line);
    }
    
}
void ft_open_map(char *file, int *map_size)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("An Error Occurred !\n");
        ft_putstr("INVALID PATH TO FILE OR DIRECTORY.\n");
        exit(0);
    }
    else
    {
        ft_validated(fd, map_size);
        if (close(fd) != 0)
        {
            perror("error\n");
            exit(0);
        }
    }
}