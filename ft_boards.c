/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:46:32 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/19 22:47:54 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printboards(t_vars vars)
{
	mlx_string_put(vars.mlx, vars.win, TILE * 0, 0, 200, "Mov:");
	mlx_string_put(vars.mlx, vars.win, TILE * 2, 0, 200, ft_itoa(*vars.steps));
	mlx_string_put(vars.mlx, vars.win, TILE * 4, 0, 200, "Sco:");
	mlx_string_put(vars.mlx, vars.win, TILE * 6, 0, 200, ft_itoa(*vars.score));
}
