/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:53:14 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/15 01:22:08 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(char *file_name, t_program *game)
{
	check_dir(file_name);
	if (check_extention(file_name, ".ber") != 0)
		extention_error();
	get_map(file_name, game);
	if (check_rectangular(*game) == 1)
		err_rectangular(game);
	if (check_characters(*game) == 0)
		err_characters(game);
	if (check_player(*game) == 0)
		err_map(game);
	if (check_exit(*game) == 0)
		err_map(game);
	if (check_walls(*game) != 0)
		err_walls(game);
	if (check_occur(*game) == 0)
		err_ecp(game);
	get_num_of_coll(game);
	get_player_pos(game);
	if (!check_ff(game))
		err_map(game);
}
