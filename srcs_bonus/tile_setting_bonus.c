/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_setting_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:30 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/06 23:40:41 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	player_sprite_set(t_vars *vars)
{
	vars->img.p_w_1_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_W_1,
			&vars->img.width, &vars->img.height);
	vars->img.p_w_2_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_W_2,
			&vars->img.width, &vars->img.height);
	vars->img.p_w_3_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_W_3,
			&vars->img.width, &vars->img.height);
	vars->img.p_a_1_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_A_1,
			&vars->img.width, &vars->img.height);
	vars->img.p_a_2_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_A_2,
			&vars->img.width, &vars->img.height);
	vars->img.p_a_3_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_A_3,
			&vars->img.width, &vars->img.height);
	vars->img.p_d_1_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_D_1,
			&vars->img.width, &vars->img.height);
	vars->img.p_d_2_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_D_2,
			&vars->img.width, &vars->img.height);
	vars->img.p_d_3_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_D_3,
			&vars->img.width, &vars->img.height);
	vars->img.p_s_1_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_S_1,
			&vars->img.width, &vars->img.height);
	vars->img.p_s_2_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_S_2,
			&vars->img.width, &vars->img.height);
	vars->img.p_s_3_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_S_3,
			&vars->img.width, &vars->img.height);
}

void	enemy_sprite_set(t_vars *vars)
{
	vars->img.t_w_1_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_W_1,
			&vars->img.width, &vars->img.height);
	vars->img.t_w_2_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_W_2,
			&vars->img.width, &vars->img.height);
	vars->img.t_w_3_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_W_3,
			&vars->img.width, &vars->img.height);
	vars->img.t_a_1_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_A_1,
			&vars->img.width, &vars->img.height);
	vars->img.t_a_2_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_A_2,
			&vars->img.width, &vars->img.height);
	vars->img.t_a_3_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_A_3,
			&vars->img.width, &vars->img.height);
	vars->img.t_d_1_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_D_1,
			&vars->img.width, &vars->img.height);
	vars->img.t_d_2_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_D_2,
			&vars->img.width, &vars->img.height);
	vars->img.t_d_3_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_D_3,
			&vars->img.width, &vars->img.height);
	vars->img.t_s_1_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_W_1,
			&vars->img.width, &vars->img.height);
	vars->img.t_s_2_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_W_2,
			&vars->img.width, &vars->img.height);
	vars->img.t_s_3_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_W_3,
			&vars->img.width, &vars->img.height);
}

void	exit_sprite_set(t_vars *vars)
{
	vars->img.e_1_img = mlx_xpm_file_to_image(vars->mlx, EXIT_1,
			&vars->img.width, &vars->img.height);
	vars->img.e_2_img = mlx_xpm_file_to_image(vars->mlx, EXIT_2,
			&vars->img.width, &vars->img.height);
	vars->img.e_3_img = mlx_xpm_file_to_image(vars->mlx, EXIT_3,
			&vars->img.width, &vars->img.height);
}

void	tile_path_set(t_vars *vars)
{
	vars->map.collectibles = vars->map.c_flag;
	vars->player.step = 0;
	vars->player.frame = 1;
	vars->player.key = S_KEY;
	vars->enemy.direction = S_KEY;
	vars->img.s_img = mlx_xpm_file_to_image(vars->mlx, SPACE,
			&vars->img.width, &vars->img.height);
	vars->img.w_img = mlx_xpm_file_to_image(vars->mlx, WALL,
			&vars->img.width, &vars->img.height);
	vars->img.c_img = mlx_xpm_file_to_image(vars->mlx, COLLECTIBLE,
			&vars->img.width, &vars->img.height);
	exit_sprite_set(vars);
	player_sprite_set(vars);
	enemy_sprite_set(vars);
}
