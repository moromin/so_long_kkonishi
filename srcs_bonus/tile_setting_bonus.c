/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_setting_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:30 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/21 18:25:43 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	tile_path_set(t_vars *vars)
{
	vars->map.collectibles = vars->map.c_flag;
	vars->player.step = 0;
	vars->player.frame = 1;
	vars->player.key = S_KEY;
	vars->player.clear = 0;
	vars->player.count = 0;
	vars->enemy.direction = S_KEY;
	vars->img.s_img = mlx_xpm_file_to_image(vars->mlx, SPACE,
			&vars->img.width, &vars->img.height);
	vars->img.w_img = mlx_xpm_file_to_image(vars->mlx, WALL,
			&vars->img.width, &vars->img.height);
	vars->img.c_img = mlx_xpm_file_to_image(vars->mlx, COLLECTIBLE,
			&vars->img.width, &vars->img.height);
	vars->img.back = mlx_xpm_file_to_image(vars->mlx, BACK,
			&vars->img.width, &vars->img.height);
	if (!vars->img.s_img || !vars->img.w_img
		|| !vars->img.c_img || !vars->img.back)
		my_mlx_error_handle(&vars, NULL, MLX_XPM_IMAGE);
	exit_sprite_set(vars);
	player_sprite_set_1(vars);
	player_sprite_set_2(vars);
	enemy_sprite_set_1(vars);
	enemy_sprite_set_2(vars);
}
