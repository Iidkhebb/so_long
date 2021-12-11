#include "so_long_bonus.h"

char *get_next_frame()
{
    char *bg;
    static int i = 0;

    char *welcome[5] = {"img/pacman/0.xpm", 
    "img/pacman/1.xpm","img/pacman/2.xpm",
    "img/pacman/3.xpm","img/pacman/4.xpm"};

    bg = welcome[i++];
    if (i == 5)
        i = 0;
    return(bg);
}

int is_done(t_maps *param,int y, int x)
{
    static int i;

    if (!i)
        i = 0;
    if (param->map_load[y][x] == 'C')
        i++;
    if (param->map_load[y][x] == 'E')
    {
        if (e.collectibles == i)
        {
            printf("YOU WIN");
            exit(0);
        }
        return (0);
    }
    return (1);
}

int ft_close_window(t_maps *map)
{	
    mlx_destroy_window(map->mlx, map->mlx_win);
	free(map->map_load);
	exit(0);
    return 1;
}