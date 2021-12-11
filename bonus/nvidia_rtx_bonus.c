#include "so_long_bonus.h"

void put_img(char c, int x, int y, t_maps *map)
{
    char *tswira;
    char *backgroud_parser;
    int w;
    int h;

    backgroud_parser = mlx_xpm_file_to_image(map->mlx, "img/pacman/bg.xpm", &w, &h);
    mlx_put_image_to_window(map->mlx, map->mlx_win, backgroud_parser, x, y);
    mlx_destroy_image(map->mlx, backgroud_parser);
    tswira = mlx_xpm_file_to_image(map->mlx, ft_pull_img(c), &w, &h);
    mlx_put_image_to_window(map->mlx, map->mlx_win, tswira, x, y);
    mlx_destroy_image(map->mlx, tswira);
}

char *ft_pull_img(char c)
{
    if (c == 'P')
        return(get_next_frame());
    if (c == '1')
        return("img/pacman/blue_wall.xpm");
    if (c == 'C')
        return("img/pacman/yellow_dot.xpm");
    if (c == 'E')
        return("img/pacman/door.xpm");
    if (c == 'M')
        return(get_next_frame_enemy()); // bonus
    return("img/pacman/bg.xpm");
}

void ft_parser(t_maps *map)
{
    int y = 0;
    map->y = 0;
    
    while (map->map_load[y])
    {
        int x = 0;
        map->x = 0;
        while (map->map_load[y][x])
        {
            if (map->map_load[y][x] != '\n')
                put_img(map->map_load[y][x], map->x, map->y, map);
            if (map->map_load[y][x] == 'P')
            {
                map->playerx = x;
                map->playery = y;
            }
            if (map->map_load[y][x] == 'M') //bonus
            {
                map->enemy_x = x;
                map->enemy_y = y;
            }
            map->x += 50;
            x++;
        }
        map->y += 50;
        y++;
    }   
}

void ft_render(t_maps *map)
{
    int window_w;
    int window_h;
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
        mlx_key_hook(map->mlx_win,key_hook, map);
        mlx_hook(map->mlx_win, 17, 0, ft_close_window, map);
        ft_parser(map);
        ft_render_initial_text(map); //bonus
        mlx_loop_hook(map->mlx, mov_enemy, map); //bonus
        mlx_loop(map->mlx);
    }
}