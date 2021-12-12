/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:48:23 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/12/12 21:57:25 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_next_frame(void)
{
	char		*bg;
	static int	i = 0;
	char		*welcome[5];

	welcome[0] = "img/pacman/0.xpm";
	welcome[1] = "img/pacman/1.xpm";
	welcome[2] = "img/pacman/2.xpm";
	welcome[3] = "img/pacman/3.xpm";
	welcome[4] = "img/pacman/4.xpm";
	bg = welcome[i++];
	if (i == 5)
		i = 0;
	return (bg);
}

int	is_done(t_maps *param, int y, int x)
{
	static int	i;

	if (!i)
		i = 0;
	if (param->map_load[y][x] == 'C')
		i++;
	if (param->map_load[y][x] == 'E')
	{
		if (e.collectibles == i)
		{
			printf("YOU WIN");
			ft_close_window(param);
		}
		return (0);
	}
	return (1);
}

int	ft_close_window(t_maps *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	free(map->map_load);
	exit (0);
	return (1);
}
