#include "sl.h"

int	args_check(int argc, char *argv[], t_vars *vars)
{
	vars->err = -1;
	if (argc != 2)
		vars->err = ARGS_NUM_ERROR;
	return (vars->err);
}

int	print_args_err(t_vars *vars)
{
	if (vars->err == ARGS_NUM_ERROR)
		write(1, "Invalid number of arguments\n", 28);
	return (1);
}
