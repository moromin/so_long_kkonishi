#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "gnl/get_next_line.h"
# include <unistd.h>

# define ARGS_NUM_ERROR 0

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		err;
	char	*path;
}	t_vars;

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

// arg_check.c
int		args_check(int argc, char *argv[], t_vars *vars);
void	print_args_err(t_vars *vars);

#endif
