/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:51:58 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/16 09:53:19 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	player_animation(t_program *g, int x, int y)
{
	if (g->player_anim == 0 || g->player_anim == 2)
		mlx_put_image_to_window(g->mlx, g->win, g->textures[4], x, y);
	if (g->player_anim == 1)
		mlx_put_image_to_window(g->mlx, g->win, g->textures[5], x, y);
}
