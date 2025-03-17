/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 05:23:37 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/15 03:21:18 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	err_map(t_program *game)
{
	write(2, "Error: Invalid map\n", 20);
	free_map(game);
}

void	err_rectangular(t_program *game)
{
	write(2, "Error: Map isn't rectangualr!.\n", 32);
	free_map(game);
}

void	err_characters(t_program *game)
{
	write(2, "Error: Invalid character found!.\n", 34);
	free_map(game);
}

void	err_walls(t_program *game)
{
	write(2, "Error: Invalid walls!\n", 23);
	free_map(game);
}

void	err_ecp(t_program *game)
{
	write(2, "Error: P or E or C or N not Found!!.\n", 38);
	free_map(game);
}
