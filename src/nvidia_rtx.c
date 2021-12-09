#include "so_long.h"

void    ft_put_tswira(char c, int x, int y, t_maps *map)
{
    char *tswira;
    int w;
    int h;

    if (c == '0')
    {
        tswira = mlx_xpm_file_to_image(map->mlx, "img/bg_50_50.xpm", &w, &h);
        mlx_put_image_to_window(map->mlx, map->mlx_win, tswira, x, y);
        mlx_destroy_image(map->mlx, tswira);
    }
    if (c == 'P')
    {
        tswira = mlx_xpm_file_to_image(map->mlx, "img/p.xpm", &w, &h);
        mlx_put_image_to_window(map->mlx, map->mlx_win, tswira, x, y);
        mlx_destroy_image(map->mlx, tswira);
    }
    if (c == '1')
    {
        tswira = mlx_xpm_file_to_image(map->mlx, "img/three.xpm", &w, &h);
        mlx_put_image_to_window(map->mlx, map->mlx_win, tswira, x, y);
        mlx_destroy_image(map->mlx, tswira);
    }
}

void parser(t_maps *map)
{
    int y = 0;
    int pos_of_x;
    int pos_of_y = 0;
    while (map->map_load[y])
    {
        int x = 0;
        pos_of_x = 0;
        while (map->map_load[y][x])
        {
            ft_put_tswira(map->map_load[y][x], pos_of_x, pos_of_y, map);
            pos_of_x += 50;
            x++;
        }
        pos_of_y += 50;
        y++;
    }
    
}

void welcome_msg()
{
    ft_putstr("Welcome Player !\n");
    ft_putstr("The player’s goal is to collect all collectibles present on the map then escape with minimal movement.\n");
    ft_putstr("Enjoy, BITCH !\n");
}

void ft_render(t_maps *map)
{
    int window_w;
    int window_h;
    int w;
    int h;
    char *bg;

    window_w = map->map_column * 50;
    window_h = map->map_rows * 50;
    if (window_h > 1080 || window_w > 1920)
    {
        ft_putstr("error\n");
        ft_putstr("The map resolution is too big.\n");
        exit(0);
    }
    else
    {
        welcome_msg();
        map->mlx = mlx_init();
        map->mlx_win = mlx_new_window(map->mlx, window_w, window_h, "So_long");
        bg = mlx_xpm_file_to_image(map->mlx, "img/bg_50_50.xpm", &w, &h);
        parser(map);
        //mlx_put_image_to_window(map->mlx, map->mlx_win, bg, 0, 0);
        mlx_loop(map->mlx);
    }
}