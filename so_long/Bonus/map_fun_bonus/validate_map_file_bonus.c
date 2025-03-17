/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_file_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:31:44 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/14 20:38:49 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static void	check_empty_line(char *line, char *last_line, int fd)
{
	if (line[0] == '\n')
	{
		free(line);
		free(last_line);
		write(2, "Error: Map contains empty lines\n", 32);
		close(fd);
		exit(1);
	}
}

static void	check_last_line(char *last_line)
{
	if (last_line && last_line[ft_strlen(last_line) - 1] == '\n')
	{
		free(last_line);
		write(2, "Error: Your map is invalid !!\n", 31);
		exit(1);
	}
}

void	validate_map_file(char *file_name)
{
	int		fd;
	char	*line;
	char	*last_line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		fd_error();
	last_line = NULL;
	line = get_next_line(fd);
	if (!line)
		empty_map(fd);
	while (line != NULL)
	{
		check_empty_line(line, last_line, fd);
		free(last_line);
		last_line = line;
		line = get_next_line(fd);
	}
	close(fd);
	check_last_line(last_line);
	free(last_line);
}
