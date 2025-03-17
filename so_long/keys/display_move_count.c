/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:52:44 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/14 22:55:32 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	calcul_len(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	handle_negative(long *n, char *str)
{
	if (*n < 0)
	{
		str[0] = '-';
		*n *= -1;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*str;

	nb = n;
	len = 0;
	len = calcul_len(n);
	if (n <= 0)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	handle_negative(&nb, str);
	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

void	display_move_count(t_program *game)
{
	char	*str;

	str = ft_itoa(game->mv_counter);
	if (str)
	{
		write(1, "Moves : ", 9);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		free(str);
	}
}
