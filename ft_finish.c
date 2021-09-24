/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:05:19 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/24 15:20:14 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_vars vars)
{
	ft_freeall(vars);
	exit(0);
}

void	ft_error(char *str, t_vars vars)
{
	printf("Error\n");
	printf("%s\n", str);
	ft_freeall(vars);
	exit(0);
}

size_t	ft_valname(const char *str)
{
	size_t	i;
	size_t	point;

	i = -1;
	point = 0;
	while (++i < ft_strlen(str) && !point)
		if (str[i] == '.')
			point = 1;
	if (str[i] == 'b' && str[i + 1] == 'e' && str[i + 2] == 'r')
		return (1);
	return (0);
}
