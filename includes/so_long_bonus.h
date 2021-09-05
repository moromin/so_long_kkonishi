#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include "../mlx_linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define VALID_CHAR "01CEP"
# define VALID_CHAR_BONUS "01CEPT"

# define DISP_STEP "PLAYER STEP :"
# define DISP_COLLECTIBLES "COLLECTIBLES :"
# define DISP_CLEAR "MAP CLEAR!"
# define COLOR 0x00FFDAB9

# define ARGS_NUM_ERROR 0
# define FILE_OPEN_ERROR 1
# define INVALID_MAP_CHAR 2
# define LACK_ESSENTIAL_CHAR 3
# define NOT_RECTANGULAR 4
# define NOT_CLOSED_BY_WALL 5

# define MALLOC_ERROR 10

# define TILESIZE 48

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

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
	void	*t_img;
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
	char	*space;
	char	*wall;
	char	*collectible;
	char	*exit;
	char	*player;
	char	*teki;
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
int		close_window(int keycode, t_vars *vars);

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

#endif
