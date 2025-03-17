/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_fun_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:53:53 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/14 20:38:13 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	check_dir(char *file_name)
{
	int	fd;

	fd = open(file_name, O_DIRECTORY);
	if (fd != -1)
	{
		write(2, "This isn't a file it's a directory !!\n", 38);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

int	check_extention(const char *src, const char *to_find)
{
	size_t	len_to_find;
	size_t	len_src;

	len_src = ft_strlen(src);
	len_to_find = ft_strlen(to_find);
	while (len_src > len_to_find)
	{
		src++;
		len_src--;
	}
	return (ft_strcmp(src, to_find));
}

int	check_rectangular(t_program game)
{
	int	row;
	int	len;
	int	line_len;

	row = 0;
	line_len = ft_strlen(game.map.map[row]);
	while (game.map.map[row] != NULL)
	{
		len = ft_strlen(game.map.map[row]);
		if (line_len != len)
			return (1);
		row++;
	}
	return (0);
}

int	in_set(char c)
{
	char	*set;
	int		i;

	i = 0;
	set = "10CENP";
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_characters(t_program game)
{
	int	row;
	int	col;

	row = 0;
	while (game.map.map[row] != NULL)
	{
		col = 0;
		while (game.map.map[row][col] != '\n' && game.map.map[row][col] != '\0')
		{
			if (!in_set(game.map.map[row][col]))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
