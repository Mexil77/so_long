/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:14 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/14 22:30:27 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leak(void)
{
	system("leaks so_long");
}

void	ft_freemap(char **map)
{
	size_t	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_printmap(char **map)
{
	size_t	i;

	i = -1;
	while (map[++i])
		printf("map[%zu] : %s\n", i, map[i]);
}

int	main(int argc, char const *argv[])
{
	char	**map;
	void	*id;
	void	*window;

	//atexit (leak);
	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	map = ft_makemap(argv[1]);
	if (!map)
	{
		printf("Error\n");
		return (0);
	}
	id = mlx_init();
	window = mlx_new_window(id, 500, 200, "Hola");
	mlx_loop(id);
	ft_printmap(map);
	ft_freemap(map);
	return (0);
}
