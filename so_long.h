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
	int		width;
	int		height;
	char	**map;
	int		c_flag;
	int		e_flag;
	int		p_flag;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		err;
	char	*path;
	t_map	map;
}	t_vars;

// arg_check.c
int		args_check(int argc, char *argv[], t_vars *vars);

// error_handle.c
void	print_args_err(t_vars *vars);

#endif
