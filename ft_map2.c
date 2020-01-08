/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:52:56 by miclaude          #+#    #+#             */
/*   Updated: 2017/12/18 22:38:56 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_delete(char *gps, char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y])
	{
		if (map[y][x] == gps[6])
			map[y][x] = '.';
		x++;
		if (map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
}

void	ft_aff(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_putendl(tab[i++]);
}

char	**ft_map(char **tab)
{
	char	**map;
	char	**gps;
	char	c;
	int		i;

	i = ft_tetriminos(tab);
	if (!(gps = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	c = 65;
	i = -1;
	while (tab[++i])
		gps[i] = ft_gps(tab[i], c++);
	gps[i] = 0;
	i = 2;
	map = ft_create_map(i);
	while (ft_fill(gps, map, 0) == 0)
		map = ft_create_map(++i);
	return (map);
}
