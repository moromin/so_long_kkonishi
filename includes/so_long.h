/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:54:13 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/21 13:06:07 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	void	*e_img;
	void	*p_img;
}	t_data;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	int		c_flag;
	int		e_flag;
	int		p_flag;
	char	*space;
	char	*wall;
	char	*collectible;
	char	*exit;
	char	*player;
}	t_map;

typedef struct s_player
{
	int		i;
	int		j;
	int		step;
}	t_player;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			err;
	char		*path;
	t_map		map;
	t_data		img;
	t_player	player;
}	t_vars;

// main.c
int		close_window(t_vars *vars);

// arg_check.c
int		args_check(int argc, char *argv[], t_vars *vars);

// error_handle.c
void	map_gnl_check(t_vars *vars, int i);
void	mlx_error_handle(t_vars *vars, int mlx_type);
int		extension_check(char *filename);
void	screen_size_check(t_vars *vars, int width, int height);
int		print_args_err(t_vars *vars);

// rendering.c
void	tile_path_set(t_vars *vars);
void	rendering_main(t_vars *vars, t_data *img, int count);
void	moving_player(int code, t_vars *vars);

// utils.c
void	init_map(t_vars *vars);
void	free_map(t_vars *vars);
void	free_all_ptr(t_vars *vars);
void	tile_path_set(t_vars *vars);
void	img_ptr_destroy(t_vars *vars);

// display_bonus.c
void	string_put_display(t_vars *vars);

#endif
