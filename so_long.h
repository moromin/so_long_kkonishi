#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

# define VALID_CHAR "01CEP"

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
}	t_data;

typedef struct s_map
{
	size_t	width;
	size_t	height;
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

#endif
