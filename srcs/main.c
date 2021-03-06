/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:54:44 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/21 19:16:49 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	close_check(int status, t_vars *vars, int first)
{
	if (status == -1)
	{
		if (!first)
			free_map(vars);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("File close error", 2);
		exit(EXIT_FAILURE);
	}	
}

int	close_window(t_vars *vars)
{
	free_map(vars);
	img_ptr_destroy(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int code, t_vars *vars)
{
	if (code == A_KEY || code == S_KEY || code == W_KEY || code == D_KEY)
		moving_player(code, vars);
	if (code == ESC_KEY)
		close_window(vars);
	return (0);
}

int	loop_func(t_vars *vars)
{
	static int	count;

	count++;
	rendering_main(vars, &vars->img, count);
	if (count >= 1000)
		count = 2;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		width;
	int		height;

	if (args_check(argc, argv, &vars) >= 0)
		return (print_args_err(&vars));
	width = (vars.map.width - 1) * TILESIZE;
	height = vars.map.height * TILESIZE;
	vars.mlx = mlx_init();
	my_mlx_error_handle(&vars, vars.mlx, MLX_INIT);
	screen_size_check(&vars, width, height);
	tile_path_set(&vars);
	vars.win = mlx_new_window(vars.mlx, width, height, "so_long");
	my_mlx_error_handle(&vars, vars.win, MLX_NEW_WIN);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 33, 1L << 17, close_window, &vars);
	mlx_loop_hook(vars.mlx, loop_func, &vars);
	mlx_loop(vars.mlx);
}
