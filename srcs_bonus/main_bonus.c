#include "../includes/so_long_bonus.h"

int	key_hook(int code, t_vars *vars)
{
	if (code == A_KEY || code == S_KEY || code == W_KEY || code == D_KEY)
		moving_player(code, vars);
	if (code == ESC_KEY)
		close_window(vars);
	return (0);
}

int	expose_window(t_vars *vars)
{
	rendering_main(vars, &vars->img);
	return (0);
}

void	run_animation(t_vars *vars)
{
	// static int	count;

	// count++;
	// (void)vars;
	// if (count == 500)
	// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.p_s_img,
	// 		0, 6 * TILESIZE);
	// else if (count == 1000)
	// {
	// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.t_s_img,
	// 		0, 6 * TILESIZE);
	// 	count = 0;
	// }
	// else if (count == 1500)
	// {
	// 	count = 0;
	// }
	(void)vars;
}

int	loop_func(t_vars *vars)
{
	run_animation(vars);
	rendering_main(vars, &vars->img);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		width;
	int		height;

	if (args_check(argc, argv, &vars) >= 0)
		return (print_args_err(&vars));
	vars.mlx = mlx_init();
	tile_path_set(&vars);
	width = (vars.map.width - 1) * TILESIZE;
	height = vars.map.height * TILESIZE;
	vars.win = mlx_new_window(vars.mlx, width, height, "so_long");
	// vars.win = mlx_new_window(vars.mlx, width, height * 2, "so_long");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_expose_hook(vars.win, expose_window, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_window, &vars);
	mlx_loop_hook(vars.mlx, loop_func, &vars);
	mlx_loop(vars.mlx);
}
