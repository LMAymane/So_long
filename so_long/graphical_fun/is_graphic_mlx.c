/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_graphic_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:28:24 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/16 09:20:00 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_map_dimensions(t_program *game)
{
	size_t	row;
	size_t	col;
	size_t	max_col;

	max_col = 0;
	row = 0;
	while (game->map.map[row])
	{
		col = 0;
		while (game->map.map[row][col] && game->map.map[row][col] != '\0')
			col++;
		row++;
	}
	game->ww = col * 50;
	game->wh = row * 50;
}

void	load_texture(t_program *g, int index, char *f)
{
	g->textures[index] = mlx_xpm_file_to_image(g->mlx, f, &g->iw, &g->ih);
	if (!g->textures[index])
	{
		write(2, "Error: Texture not found\n", 26);
		close_handler(g);
	}
}

void	load_img(t_program *game)
{
	load_texture(game, 0, "assets/wall.xpm");
	load_texture(game, 1, "assets/route.xpm");
	load_texture(game, 2, "assets/coll.xpm");
	load_texture(game, 3, "assets/exit.xpm");
	load_texture(game, 4, "assets/player.xpm");
}

void	render_map(t_program *g)
{
	int	x;
	int	y;

	g->map.row = 0;
	while (g->map.map[g->map.row])
	{
		g->map.col = 0;
		while (g->map.map[g->map.row][g->map.col])
		{
			x = g->map.col * 50;
			y = g->map.row * 50;
			if (g->map.map[g->map.row][g->map.col] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->textures[0], x, y);
			else if (g->map.map[g->map.row][g->map.col] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->textures[1], x, y);
			else if (g->map.map[g->map.row][g->map.col] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->textures[2], x, y);
			else if (g->map.map[g->map.row][g->map.col] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->textures[3], x, y);
			else if (g->map.map[g->map.row][g->map.col] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, g->textures[4], x, y);
			g->map.col++;
		}
		g->map.row++;
	}
}

int	is_graphic_mlx(t_program *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	get_map_dimensions(game);
	if (game->ww > 2550 || game->wh > 1400)
	{
		write(2, "Error: Invalid map dimensions !!\n", 34);
		return (0);
	}
	game->win = mlx_new_window(game->mlx, game->ww, game->wh, "so_long");
	if (!game->win)
		return (0);
	load_img(game);
	render_map(game);
	mlx_hook(game->win, 2, 0, handle_keys, game);
	mlx_hook(game->win, CLOSE, 0, close_handler, game);
	mlx_loop(game->mlx);
	return (0);
}
