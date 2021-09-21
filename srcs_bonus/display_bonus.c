/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:18 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/21 18:16:54 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	string_bar_put(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = vars->map.height * TILESIZE;
	while (x < (vars->map.width - 1))
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.back,
			x * TILESIZE, y);
		x++;
	}
}

void	map_clear_string_put(t_vars *vars)
{
	if (vars->player.clear == 1)
		mlx_string_put(vars->mlx, vars->win, 5,
			vars->map.height * TILESIZE + 15, COLOR, "MAP CLEAR!!");
	else
		mlx_string_put(vars->mlx, vars->win, 5,
			vars->map.height * TILESIZE + 15, COLOR, "YOU LOSE...");
}

void	string_put_display(t_vars *vars)
{
	char	*step;
	char	*all;
	char	*current;

	string_bar_put(vars);
	if (vars->player.clear == 1 || vars->player.clear == -1)
		return (map_clear_string_put(vars));
	step = ft_itoa(vars->player.step);
	all = ft_itoa(vars->map.collectibles);
	current = ft_itoa(vars->map.collectibles - vars->map.c_flag);
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
	free(step);
	free(all);
	free(current);
}
