/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:54:50 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/06 18:54:50 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	free_all_ptr(t_vars *vars)
{
	free(vars->img.img);
	free(vars->mlx);
	free(vars->win);
}

void	tile_path_set(t_vars *vars)
{
	vars->map.space = "images/space.xpm";
	vars->map.wall = "images/wall.xpm";
	vars->map.collectible = "images/collectible.xpm";
	vars->map.exit = "images/exit.xpm";
	vars->map.player = "images/player.xpm";
	vars->map.teki = "images/player.xpm";
	vars->player.step = 0;
	vars->img.s_img = mlx_xpm_file_to_image(vars->mlx, vars->map.space,
			&vars->img.width, &vars->img.height);
	vars->img.w_img = mlx_xpm_file_to_image(vars->mlx, vars->map.wall,
			&vars->img.width, &vars->img.height);
	vars->img.c_img = mlx_xpm_file_to_image(vars->mlx, vars->map.collectible,
			&vars->img.width, &vars->img.height);
	vars->img.e_img = mlx_xpm_file_to_image(vars->mlx, vars->map.exit,
			&vars->img.width, &vars->img.height);
	vars->img.p_img = mlx_xpm_file_to_image(vars->mlx, vars->map.player,
			&vars->img.width, &vars->img.height);
	vars->img.t_img = mlx_xpm_file_to_image(vars->mlx, vars->map.teki,
			&vars->img.width, &vars->img.height);
}

void	img_ptr_destroy(t_vars *vars)
{
	if (vars->img.s_img)
		mlx_destroy_image(vars->mlx, vars->img.s_img);
	if (vars->img.w_img)
		mlx_destroy_image(vars->mlx, vars->img.w_img);
	if (vars->img.e_img)
		mlx_destroy_image(vars->mlx, vars->img.e_img);
	if (vars->img.c_img)
		mlx_destroy_image(vars->mlx, vars->img.c_img);
	if (vars->img.p_img)
		mlx_destroy_image(vars->mlx, vars->img.p_img);
	if (vars->img.t_img)
		mlx_destroy_image(vars->mlx, vars->img.t_img);
}
