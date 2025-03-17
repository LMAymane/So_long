/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:59:32 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/14 20:37:50 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	put_img(t_program *g, int x, int y)
{
	if (g->map.map[g->map.row][g->map.col] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->textures[0], x, y);
	else if (g->map.map[g->map.row][g->map.col] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->textures[1], x, y);
	else if (g->map.map[g->map.row][g->map.col] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->textures[2], x, y);
	else if (g->map.map[g->map.row][g->map.col] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->textures[3], x, y);
	else if (g->map.map[g->map.row][g->map.col] == 'N')
		mlx_put_image_to_window(g->mlx, g->win, g->textures[6], x, y);
	else if (g->map.map[g->map.row][g->map.col] == 'P')
		player_animation(g, x, y);
}

void	render_map(t_program *g)
{
	int	x;
	int	y;

	g->map.row = 0;
	if (g->player_anim == 2)
		g->player_anim = 2;
	else if (g->player_anim == 1)
		g->player_anim = 1;
	else
		g->player_anim = 0;
	while (g->map.map[g->map.row])
	{
		g->map.col = 0;
		while (g->map.map[g->map.row][g->map.col])
		{
			x = g->map.col * 50;
			y = g->map.row * 50;
			put_img(g, x, y);
			g->map.col++;
		}
		g->map.row++;
	}
}
