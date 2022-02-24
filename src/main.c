/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:42:27 by jlamonic          #+#    #+#             */
/*   Updated: 2021/10/19 21:59:44 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Wrong number of arguments\n");
	if (ft_strrchr(argv[1], '.'))
	{
		if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
			ft_error("Wrong map extension\n");
	}
	else
		ft_error("Wrong argument\n");
}

void	game(t_struct *map)
{
	map->mlx = mlx_init();
	map->new_window = mlx_new_window(map->mlx, map->len * 64, \
	map->width * 64, "so_long");
	ft_map_filling(map);
	mlx_hook(map->new_window, 2, 0, key_h, map);
	mlx_hook(map->new_window, 17, 1L << 2, ft_close_x, map);
	mlx_loop_hook(map->mlx, ft_patrol_animation, map);
	mlx_loop(map->mlx);
}

int	main(int argc, char **argv)
{
	t_struct	map;

	ft_init_map(&map);
	ft_init_map2(&map);
	check_arg(argc, argv);
	map_parser(argv[1], &map);
	map_validate(&map);
	game(&map);
	return (0);
}
