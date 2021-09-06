/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 20:54:04 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/06 23:15:08 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	*sprite_enemy_direction_sd(t_vars *vars, t_data *img)
{
	void	*img_ptr;
	int		key;

	img_ptr = NULL;
	key = vars->enemy.direction;
	if (vars->player.frame == 1 && key == S_KEY)
		img_ptr = img->t_s_1_img;
	if (vars->player.frame == 2 && key == S_KEY)
		img_ptr = img->t_s_2_img;
	if (vars->player.frame == 3 && key == S_KEY)
		img_ptr = img->t_s_3_img;
	if (vars->player.frame == 1 && key == D_KEY)
		img_ptr = img->t_d_1_img;
	if (vars->player.frame == 2 && key == D_KEY)
		img_ptr = img->t_d_2_img;
	if (vars->player.frame == 3 && key == D_KEY)
		img_ptr = img->t_d_3_img;
	return (img_ptr);
}

void	*sprite_enemy_direction_wa(t_vars *vars, t_data *img)
{
	void	*img_ptr;
	int		key;

	img_ptr = NULL;
	key = vars->enemy.direction;
	if (vars->player.frame == 1 && key == W_KEY)
		img_ptr = img->t_w_1_img;
	if (vars->player.frame == 2 && key == W_KEY)
		img_ptr = img->t_w_2_img;
	if (vars->player.frame == 3 && key == W_KEY)
		img_ptr = img->t_w_3_img;
	if (vars->player.frame == 1 && key == A_KEY)
		img_ptr = img->t_a_1_img;
	if (vars->player.frame == 2 && key == A_KEY)
		img_ptr = img->t_a_2_img;
	if (vars->player.frame == 3 && key == A_KEY)
		img_ptr = img->t_a_3_img;
	return (img_ptr);
}

void	sprite_enemy(t_vars *vars, t_data *img, int i, int j)
{
	void	*img_ptr;
	int		key;

	img_ptr = NULL;
	key = vars->player.key;
	if (vars->enemy.direction == S_KEY || vars->enemy.direction == D_KEY)
		img_ptr = sprite_enemy_direction_sd(vars, img);
	if (vars->enemy.direction == W_KEY || vars->enemy.direction == A_KEY)
		img_ptr = sprite_enemy_direction_wa(vars, img);
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		mlx_put_image_to_window(vars->mlx, vars->win, img_ptr,
			j * TILESIZE, i * TILESIZE);
	return ;
}
