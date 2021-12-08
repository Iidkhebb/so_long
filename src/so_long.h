#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "./mlx/mlx.h"
# include <stdio.h>


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
void ft_check_map_shap(char *line);
void ft_check_sides(char *line);
void ft_check_horz_wall(char *line);
int ft_char_line_count(char *str);

#endif