/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text_img_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:19:55 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/12/12 21:28:27 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	len_str(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len = 1;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	num;

	num = n;
	i = len_str(n) - 1;
	str = (char *)malloc((len_str(n) + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len_str(n)] = '\0';
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		str[i--] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		str[i] = '-';
	if (n == 0)
		str[i] = '0';
	return (str);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char			*s;
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	s = (char *)malloc((len1 + len2) + 1);
	if (!s)
		return (0);
	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		s[i + len1] = s2[i];
		i++;
	}
	s[len1 + len2] = '\0';
	return (s);
}

void	ft_render_initial_text(t_maps *map)
{
	char	*str1;
	char	*str2;
	char	*mv;
	char	*msg;

	str1 = "PACMAN 2005";
	mv = ft_itoa(e.mov);
	str2 = "Moves: ";
	msg = ft_strjoin2(str2, mv);
	mlx_string_put(map->mlx, map->mlx_win, 25, 15, 0xFFDC1E, str1);
	mlx_string_put(map->mlx, map->mlx_win, map->map_column * 35 + 95,
		15, 0xFFDC1E, msg);
	free((char *)mv);
	free((char *)msg);
}
