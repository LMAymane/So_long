/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:55:14 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/15 00:40:10 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_len(int fd)
{
	int		len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line != NULL)
	{
		len++;
		free(line);
		line = get_next_line(fd);
		if (line && line[0] == '\n')
			return (-1);
	}
	free(line);
	return (len);
}

static void	read_map_lines(int fd, t_program *game)
{
	int	i;

	i = 0;
	while (i < game->map.row)
	{
		game->map.map[i] = get_next_line(fd);
		if (!game->map.map[i])
		{
			write(2, "Error: Failed to read map line\n", 30);
			exit(1);
		}
		if (game->map.map[i][ft_strlen(game->map.map[i]) - 1] == '\n')
			game->map.map[i][ft_strlen(game->map.map[i]) - 1] = '\0';
		i++;
	}
}

void	get_map(char *file_name, t_program *game)
{
	int	fd;

	validate_map_file(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		fd_error();
	game->map.row = map_len(fd);
	if (game->map.row == -1)
		err_map(game);
	close(fd);
	game->map.map = malloc(sizeof(char *) * (game->map.row + 1));
	if (!game->map.map)
	{
		write(2, "Error: Malloc failed to allocate memory\n", 41);
		exit(1);
	}
	game->map.map[game->map.row] = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		fd_error();
	read_map_lines(fd, game);
	close(fd);
}
