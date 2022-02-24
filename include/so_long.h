/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:42:27 by jlamonic          #+#    #+#             */
/*   Updated: 2021/10/19 21:59:44 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>

typedef struct s_struct
{
	char	**str;
	int		len;
	int		width;
	int		position;
	int		wall;
	int		goal;
	int		collect;
	int		exit;
	int		pos_x;
	int		pos_y;
	void	*img_player;
	void	*img_player2;
	void	*img_player3;
	void	*img_player4;
	void	*img_wall;
	void	*img_grass;
	void	*img_earth;
	void	*img_collect;
	void	*img_collect2;
	void	*img_collect3;
	void	*img_collect4;
	void	*img_exit;
	void	*img_exit2;
	void	*img_enemy;
	void	*img_enemy_2;
	void	*victim;
	int		img_height;
	int		img_width;
	int		time;
	int		steps;
	int		frame;
	void	*mlx;
	void	*new_window;
	int		x;
	int		y;
	void	*img;
	int		flag;
}	t_struct;

int		main(int argc, char **argv);
void	so_long(char *str);
void	ft_width_map(char *str, t_struct *map);
void	ft_init_map(t_struct *map);
void	ft_init_map2(t_struct *map);
void	map_parser(char *str, t_struct *map);
void	map_validate(t_struct *map);
void	first_and_last_str_of_map(t_struct *map);
void	structure_of_map(char *str, t_struct *map);
int		key_h(int key_code, t_struct *map);
void	game(t_struct *map);
char	*find_image(char *str);
void	ft_map_filling(t_struct *map);
void	ft_put_image(char symbol, t_struct *map, int x, int y);
void	put_simple_images(char symbol, t_struct *map);
void	put_animation(char symbol, t_struct *map);
void	ft_exit(t_struct *map);
void	ft_step_printer(t_struct *map);
int		ft_close(t_struct *map, char mes_code);
void	ft_moving(t_struct *map, int x, int y);
void	ft_lets_moving(t_struct *map, int x, int y);
int		ft_patrol_animation(t_struct *map);
int		ft_close_x(t_struct *map);
void	ft_error(char *str);

#endif