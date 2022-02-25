/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:26:54 by jlamonic          #+#    #+#             */
/*   Updated: 2022/02/25 12:27:22 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_close_x(t_struct *map)
{
	mlx_destroy_window(map->mlx, map->new_window);
	ft_putendl_fd("You closed window", 1);
	exit(EXIT_SUCCESS);
}
