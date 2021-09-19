/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 22:14:00 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/19 19:32:29 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printmap(char **map)
{
	size_t	i;

	if (map)
	{
		i = -1;
		while (map[++i])
			printf("map[%zu] : %s\n", i, map[i]);
	}
	else
		printf("No hay MAPA.");
}

void	ft_printobjs(t_img *objs)
{
	size_t	i;

	i = -1;
	while (objs[++i].type)
	{
		printf("O[%zu].T : %c\n", i + 1, objs[i].type);
		printf("O[%zu].X : %zu\n", i + 1, objs[i].x);
		printf("O[%zu].Y : %zu\n", i + 1, objs[i].y);
		printf("\n");
	}
}

void	leak(void)
{
	system("leaks so_long");
}
