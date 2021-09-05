#include "../includes/so_long.h"

int	print_args_err(t_vars *vars)
{
	ssize_t	res;

	res = write(2, "Error\n", 6);
	if (vars->err == ARGS_NUM_ERROR)
		res = write(2, "Invalid number of arguments.\n", 29);
	if (vars->err == FILE_OPEN_ERROR)
		res = write(2, "File open error.\n", 17);
	if (vars->err == INVALID_MAP_CHAR)
		res = write(2, "Map includes invalid character.\n", 32);
	if (vars->err == LACK_ESSENTIAL_CHAR)
		res = write(2, "Lack essential character (C, E or P).\n", 38);
	if (vars->err == NOT_RECTANGULAR)
		res = write(2, "Map is not rectangular.\n", 24);
	if (vars->err == NOT_CLOSED_BY_WALL)
	{
		free_map(vars);
		res = write(2, "Map is not closed by wall.\n", 27);
	}
	(void)res;
	return (EXIT_FAILURE);
}