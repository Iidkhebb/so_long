/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_logic_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:29:09 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/12/12 21:37:11 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_next_frame_enemy(void)
{
	char		*bg;
	static int	i = 0;
	char		*welcome[4];

	welcome[0] = "img/enemy/0.xpm";
	welcome[1] = "img/enemy/1.xpm";
	welcome[2] = "img/enemy/2.xpm";
	welcome[3] = "img/enemy/3.xpm";
	bg = welcome[i++];
	if (i == 4)
		i = 0;
	return (bg);
}

int	enemy_logic(t_maps *param, int y, int x)
{
	if (param->map_load[y][x] != '1' && param->map_load[y][x] != 'C')
	{
		return (1);
	}
	return (0);
}

int	is_enemy(t_maps *param, int y, int x)
{
	int	j;

	j = 0;
	if (param->map_load[y][x] == 'P')
	{
		printf("YOU LOSE");
		while (j < 2147483647)
			j++;
		exit (0);
		return (0);
	}
	return (1);
}
