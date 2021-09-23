/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boards_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:46:32 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/23 20:31:00 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_printboards(t_vars vars, size_t flag, size_t i)
{
	char	*score;
	char	*steps;
	size_t	h;

	score = 0;
	steps = 0;
	h = TILE * i;
	if (flag == 1 || flag == 0)
	{
		steps = ft_itoa(*vars.steps);
		mlx_string_put(vars.mlx, vars.win, TILE * 0, h, 200, "Mov:");
		mlx_string_put(vars.mlx, vars.win, TILE * 2, h, 200, steps);
		free(steps);
	}
	if (flag == 2 || flag == 0)
	{
		score = ft_itoa(*vars.score);
		mlx_string_put(vars.mlx, vars.win, TILE * 0, h + 32, 200, "Sco:");
		mlx_string_put(vars.mlx, vars.win, TILE * 2, h + 32, 200, score);
		free(score);
	}
}
