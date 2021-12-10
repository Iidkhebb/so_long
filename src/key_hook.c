#include "so_long.h"

void mov_down(t_maps *param)
{
    char *tswira;
    int w, h;

    if (!e.mov)
        e.mov = 0;
    if (is_done(param,param->playery+1,param->playerx) == 1)
    {
        tswira = mlx_xpm_file_to_image(param->mlx, "img/grog.xpm", &w, &h);
        mlx_put_image_to_window(param->mlx, param->mlx_win, tswira, param->x, param->y+=50);
        mlx_destroy_image(param->mlx, tswira);
        param->map_load[param->playery][param->playerx] = '0';
        param->map_load[param->playery+1][param->playerx] = 'P';
        ft_parser(param);
        printf("Mouvement : %d\n", e.mov += 1);
    }
}

void mov_right(t_maps *param)
{
    char *tswira;
    int w, h;

    if (!e.mov)
        e.mov = 0;
    if (is_done(param,param->playery,param->playerx+1) == 1)
    {
        tswira = mlx_xpm_file_to_image(param->mlx, "img/grog.xpm", &w, &h);
        mlx_put_image_to_window(param->mlx, param->mlx_win, tswira, param->x+=50, param->y);
        mlx_destroy_image(param->mlx, tswira);
        param->map_load[param->playery][param->playerx] = '0';
        param->map_load[param->playery][param->playerx+1] = 'P';
        ft_parser(param);
        printf("Mouvement : %d\n", e.mov += 1);
    }
}

void mov_left(t_maps *param)
{
    char *tswira;
    int w, h;

    if (!e.mov)
        e.mov = 0;
    if (is_done(param,param->playery,param->playerx-1))
    {
        tswira = mlx_xpm_file_to_image(param->mlx, "img/grog.xpm", &w, &h);
        mlx_put_image_to_window(param->mlx, param->mlx_win, tswira, param->x-=50, param->y);
        mlx_destroy_image(param->mlx, tswira);
        param->map_load[param->playery][param->playerx] = '0';
        param->map_load[param->playery][param->playerx-1] = 'P';
        ft_parser(param);
        printf("Mouvement : %d\n", e.mov += 1);
    }
}

void mov_up(t_maps *param)
{
    char *tswira;
    int w, h;

    if (!e.mov)
        e.mov = 0;
    if (is_done(param,param->playery-1,param->playerx))
    {
        tswira = mlx_xpm_file_to_image(param->mlx, "img/grog.xpm", &w, &h);
        mlx_put_image_to_window(param->mlx, param->mlx_win, tswira, param->x, param->y-=50);
        mlx_destroy_image(param->mlx, tswira);
        param->map_load[param->playery][param->playerx] = '0';
        param->map_load[param->playery-1][param->playerx] = 'P';
        ft_parser(param);
        printf("Mouvement : %d\n", e.mov += 1);
    }
}

int key_hook(int keycode,t_maps *param)
{
    char *tswira;
    int w;
    int h;

    if (keycode == 1 && (param->map_load[param->playery+1][param->playerx] != '1'))
        mov_down(param);
    if (keycode == 2 && (param->map_load[param->playery][param->playerx+1] != '1'))
        mov_right(param);
    if (keycode == 0 && (param->map_load[param->playery][param->playerx-1] != '1'))
        mov_left(param);
    if (keycode == 13 && (param->map_load[param->playery-1][param->playerx] != '1'))
        mov_up(param);
    if (keycode == 53)
    {
        mlx_destroy_window(param->mlx, param->mlx_win);
	    free(param->map_load);
        exit(0);
    }
    return 0;
}