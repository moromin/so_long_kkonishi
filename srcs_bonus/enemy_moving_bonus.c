/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moving_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:12:21 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/17 13:29:11 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	enemy_tracing_1(t_vars *vars, int *x, int *y)
{
	if (*x == vars->player.j)
	{
		if (*y > vars->player.i)
			(*y)--;
		else
			(*y)++;
		return (0);
	}
	if (*y == vars->player.i)
	{
		if (*x > vars->player.j)
			(*x)--;
		else
			(*x)++;
		return (0);
	}
	return (-1);
}

void	enemy_tracing_2(t_vars *vars, int *x, int *y)
{
	int	x_diff;
	int	y_diff;
	int	x_abs;
	int	y_abs;

	x_diff = *x - vars->player.j;
	y_diff = *y - vars->player.i;
	x_abs = *x - vars->player.j;
	y_abs = *y - vars->player.i;
	if (x_abs < 0)
		x_abs *= -1;
	if (y_abs < 0)
		y_abs *= -1;
	if ((x_abs <= y_abs) && x_diff < 0)
		(*x)++;
	if ((x_abs <= y_abs) && x_diff > 0)
		(*x)--;
	if ((y_abs < x_abs) && y_diff < 0)
		(*y)++;
	if ((y_abs < x_abs) && y_diff > 0)
		(*y)--;
}

void	enemy_direction(t_vars *vars, int x, int y)
{
	if (x > vars->enemy.j)
		vars->enemy.direction = D_KEY;
	if (x < vars->enemy.j)
		vars->enemy.direction = A_KEY;
	if (y < vars->enemy.i)
		vars->enemy.direction = W_KEY;
	if (y > vars->enemy.i)
		vars->enemy.direction = S_KEY;
}

void	update_enemy_map(t_vars *vars, int x, int y)
{
	if (vars->map.map[y][x] == 'P')
		vars->player.clear = -1;
	vars->map.map[y][x] = 'T';
	vars->map.map[vars->enemy.i][vars->enemy.j] = '0';
	rendering_main(vars, &vars->img);
}

void	moving_enemy(t_vars *vars)
{
	int		x;
	int		y;
	char	tile;

	x = vars->enemy.j;
	y = vars->enemy.i;
	if (enemy_tracing_1(vars, &x, &y) < 0)
		enemy_tracing_2(vars, &x, &y);
	enemy_direction(vars, x, y);
	if (x < 0 || x > (int)vars->map.width - 2)
		return ;
	if (y < 0 || y > (int)vars->map.height - 1)
		return ;
	tile = vars->map.map[y][x];
	if (tile == '1' || tile == 'E' || tile == 'C')
		return ;
	update_enemy_map(vars, x, y);
}
