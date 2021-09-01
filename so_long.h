#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>

# define ARGS_NUM_ERROR 0

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		err;
}	t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// arg_check.c
int		args_check(int argc, char *argv[], t_vars *vars);
int		print_args_err(t_vars *vars);

#endif
