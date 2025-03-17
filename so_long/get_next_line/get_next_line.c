/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:21:46 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/08 23:43:46 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	clear(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*remainder(char *rem, char *buffer)
{
	char	*temp;

	temp = rem;
	rem = ft_strjoin(temp, buffer);
	if (!rem)
		return (clear(&temp), NULL);
	clear(&temp);
	return (rem);
}

static char	*get_line(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
		line[j++] = *str++;
	line[j] = '\0';
	return (line);
}

static char	*get_rem(char *str)
{
	char	*check_newline;
	char	*rem;

	if (!str || !*str)
		return (clear(&str), NULL);
	check_newline = ft_strchr_gnl(str, '\n');
	if (!check_newline)
		return (clear(&str), NULL);
	rem = ft_strdup(check_newline + 1);
	if (!rem)
		return (clear(&str), NULL);
	clear(&str);
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*buffer;
	char		*line;
	ssize_t		bytes_read;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer || fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > (size_t)-1)
		return (clear(&buffer), clear(&rem), NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		rem = remainder(rem, buffer);
		if (!rem || ft_strchr_gnl(rem, '\n'))
			break ;
	}
	if (!rem || !*rem || bytes_read < 0)
		return (clear(&buffer), clear(&rem), NULL);
	line = get_line(rem);
	if (!line)
		return (clear(&buffer), clear(&rem), NULL);
	rem = get_rem(rem);
	return (clear(&buffer), line);
}
