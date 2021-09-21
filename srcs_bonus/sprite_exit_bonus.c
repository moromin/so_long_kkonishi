/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_exit_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:27 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/21 18:48:27 by kkonishi         ###   ########.fr       */
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

void	exit_sprite_set(t_vars *vars)
{
	vars->img.e_1_img = mlx_xpm_file_to_image(vars->mlx, EXIT_1,
			&vars->img.width, &vars->img.height);
	vars->img.e_2_img = mlx_xpm_file_to_image(vars->mlx, EXIT_2,
			&vars->img.width, &vars->img.height);
	vars->img.e_3_img = mlx_xpm_file_to_image(vars->mlx, EXIT_3,
			&vars->img.width, &vars->img.height);
	if (!vars->img.e_1_img || !vars->img.e_2_img || !vars->img.e_3_img)
		my_mlx_error_handle(vars, NULL, MLX_XPM_IMAGE);
}
