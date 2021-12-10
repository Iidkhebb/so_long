#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "../mlx/mlx.h"
# include <stdio.h>

typedef struct  maps
{
    int map_rows;
    int map_column;
    char **map_load;
    void *mlx;
    void	*mlx_win;
    int playerx;
    int playery;
    int x;
    int y;

} t_maps;

struct  e
{
    int collectibles;
    int player;
    int exits;
    int mov;
} e;

// Get_next_line
char	*get_next_line(int fd);
size_t	ft_strlen(char const	*str);
char	*ft_strjoin(char const *s1,	char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void	*ft_memmove(void *str1, const void *str2, size_t n);

// libft_utils
void ft_putstr(char *str);
int ft_strlen2(char *str);

// so_long_utils
void ft_open_map(char *file, int *map_size);
int map_extention_validator(char *map_name);
void ft_check_map_shap(char *line);
void ft_validated(int fd, int *map_size);
void ft_check_invalid_char(char *line);
void ft_check_sides(char *line);
void ft_check_horz_wall(char *line);
int ft_char_line_count(char *str);
void ft_check_elements(char *line);
int ft_open_mapfile(char *file);
char **ft_close_map(int fd, char **load[]);
char **ft_map_loader(char *file, int map_size, t_maps *map);
void count_elem(char c);

// Nvidia RTX Render
void welcome_msg();
void ft_render(t_maps *map);
void ft_parser(t_maps *map);
int key_hook(int keycode,t_maps *param);
char *get_next_frame(t_maps *map);
char *ft_pull_img(char c, t_maps *map);
void put_img(char c, int x, int y, t_maps *map);
int ft_close_window(t_maps *map);
int is_done(t_maps *param,int y, int x);

// Movement
void mov_down(t_maps *param);
void mov_right(t_maps *param);
void mov_left(t_maps *param);
void mov_up(t_maps *param);
#endif