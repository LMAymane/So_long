/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 05:48:51 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/13 20:13:57 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	flood_fill(int x, int y, t_program *game, char **map)
{
	if (x < 0 || y < 0 || x >= game->map.row || y >= (int)ft_strlen(map[x]))
		return ;
	if (map[x][y] == 'E')
	{
		map[x][y] = 'V';
		return ;
	}
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill(x + 1, y, game, map);
	flood_fill(x - 1, y, game, map);
	flood_fill(x, y + 1, game, map);
	flood_fill(x, y - 1, game, map);
}

static int	test_ff(char **map, t_program *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_ff(t_program *game)
{
	int		i;
	char	**copy_map;
	int		res;

	i = 0;
	copy_map = malloc(sizeof(char *) * (game->map.row + 1));
	if (!copy_map)
		return (0);
	while (i < game->map.row)
	{
		copy_map[i] = ft_strdup(game->map.map[i]);
		if (!copy_map[i])
		{
			free_map_cpy(copy_map);
			return (0);
		}
		i++;
	}
	copy_map[game->map.row] = NULL;
	flood_fill(game->map.player.x, game->map.player.y, game, copy_map);
	res = test_ff(copy_map, game);
	free_map_cpy(copy_map);
	return (res);
}
