/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:27 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/21 18:25:19 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	*sprite_player_direction_sd(t_vars *vars, t_data *img)
{
	void	*img_ptr;
	int		key;

	img_ptr = NULL;
	key = vars->player.key;
	if (vars->player.frame == 1 && key == S_KEY)
		img_ptr = img->p_s_1_img;
	if (vars->player.frame == 2 && key == S_KEY)
		img_ptr = img->p_s_2_img;
	if (vars->player.frame == 3 && key == S_KEY)
		img_ptr = img->p_s_3_img;
	if (vars->player.frame == 1 && key == D_KEY)
		img_ptr = img->p_d_1_img;
	if (vars->player.frame == 2 && key == D_KEY)
		img_ptr = img->p_d_2_img;
	if (vars->player.frame == 3 && key == D_KEY)
		img_ptr = img->p_d_3_img;
	return (img_ptr);
}

void	*sprite_player_direction_wa(t_vars *vars, t_data *img)
{
	void	*img_ptr;
	int		key;

	img_ptr = NULL;
	key = vars->player.key;
	if (vars->player.frame == 1 && key == W_KEY)
		img_ptr = img->p_w_1_img;
	if (vars->player.frame == 2 && key == W_KEY)
		img_ptr = img->p_w_2_img;
	if (vars->player.frame == 3 && key == W_KEY)
		img_ptr = img->p_w_3_img;
	if (vars->player.frame == 1 && key == A_KEY)
		img_ptr = img->p_a_1_img;
	if (vars->player.frame == 2 && key == A_KEY)
		img_ptr = img->p_a_2_img;
	if (vars->player.frame == 3 && key == A_KEY)
		img_ptr = img->p_a_3_img;
	return (img_ptr);
}

void	sprite_player(t_vars *vars, t_data *img, int i, int j)
{
	void	*img_ptr;
	int		key;

	img_ptr = NULL;
	key = vars->player.key;
	if (vars->player.key == S_KEY || vars->player.key == D_KEY)
		img_ptr = sprite_player_direction_sd(vars, img);
	if (vars->player.key == W_KEY || vars->player.key == A_KEY)
		img_ptr = sprite_player_direction_wa(vars, img);
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		mlx_put_image_to_window(vars->mlx, vars->win, img_ptr,
			j * TILESIZE, i * TILESIZE);
}

void	player_sprite_set_1(t_vars *vars)
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
	if (!vars->img.p_w_1_img || !vars->img.p_w_2_img || !vars->img.p_w_3_img
		|| !vars->img.p_a_1_img || !vars->img.p_a_2_img || !vars->img.p_a_3_img)
		my_mlx_error_handle(&vars, NULL, MLX_XPM_IMAGE);
}

void	player_sprite_set_2(t_vars *vars)
{
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
	if (!vars->img.p_d_1_img || !vars->img.p_d_2_img || !vars->img.p_d_3_img
		|| !vars->img.p_s_1_img || !vars->img.p_s_2_img || !vars->img.p_s_3_img)
		my_mlx_error_handle(&vars, NULL, MLX_XPM_IMAGE);
}
