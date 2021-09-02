#include "so_long.h"

void	init_map(t_vars *vars)
{
	vars->map.c_flag = 0;
	vars->map.e_flag = 0;
	vars->map.p_flag = 0;
	vars->map.width = 0;
	vars->map.height = 0;
}

void	free_map(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->map.height)
	{
		free(vars->map.map[i]);
		vars->map.map[i] = NULL;
		i++;
	}
	free(vars->map.map);
}
