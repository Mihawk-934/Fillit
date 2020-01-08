/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:47:21 by miclaude          #+#    #+#             */
/*   Updated: 2017/12/18 17:10:31 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_open1(char **tab, char **argv)
{
	char	buf[BUF_SIZE + 1];
	int		i;
	int		fd;
	int		ret;

	i = 0;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		ft_putendl("error");
		return (0);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
		i++;
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	tab[i] = 0;
	if (close(fd) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	return (tab);
}

int		ft_void(int i)
{
	if (i == 0)
	{
		ft_putendl("error");
		exit(0);
	}
	return (1);
}

int		ft_open2(char **tab, char **argv)
{
	char	buf[BUF_SIZE + 1];
	int		i;
	int		fd;
	int		ret;

	i = 0;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		ft_putendl("error");
		return (0);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		tab[i++] = ft_strdup(buf);
	}
	if (close(fd) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	if (!(ft_void(i)))
		return (0);
	return (1);
}

char	**ft_open(char **tab, char **argv, int argc)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [file]");
		return (0);
	}
	if (!(tab = ft_open1(tab, argv)))
		return (0);
	if (!(ft_open2(tab, argv)))
		return (0);
	return (tab);
}
