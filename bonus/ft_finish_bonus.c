/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:05:19 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/23 22:35:43 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
