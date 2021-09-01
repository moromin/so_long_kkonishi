#include "so_long.h"

int	close_win(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_data	img;

	if (args_check(argc, argv, &vars) >= 0)
		print_args_err(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00000000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// char	*relative_path = "./test.xpm";
	// img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img.width, &img.height);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 33, 1L << 17, close_win, &vars);
	// mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	// mlx_hook(vars.win, 4, 1L << 2, close, &vars);
	mlx_loop(vars.mlx);
}
