/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_fun2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 06:06:15 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/15 01:22:45 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_player(t_program game)
{
	int	p;
	int	i;

	i = 0;
	p = 0;
	while (game.map.map[i])
	{
		if (ft_strchr(game.map.map[i], 'P') == 1)
			p++;
		i++;
	}
	return (p == 1);
}

int	check_exit(t_program game)
{
	int	e;
	int	i;

	i = 0;
	e = 0;
	while (game.map.map[i])
	{
		if (ft_strchr(game.map.map[i], 'E') == 1)
			e++;
		i++;
	}
	return (e == 1);
}

int	check_walls(t_program game)
{
	int	i;
	int	j;

	i = 0;
	game.map.col = ft_strlen(game.map.map[0]);
	while (i < game.map.row)
	{
		j = 0;
		while (j < game.map.col)
		{
			if (i == 0 || i == game.map.row - 1)
			{
				if (game.map.map[i][j] != '1')
					return (1);
			}
			if (j == 0 || j == game.map.col - 1)
			{
				if (game.map.map[i][j] != '1')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_occur(t_program game)
{
	int	i;
	int	c;
	int	p;
	int	e;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (game.map.map[i])
	{
		if (ft_strchr(game.map.map[i], 'E') == 1)
			e = 1;
		if (ft_strchr(game.map.map[i], 'C') == 1)
			c = 1;
		if (ft_strchr(game.map.map[i], 'P') == 1)
			p = 1;
		i++;
	}
	return (e && c && p);
}
