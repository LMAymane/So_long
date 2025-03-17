/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:26:54 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/16 09:58:16 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_bonus/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_program	game;

	if (ac != 2)
		syntaxe_error();
	check_map(av[1], &game);
	if (is_graphic_mlx(&game) == 0)
		return (free_map(&game), 0);
	return (0);
}
