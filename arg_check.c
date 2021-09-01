#include "so_long.h"

int	args_check(int argc, char *argv[], t_vars *vars)
{
	vars->err = -1;
	if (argc != 2)
		vars->err = ARGS_NUM_ERROR;
	(void)argv;
	return (vars->err);
}

void	print_args_err(t_vars *vars)
{
	ssize_t	res;

	if (vars->err == ARGS_NUM_ERROR)
		res = write(2, "Invalid number of arguments\n", 28);
	(void)res;
	exit(EXIT_FAILURE);
}
