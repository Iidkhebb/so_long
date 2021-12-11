#include "so_long_bonus.h"

char *get_next_frame_enemy()
{
    char *bg;
    static int i = 0;

    char *welcome[4] = {"img/enemy/0.xpm", 
    "img/enemy/1.xpm","img/enemy/2.xpm",
    "img/enemy/3.xpm"};

    bg = welcome[i++];
    if (i == 4)
        i = 0;
    return(bg);
}

int is_enemy(t_maps *param,int y, int x)
{
    int j;

    j = 0; 
    if (param->map_load[y][x] == 'P')
    {
        printf("YOU LOSE");
        while (j++ < 2147483647){}
        exit(0);
        return (0);
    }
    return (1);
}
void mov_enemy_up(t_maps *param)
{
    char *tswira;
    int w, h;

    tswira = mlx_xpm_file_to_image(param->mlx, get_next_frame(), &w, &h);
    mlx_put_image_to_window(param->mlx, param->mlx_win, tswira, param->x, param->y-=50);
    mlx_destroy_image(param->mlx, tswira);
    param->map_load[param->enemy_y][param->enemy_x] = '0';
    param->map_load[param->enemy_y-1][param->enemy_x] = 'M';
}

void mov_enemy_down(t_maps *param)
{
    char *tswira;
    int w;
    int h;
    
    tswira = mlx_xpm_file_to_image(param->mlx, get_next_frame(), &w, &h);
    mlx_put_image_to_window(param->mlx, param->mlx_win, tswira, param->x, param->y+=50);
    mlx_destroy_image(param->mlx, tswira);
    param->map_load[param->enemy_y][param->enemy_x] = '0';
    param->map_load[param->enemy_y+1][param->enemy_x] = 'M';
}
int enemy_logic(t_maps *param,int y , int x)
{
    if (param->map_load[y][x] != '1' && param->map_load[y][x] != 'C')
    {
        return(1);
    }
    return(0);
}
int mov_enemy(t_maps *param)
{
    static int  moves = 0;
    static int max_moves = 0;

    if(enemy_logic(param, param->enemy_y-1, param->enemy_x) && moves >= 0 && moves <= max_moves && is_enemy(param, param->enemy_y-1, param->enemy_x))
    {
        mov_enemy_up(param);
        ft_parser(param);
        moves++;
        max_moves++;
        ft_render_initial_text(param);
    }
    else if(enemy_logic(param, param->enemy_y+1, param->enemy_x) && moves != 0 && is_enemy(param, param->enemy_y+1, param->enemy_x))
    {
        mov_enemy_down(param);
        ft_parser(param);
        max_moves = 0;
        moves--;
        ft_render_initial_text(param);
    }
    return 0;
}