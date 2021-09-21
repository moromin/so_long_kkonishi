/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:54:10 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/21 22:36:53 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include "../mlx_linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "defines.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	void	*s_img;
	void	*w_img;
	void	*c_img;
	void	*p_w_1_img;
	void	*p_w_2_img;
	void	*p_w_3_img;
	void	*p_a_1_img;
	void	*p_a_2_img;
	void	*p_a_3_img;
	void	*p_s_1_img;
	void	*p_s_2_img;
	void	*p_s_3_img;
	void	*p_d_1_img;
	void	*p_d_2_img;
	void	*p_d_3_img;
	void	*t_w_1_img;
	void	*t_w_2_img;
	void	*t_w_3_img;
	void	*t_a_1_img;
	void	*t_a_2_img;
	void	*t_a_3_img;
	void	*t_s_1_img;
	void	*t_s_2_img;
	void	*t_s_3_img;
	void	*t_d_1_img;
	void	*t_d_2_img;
	void	*t_d_3_img;
	void	*e_1_img;
	void	*e_2_img;
	void	*e_3_img;
	void	*back;
}	t_data;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	int		c_flag;
	int		e_flag;
	int		p_flag;
	int		t_flag;
	int		collectibles;
}	t_map;

typedef struct s_player
{
	int		i;
	int		j;
	int		step;
	int		key;
	int		frame;
	int		clear;
	int		count;
}	t_player;

typedef struct s_enemy
{
	int		i;
	int		j;
	int		direction;
}	t_enemy;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			err;
	char		*path;
	t_map		map;
	t_data		img;
	t_player	player;
	t_enemy		enemy;
}	t_vars;

// main.c

// arg_check.c
int		args_check(int argc, char *argv[], t_vars *vars);

// error_handle.c
void	my_mlx_error_handle(t_vars *vars, void *ptr, int mlx_type);
int		is_valid_map_size(int x, int y);
void	close_check(int status, t_vars *vars, int first);
void	map_gnl_check(t_vars *vars, int i);
int		print_args_err(t_vars *vars);

// rendering.c
void	tile_path_set(t_vars *vars);
void	rendering_main(t_vars *vars, t_data *img);
void	moving_player(int code, t_vars *vars);

// utils.c
void	init_map(t_vars *vars);
void	free_map(t_vars *vars);
int		is_valid_extension(char *filename);
void	screen_size_check(t_vars *vars, int width, int height);

// display_bonus.c
void	string_put_display(t_vars *vars);

// tile_setting.c
void	tile_path_set(t_vars *vars);

// destroy_ptr.c
int		close_window(t_vars *vars);
void	img_ptr_destroy(t_vars *vars);
void	destroy_player(t_vars *vars);
void	destroy_enemy(t_vars *vars);

// sprite_player_bonus.c
void	sprite_player(t_vars *vars, t_data *img, int i, int j);
void	player_sprite_set_1(t_vars *vars);
void	player_sprite_set_2(t_vars *vars);

// sprite_exit_bonus.c
void	sprite_exit(t_vars *vars, t_data *img, int i, int j);
void	exit_sprite_set(t_vars *vars);

// sprite_enemy_bonus.c
void	sprite_enemy(t_vars *vars, t_data *img, int i, int j);
void	enemy_sprite_set_1(t_vars *vars);
void	enemy_sprite_set_2(t_vars *vars);

// enemy_moving_bonus.c
void	moving_enemy(t_vars *vars);

#endif
