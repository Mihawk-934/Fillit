/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:09:33 by miclaude          #+#    #+#             */
/*   Updated: 2017/12/18 10:17:53 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	**tab;

	tab = NULL;
	if (!(tab = ft_open(tab, argv, argc)))
		return (0);
	if (!(ft_check_piece(tab)))
		return (0);
	ft_aff(ft_map(tab));
	return (0);
}
