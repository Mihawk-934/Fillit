/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:11:46 by miclaude          #+#    #+#             */
/*   Updated: 2017/12/18 22:50:12 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"
# define BUF_SIZE 21

char	**ft_open1(char **tab, char **argv);
int		ft_open2(char **tab, char **argv);
char	**ft_open(char **tab, char **argv, int argc);

int		ft_check1(char *tab);
int		ft_check2(char *tab);
int		ft_connexion(char *tab);
int		ft_tetriminos(char **tab);
int		ft_check_piece(char **tab);

char	*ft_gps(char *str, char c);
char	**ft_create_map(int i);
int		ft_count(char **map);
int		ft_position(char *gps, char **map, int x, int y);
int		ft_fill(char **gps, char **map, int i);
void	ft_aff(char **tab);
char	**ft_map(char **tab);
void	ft_delete(char *gps, char **map);
int		ft_void(int i);
#endif
