/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:18 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/29 17:40:14 by kkonishi         ###   ########.fr       */
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

void	*exit_if_fail(void *ptr, t_vars *vars)
{
	if (ptr == NULL)
	{
		close_window(vars);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	string_put_display(t_vars *vars)
{
	char	*step;
	char	*all;
	char	*current;
	int		height;

	height = vars->map.height * TILESIZE + 15;
	string_bar_put(vars);
	if (vars->player.clear == 1 || vars->player.clear == -1)
		return (map_clear_string_put(vars));
	mlx_string_put(vars->mlx, vars->win, 5, height, COLOR, DISP_STEP);
	step = exit_if_fail(ft_itoa(vars->player.step), vars);
	mlx_string_put(vars->mlx, vars->win, 90, height, COLOR, step);
	free(step);
	mlx_string_put(vars->mlx, vars->win, 130, height, COLOR, DISP_COLLECTIBLES);
	current = exit_if_fail(ft_itoa(vars->map.collectibles - vars->map.c_flag),
			vars);
	mlx_string_put(vars->mlx, vars->win, 220, height, COLOR, current);
	free(current);
	mlx_string_put(vars->mlx, vars->win, 230, height, COLOR, "/");
	all = exit_if_fail(ft_itoa(vars->map.collectibles), vars);
	mlx_string_put(vars->mlx, vars->win, 240, height, COLOR, all);
	free(all);
}
