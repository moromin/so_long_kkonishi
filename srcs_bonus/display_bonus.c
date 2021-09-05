#include "../includes/so_long_bonus.h"

void	string_put_display(t_vars *vars)
{
	char	*step;
	char	*all;
	char	*current;

	step = ft_itoa(vars->player.step);
	all = ft_itoa(vars->map.collectibles);
	current = ft_itoa(vars->map.collectibles - vars->map.c_flag);
	mlx_string_put(vars->mlx, vars->win, 5, vars->map.height * TILESIZE - 5,
		COLOR, DISP_STEP);
	mlx_string_put(vars->mlx, vars->win, 90, vars->map.height * TILESIZE - 5,
		COLOR, step);
	mlx_string_put(vars->mlx, vars->win, 130, vars->map.height * TILESIZE - 5,
		COLOR, DISP_COLLECTIBLES);
	mlx_string_put(vars->mlx, vars->win, 220, vars->map.height * TILESIZE - 5,
		COLOR, current);
	mlx_string_put(vars->mlx, vars->win, 230, vars->map.height * TILESIZE - 5,
		COLOR, "/");
	mlx_string_put(vars->mlx, vars->win, 240, vars->map.height * TILESIZE - 5,
		COLOR, all);
	free(step);
	free(all);
	free(current);
}
