#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

int	close(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	// t_data	img;

	(void)argc;
	(void)argv;
	// if (args_check(argc, argv, &vars) >= 0)
	// 	return (print_args_err(&vars));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Hello world!");
	// img.img = mlx_new_image(vars.mlx, 1280, 720);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 		&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	mlx_loop(vars.mlx);
}
