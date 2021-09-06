/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:18 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/06 20:01:48 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	string_bar_put(t_vars *vars)
{
	int	x;
	int	y;

	y = 1;
	while (y <= 20)
	{
		x = 90;
		while (x <= 110)
			mlx_pixel_put(vars->mlx, vars->win, x++,
				y + vars->map.height * TILESIZE, 0x00000000);
		x = 220;
		while (x <= 230)
			mlx_pixel_put(vars->mlx, vars->win, x++,
				y + vars->map.height * TILESIZE, 0x00000000);
		y++;
	}
}

void	string_put_display(t_vars *vars)
{
	char	*step;
	char	*all;
	char	*current;

	step = ft_itoa(vars->player.step);
	all = ft_itoa(vars->map.collectibles);
	current = ft_itoa(vars->map.collectibles - vars->map.c_flag);
	string_bar_put(vars);
	mlx_string_put(vars->mlx, vars->win, 5, vars->map.height * TILESIZE + 15,
		COLOR, DISP_STEP);
	mlx_string_put(vars->mlx, vars->win, 90, vars->map.height * TILESIZE + 15,
		COLOR, step);
	mlx_string_put(vars->mlx, vars->win, 130, vars->map.height * TILESIZE + 15,
		COLOR, DISP_COLLECTIBLES);
	mlx_string_put(vars->mlx, vars->win, 220, vars->map.height * TILESIZE + 15,
		COLOR, current);
	mlx_string_put(vars->mlx, vars->win, 230, vars->map.height * TILESIZE + 15,
		COLOR, "/");
	mlx_string_put(vars->mlx, vars->win, 240, vars->map.height * TILESIZE + 15,
		COLOR, all);
		// printf("step:%d\n", vars->player.step);
	free(step);
	free(all);
	free(current);
}
