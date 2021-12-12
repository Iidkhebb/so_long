/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:56:51 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/12/12 21:55:15 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_open_mapfile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit (0);
	}
	return (fd);
}

char	**ft_close_map(int fd, char **load[])
{
	if (close(fd) == 0)
	{
		return (*load);
	}
	else
	{
		free(*load);
		perror("Error\n");
		exit (0);
	}
}

char	**ft_map_loader(char *file, int map_size, t_maps *map)
{
	int		i;
	int		fd;
	char	*line;
	char	**load;

	i = 0;
	fd = ft_open_mapfile(file);
	load = malloc(sizeof(char *) * map_size);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (i == 0)
		{
			map->map_column = ft_char_line_count(line);
		}
		load[i] = ft_strdup(line);
		free((char *)line);
		i++;
	}
	map->map_rows = i;
	load[i] = NULL;
	return (ft_close_map(fd, &load));
}
