/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:43:02 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/12/12 18:48:10 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_validated(int fd, int *map_size)
{
	char	*line;
	char	*prv;

	prv = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			ft_check_elements("");
			break ;
		}
		*map_size += ft_strlen2(line + 1);
		if (!prv)
			ft_check_horz_wall(line);
		else
			ft_check_sides(line);
		ft_check_map_shap(line);
		ft_check_elements(line);
		ft_check_invalid_char(line);
		prv = line;
	}
	ft_check_horz_wall(prv);
	free(line);
}

void	count_elem(char c)
{
	if (c == 'E')
		e.exits += 1;
	if (c == 'C')
		e.collectibles += 1;
	if (c == 'P')
		e.player += 1;
}

void	ft_check_invalid_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != 'E' && line[i] != 'P' && line[i] != 'C'
			&& line[i] != '1' && line[i] != '0' && line[i] != '\n')
		{
			ft_putstr("Error\n");
			ft_putstr("Invalid map characters\n");
			exit (0);
		}
		i++;
	}
}

void	ft_open_map(char *file, int *map_size)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("An Error Occurred !\n");
		ft_putstr("INVALID PATH TO FILE OR DIRECTORY.\n");
		exit (0);
	}
	else
	{
		ft_validated(fd, map_size);
		if (close(fd) != 0)
		{
			perror("error\n");
			exit (0);
		}
	}
}
