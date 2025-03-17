/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:18:25 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/16 09:53:06 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	close_handler(t_program *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	free(game->win);
	exit(0);
}

void	enemy_check(t_program *game, char tile)
{
	if (tile == 'N')
	{
		write(1, "You pick the wrong one HAHAHA !!\n", 34);
		close_handler(game);
	}
}

void	move_player(t_program *game, int new_x, int new_y)
{
	char	tile;

	tile = game->map.map[new_x][new_y];
	if (tile == '0' || tile == 'C')
	{
		if (tile == 'C')
			game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[new_x][new_y] = 'P';
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->mv_counter++;
	}
	enemy_check(game, tile);
	if (tile == 'E')
	{
		if (game->map.collectibles == 0)
		{
			write(1, "You won!\n", 9);
			close_handler(game);
		}
		else
			write(1, "Collect all items before exiting!\n", 34);
	}
	display_move_count(game);
}

void	player_action(int key, t_program *game)
{
	if (key == W)
		move_player(game, game->map.player.x - 1, game->map.player.y);
	if (key == S)
		move_player(game, game->map.player.x + 1, game->map.player.y);
	if (key == A)
	{
		game->player_anim = 1;
		move_player(game, game->map.player.x, game->map.player.y - 1);
	}
	if (key == D)
	{
		game->player_anim = 2;
		move_player(game, game->map.player.x, game->map.player.y + 1);
	}
}

int	handle_keys(int key, t_program *game)
{
	if (key == ESC_KEY)
		close_handler(game);
	if (key == W || key == S || key == A || key == D)
		player_action(key, game);
	return (0);
}
