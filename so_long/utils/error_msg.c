/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:11:43 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/10 21:49:11 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	syntaxe_error(void)
{
	write(2, "Error: Try ./program_name <map_file.ber>\n", 42);
	exit(1);
}

void	extention_error(void)
{
	write(2, "Error: Invalid extention !!\n", 29);
	exit(EXIT_FAILURE);
}

void	fd_error(void)
{
	write(2, "Error: failed to open the map file\n", 36);
	exit(1);
}

void	empty_map(int fd)
{
	close(fd);
	write(2, "Error: Map file is empty\n", 25);
	exit(1);
}
