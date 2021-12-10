#include "so_long.h"
/*int get_next_frame(t_maps *map)
{
    char *bg;
    static int i = 0;
    int window_w;
    int window_h;
    int w;
    int h;

    char *welcome[10] = {"img/intro/0.xpm", "img/intro/1.xpm","img/intro/2.xpm","img/intro/3.xpm","img/intro/4.xpm","img/intro/5.xpm", "img/intro/6.xpm", "img/intro/7.xpm","img/intro/8.xpm", "img/intro/9.xpm"};

    bg = mlx_xpm_file_to_image(map->mlx, welcome[i++], &w, &h);
    mlx_put_image_to_window(map->mlx, map->mlx_win, bg, map->playery, map->playerx);
    mlx_destroy_image(map->mlx, bg);
    if (i == 10)
        i = 0;
    return(0);
}*/

void    ft_put_tswira(char c, int x, int y, t_maps *map)
{
    char *tswira;
    int w;
    int h;

    if (c == '0' || c == 'P' || c == '1' || c == 'E' || c == 'C')
    {
        tswira = mlx_xpm_file_to_image(map->mlx, "img/grass.xpm", &w, &h);
        mlx_put_image_to_window(map->mlx, map->mlx_win, tswira, x, y);
        mlx_destroy_image(map->mlx, tswira);
    }
    if (c == 'P')
    {
        tswira = mlx_xpm_file_to_image(map->mlx, "img/grog.xpm", &w, &h);
        mlx_put_image_to_window(map->mlx, map->mlx_win, tswira, x, y);
        mlx_destroy_image(map->mlx, tswira);
        //mlx_loop_hook(map->mlx, get_next_frame, map);
    }
    if (c == '1')
    {
        tswira = mlx_xpm_file_to_image(map->mlx, "img/three.xpm", &w, &h);
        mlx_put_image_to_window(map->mlx, map->mlx_win, tswira, x, y);
        mlx_destroy_image(map->mlx, tswira);
    }
    if (c == 'C')
    {
        tswira = mlx_xpm_file_to_image(map->mlx, "img/green_c.xpm", &w, &h);
        mlx_put_image_to_window(map->mlx, map->mlx_win, tswira, x, y);
        mlx_destroy_image(map->mlx, tswira);
    }
    if (c == 'E')
    {
        tswira = mlx_xpm_file_to_image(map->mlx, "img/e.xpm", &w, &h);
        mlx_put_image_to_window(map->mlx, map->mlx_win, tswira, x, y);
        mlx_destroy_image(map->mlx, tswira);
    }
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
            ft_put_tswira(map->map_load[y][x], map->x, map->y, map);
            if (map->map_load[y][x] == 'P')
            {
                map->playerx = x;
                map->playery = y;
            }
            map->x += 50;
            x++;
        }
        map->y += 50;
        y++;
    }    
}

void welcome_msg()
{
    ft_putstr("Welcome Player !\n");
    ft_putstr("The player’s goal is to collect all collectibles present on the map then escape with minimal movement.\n");
    ft_putstr("Enjoy, BITCH !\n");
}

int is_done(t_maps *param,int y, int x)
{
    static int i;

    if (!i)
        i = 0;
    if (param->map_load[y][x] == 'C')
    {
        printf("%d",i);
        i++;
    }
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

int key_hook(int keycode,t_maps *param)
{
    printf("%d\n",keycode);
    char *tswira;
    int w, h;

    if (keycode == 125 && (param->map_load[param->playery+1][param->playerx] != '1'))
    {
        //down
        if (is_done(param,param->playery+1,param->playerx) == 1)
        {
            tswira = mlx_xpm_file_to_image(param->mlx, "img/grog.xpm", &w, &h);
            mlx_put_image_to_window(param->mlx, param->mlx_win, tswira, param->x, param->y+=50);
            mlx_destroy_image(param->mlx, tswira);
            param->map_load[param->playery][param->playerx] = '0';
            param->map_load[param->playery+1][param->playerx] = 'P';
            ft_parser(param);
        }
        printf("%d\n", param->x);
    }
    if (keycode == 124 && (param->map_load[param->playery][param->playerx+1] != '1'))
    {
        //right
        if (is_done(param,param->playery,param->playerx+1) == 1)
        {
            tswira = mlx_xpm_file_to_image(param->mlx, "img/grog.xpm", &w, &h);
            mlx_put_image_to_window(param->mlx, param->mlx_win, tswira, param->x+=50, param->y);
            mlx_destroy_image(param->mlx, tswira);
            param->map_load[param->playery][param->playerx] = '0';
            param->map_load[param->playery][param->playerx+1] = 'P';
            ft_parser(param);
        }
        printf("%d\n", param->x);
    }
    if (keycode == 123 && (param->map_load[param->playery][param->playerx-1] != '1'))
    {
        //left
         if (is_done(param,param->playery,param->playerx-1))
        {
            tswira = mlx_xpm_file_to_image(param->mlx, "img/grog.xpm", &w, &h);
            mlx_put_image_to_window(param->mlx, param->mlx_win, tswira, param->x-=50, param->y);
            mlx_destroy_image(param->mlx, tswira);
            param->map_load[param->playery][param->playerx] = '0';
            param->map_load[param->playery][param->playerx-1] = 'P';
            ft_parser(param);
        }
        printf("%d\n", param->x);
    }
    if (keycode == 126 && (param->map_load[param->playery-1][param->playerx] != '1'))
    {
        //up
        if (is_done(param,param->playery-1,param->playerx))
        {
            tswira = mlx_xpm_file_to_image(param->mlx, "img/grog.xpm", &w, &h);
            mlx_put_image_to_window(param->mlx, param->mlx_win, tswira, param->x, param->y-=50);
            mlx_destroy_image(param->mlx, tswira);
            param->map_load[param->playery][param->playerx] = '0';
            param->map_load[param->playery-1][param->playerx] = 'P';
            ft_parser(param);
        }
        printf("%d\n", param->x);
    }
    if (keycode == 53)
    {
        exit(0);
    }
    return 0;
}

void ft_render(t_maps *map)
{
    int window_w;
    int window_h;
    int w;
    int h;
    char *bg;
    int i  = 0;
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
        
        //mlx_loop_hook(map->mlx,get_next_frame, map);
        mlx_key_hook(map->mlx_win,key_hook, map);
        ft_parser(map);
        mlx_loop(map->mlx);
    }
}
