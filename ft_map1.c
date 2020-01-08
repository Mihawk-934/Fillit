/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:52:41 by miclaude          #+#    #+#             */
/*   Updated: 2017/12/18 11:00:46 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_gps(char *str, char c)
{
	char	*tab;
	int		i;
	int		a;
	int		x;
	int		y;

	a = -1;
	i = 0;
	if (!(tab = (char*)malloc(sizeof(char) * 7)))
		return (0);
	while (((y = 0) + 1) && str[i] && str[i] != '#')
		i++;
	x = i;
	while (str[++x])
	{
		if (str[x] == '\n' && (i = i + 5))
			y++;
		if (str[x] == '#')
		{
			tab[++a] = y;
			tab[++a] = (x - i);
		}
	}
	tab[++a] = c;
	return (tab);
}

char	**ft_create_map(int i)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	map[i] = 0;
	while (y < i)
	{
		if (!(map[y] = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		map[y][i] = '\0';
		while (x < i)
		{
			map[y][x] = '.';
			x++;
		}
		y++;
		x = 0;
	}
	return (map);
}

int		ft_fill(char **gps, char **map, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!gps[i])
		return (1);
	while (map[y])
	{
		if (map[y][x] == '.')
			if (ft_position(gps[i], map, x, y))
			{
				if (ft_fill(gps, map, i + 1))
					return (1);
				ft_delete(gps[i], map);
			}
		x++;
		if (map[y][x] == '\0')
		{
			y++;
			x = 0;
		}
	}
	return (0);
}

int		ft_count(char **map)
{
	int y;
	int i;

	y = 0;
	i = 0;
	while (map[y][i] != '\0')
		i++;
	return (i);
}

int		ft_position(char *gps, char **map, int x, int y)
{
	if (x + gps[1] < 0 || y + gps[0] >= ft_count(map) ||
		map[y + gps[0]][x + gps[1]] != '.')
		return (0);
	if (x + gps[3] < 0 || y + gps[2] >= ft_count(map) ||
		map[y + gps[2]][x + gps[3]] != '.')
		return (0);
	if (x + gps[5] < 0 || y + gps[4] >= ft_count(map) ||
		map[y + gps[4]][x + gps[5]] != '.')
		return (0);
	map[y][x] = gps[6];
	map[y + gps[0]][x + gps[1]] = gps[6];
	map[y + gps[2]][x + gps[3]] = gps[6];
	map[y + gps[4]][x + gps[5]] = gps[6];
	return (1);
}
