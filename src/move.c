/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:42:27 by jlamonic          #+#    #+#             */
/*   Updated: 2022/02/25 12:13:49 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_step_printer(t_struct *map)
{
	char	*str;

	str = ft_itoa(map->steps);
	ft_put_image('1', map, 0, 1);
	ft_put_image('1', map, 0, 0);
	mlx_string_put(map->mlx, map->new_window, 20, 10, 0xDC143C, "Steps: ");
	mlx_string_put(map->mlx, map->new_window, 100, 10, 0xDC143C, str);
	ft_putstr_fd("Steps: ", 1);
	ft_putendl_fd(str, 1);
	free(str);
}

int	ft_close(t_struct *map, char mes_code)
{
	int	res;

	mlx_destroy_window(map->mlx, map->new_window);
	if (mes_code == 'C')
		ft_putendl_fd("You closed the window", 1);
	else if (mes_code == 'W')
	{
		res = fork();
		if (res == 0)
		{
			system(" kill $(ps | grep tea | head -n 1 | awk '{print $1}')");
			system("afplay ./assets/sound/game-over.mp3");
			exit(0);
		}
		ft_putendl_fd("You win", 1);
	}
	else if (mes_code == 'D')
	{
		ft_putendl_fd("You were eaten", 1);
	}
	exit(EXIT_SUCCESS);
}

void	ft_moving(t_struct *map, int x, int y)
{
	map->str[map->pos_y][map->pos_x] = '0';
	ft_put_image('0', map, map->pos_y, map->pos_x);
	map->str[map->pos_y + y][map->pos_x + x] = 'P';
	ft_put_image('P', map, map->pos_y + y, map->pos_x + x);
	map->steps++;
	ft_step_printer(map);
}

void	ft_lets_moving(t_struct *map, int x, int y)
{
	int	res;

	if (map->str[map->pos_y + y][map->pos_x + x] == 'D')
		ft_close(map, 'D');
	else if (map->str[map->pos_y + y][map->pos_x + x] == 'E' \
			&& map->collect == 0)
		ft_close(map, 'W');
	else if (map->str[map->pos_y + y][map->pos_x + x] == 'C')
	{
		res = fork();
		if (res == 0)
		{
			system(" kill $(ps | grep tea | head -n 1 | awk '{print $1}')");
			system("afplay ./assets/sound/coin.mp3");
			exit(0);
		}
		ft_moving(map, x, y);
		map->collect = map->collect - 1;
		if (map->collect == 0)
			ft_exit(map);
	}
	else if (map->str[map->pos_y + y][map->pos_x + x] == '0')
		ft_moving(map, x, y);
}

int	key_h(int key_code, t_struct *map)
{
	if (key_code == 13)
		ft_lets_moving(map, 0, -1);
	else if (key_code == 1)
		ft_lets_moving(map, 0, 1);
	else if (key_code == 0)
	{
		map->flag = 1;
		ft_lets_moving(map, -1, 0);
	}
	else if (key_code == 2)
	{
		map->flag = 0;
		ft_lets_moving(map, 1, 0);
	}
	else if (key_code == 53)
		ft_close(map, 'C');
	return (0);
}
