/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:36:46 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/12/12 20:43:54 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mov_enemy_up(t_maps *param)
{
	char	*tswira;
	int		w;
	int		h;

	tswira = mlx_xpm_file_to_image(param->mlx, get_next_frame(), &w, &h);
	mlx_put_image_to_window(param->mlx, param->mlx_win,
		tswira, param->x, param->y -= 50);
	mlx_destroy_image(param->mlx, tswira);
	param->map_load[param->enemy_y][param->enemy_x] = '0';
	param->map_load[param->enemy_y - 1][param->enemy_x] = 'M';
}

void	mov_enemy_down(t_maps	*param)
{
	char	*tswira;
	int		w;
	int		h;

	tswira = mlx_xpm_file_to_image(param->mlx, get_next_frame(), &w, &h);
	mlx_put_image_to_window(param->mlx, param->mlx_win,
		tswira, param->x, param->y += 50);
	mlx_destroy_image(param->mlx, tswira);
	param->map_load[param->enemy_y][param->enemy_x] = '0';
	param->map_load[param->enemy_y + 1][param->enemy_x] = 'M';
}

int	mov_enemy(t_maps *param)
{
	static int	moves = 0;
	static int	max_moves = 0;

	if (enemy_logic(param, param->enemy_y - 1, param->enemy_x) && moves >= 0
		&& moves <= max_moves
		&& is_enemy(param, param->enemy_y - 1, param->enemy_x))
	{
		mov_enemy_up(param);
		ft_parser(param);
		moves++;
		max_moves++;
		ft_render_initial_text(param);
	}
	else if (enemy_logic(param, param->enemy_y + 1, param->enemy_x)
		&& moves != 0 && is_enemy(param, param->enemy_y + 1, param->enemy_x))
	{
		mov_enemy_down(param);
		ft_parser(param);
		max_moves = 0;
		moves--;
		ft_render_initial_text(param);
	}
	return (0);
}
