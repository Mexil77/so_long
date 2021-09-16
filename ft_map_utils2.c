/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:21:07 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/16 22:36:01 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_countobjs(char **map)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
			if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				count++;
		j = -1;
	}
	return (count);
}
