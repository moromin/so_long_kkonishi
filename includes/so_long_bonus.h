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
	void	*e_img;
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
}	t_data;

typedef struct s_map
{
	size_t	width;
	size_t	height;
	char	**map;
	int		c_flag;
	int		e_flag;
	int		p_flag;
	int		collectibles;
}	t_map;

typedef struct s_player
{
	int		i;
	int		j;
	int		step;
	int		key;
	int		frame;
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

// arg_check.c
int		args_check(int argc, char *argv[], t_vars *vars);

// error_handle.c
int		print_args_err(t_vars *vars);

// rendering.c
void	tile_path_set(t_vars *vars);
void	rendering_main(t_vars *vars, t_data *img);
void	moving_player(int code, t_vars *vars);

// utils.c
void	init_map(t_vars *vars);
void	free_map(t_vars *vars);
void	free_all_ptr(t_vars *vars);

// display_bonus.c
void	string_put_display(t_vars *vars);

// tile_setting.c
void	tile_path_set(t_vars *vars);
void	img_ptr_destroy(t_vars *vars);

// destroy_ptr.c
int		close_window(t_vars *vars);
void	img_ptr_destroy(t_vars *vars);
void	destroy_player(t_vars *vars);
void	destroy_enemy(t_vars *vars);

// sprite_player_bonus.c
void	sprite_player(t_vars *vars, t_data *img, int i, int j);

#endif
