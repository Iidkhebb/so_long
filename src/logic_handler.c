#include "so_long.h"

/*char *get_next_frame(t_maps *map)
{
    char *bg;
    static int i = 0;

    char *welcome[16] = {"img/p3/0.xpm", 
    "img/p3/1.xpm","img/p3/2.xpm",
    "img/p3/3.xpm","img/p3/4.xpm",
    "img/p3/5.xpm", "img/p3/6.xpm", "img/p3/7.xpm", "img/p3/8.xpm", "img/p3/9.xpm", "img/p3/10.xpm", "img/p3/11.xpm",
    "img/p3/12.xpm", "img/p3/13.xpm", "img/p3/14.xpm", "img/p3/15.xpm"};

    bg = welcome[i++];
    if (i == 16)
        i = 0;
    return(bg);
}*/

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