#include "so_long.h"

int	close_window(int keycode, t_vars *vars)
{
	(void)keycode;
	// free_map(vars);
	// free_all_ptr(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	key_hook(int code, t_vars *vars)
{
	if (code == A_KEY || code == S_KEY || code == W_KEY || code == D_KEY)
		moving_player(code, vars);
	if (code == ESC_KEY)
	{
		// free_map(vars);
		// free_all_ptr(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
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
	rendering_main(&vars, &vars.img);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 33, 1L << 17, close_window, &vars);
	mlx_loop(vars.mlx);
}

	// mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	// mlx_hook(vars.win, 4, 1L << 2, close, &vars);