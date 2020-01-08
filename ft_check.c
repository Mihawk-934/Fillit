/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:58:33 by miclaude          #+#    #+#             */
/*   Updated: 2017/12/18 22:49:18 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check1(char *tab)
{
	int	i;
	int	n;
	int	h;
	int	p;

	i = -1;
	n = 0;
	h = 0;
	p = 0;
	while (tab[++i])
	{
		if (tab[i] != '.' && tab[i] != '\n' && tab[i] != '#')
			return (0);
		if (tab[i] == '#')
			h++;
		if (tab[i] == '.')
			p++;
		if (tab[i] == '\n')
			n++;
	}
	if ((h != 4 || p != 12 || n != 5) || (tab[4] != '\n' || tab[9] != '\n' ||
				tab[14] != '\n' || tab[19] != '\n' || tab[20] != '\n'))
		return (0);
	return (1);
}

int		ft_check2(char *tab)
{
	int	i;
	int	n;
	int	h;
	int	p;

	i = -1;
	n = 0;
	h = 0;
	p = 0;
	while (tab[++i])
	{
		if (tab[i] != '.' && tab[i] != '\n' && tab[i] != '#')
			return (0);
		if (tab[i] == '#')
			h++;
		if (tab[i] == '.')
			p++;
		if (tab[i] == '\n')
			n++;
	}
	if ((h != 4 || p != 12 || n != 4) || (tab[4] != '\n' || tab[9] != '\n' ||
				tab[14] != '\n' || tab[19] != '\n'))
		return (0);
	return (1);
}

int		ft_connexion(char *tab)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (tab[i])
	{
		if (tab[i] != '#')
			i++;
		if ((i > 0) && (tab[i] == '#' && tab[i - 1] == '#'))
			c++;
		if (tab[i] == '#' && tab[i + 1] == '#')
			c++;
		if ((i > 4) && (tab[i] == '#' && tab[i - 5] == '#'))
			c++;
		if ((i < 15) && (tab[i] == '#' && tab[i + 5] == '#'))
			c++;
		if (tab[i])
			i++;
	}
	if (c == 6 || c == 8)
		return (1);
	else
		return (0);
}

int		ft_tetriminos(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (i > 26)
	{
		ft_putendl("error");
		exit(0);
	}
	return (i);
}

int		ft_check_piece(char **tab)
{
	int	i;

	i = ft_tetriminos(tab) - 1;
	if (!(ft_check2(tab[i])))
	{
		ft_putendl("error");
		return (0);
	}
	while (--i >= 0)
	{
		if (!(ft_check1(tab[i])))
		{
			ft_putendl("error");
			return (0);
		}
	}
	while (tab[++i])
	{
		if (!(ft_connexion(tab[i])))
		{
			ft_putendl("error");
			return (0);
		}
	}
	return (1);
}
