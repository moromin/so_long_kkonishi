/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_exit_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:27 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/06 19:37:44 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	sprite_exit(t_vars *vars, t_data *img, int i, int j)
{
	void	*img_ptr;
	int		frame;

	img_ptr = NULL;
	frame = vars->player.frame;
	if (frame == 1)
		img_ptr = img->e_1_img;
	if (frame == 2)
		img_ptr = img->e_2_img;
	if (frame == 3)
		img_ptr = img->e_3_img;
	mlx_put_image_to_window(vars->mlx, vars->win, img_ptr,
		j * TILESIZE, i * TILESIZE);
}
