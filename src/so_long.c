/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:01:20 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/12/12 19:05:26 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_extention_validator(char *map_name)
{
	int	i;

	i = 0;
	while (map_name[i] != '.')
	{
		i++;
	}
	if (map_name[i] != '.' && map_name[i + 1] != 'b' && map_name[i + 2] != 'e'
		&& map_name[i + 3] != 'r' && map_name[i + 4] != '\0')
	{
		ft_putstr("an error occurred !\n");
		ft_putstr("Please choose a valid map name\n");
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		map_size;
	t_maps	map;
	int		x;

	x = 0;
	map_size = 0;
	if (ac != 2)
	{
		ft_putstr("An Error Occurred !\n");
		ft_putstr("INVALID ARGUMENTS, Please choose only one map name.\n");
		return (0);
	}
	if (ac == 2)
	{
		if (map_extention_validator(av[1]) == -1)
			return (0);
		ft_open_map(av[1], &map_size);
		map.map_load = ft_map_loader(av[1], map_size, &map);
		ft_render(&map);
	}
}
