/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:25 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/15 00:20:30 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	map_screen(t_vars *vars, t_data *img, int i, int j)
{
	void	*img_ptr;
	char	tile;

	tile = vars->map.map[i][j];
	img_ptr = NULL;
	if (tile == '1')
		img_ptr = img->w_img;
	else if (tile == '0')
		img_ptr = img->s_img;
	else if (tile == 'C')
		img_ptr = img->c_img;
	else if (tile == 'E')
		sprite_exit(vars, img, i, j);
	else if (tile == 'P')
		sprite_player(vars, img, i, j);
	else if (tile == 'T')
		sprite_enemy(vars, img, i, j);
	if (tile != 'P' && tile != 'E' && tile != 'T')
		mlx_put_image_to_window(vars->mlx, vars->win, img_ptr,
			j * TILESIZE, i * TILESIZE);
}

void	rendering_main(t_vars *vars, t_data *img)
{
	int		i;
	int		j;

	i = 0;
	while (vars->map.map[i])
	{
		j = 0;
		while (vars->map.map[i][j] != '\n')
		{
			map_screen(vars, img, i, j);
			if (vars->map.map[i][j] == 'P')
			{
				vars->player.i = i;
				vars->player.j = j;
			}
			if (vars->map.map[i][j] == 'T')
			{
				vars->enemy.i = i;
				vars->enemy.j = j;
			}
			j++;
		}
		i++;
	}
	string_put_display(vars);
}

void	update_map(t_vars *vars, int x, int y)
{
	if (vars->map.map[y][x] == 'C')
		vars->map.c_flag--;
	if (vars->map.map[y][x] == 'E' && vars->map.c_flag == 0)
		vars->player.clear = 1;
	if (vars->map.map[y][x] == 'T')
		vars->player.clear = -1;
	if (vars->player.clear == 0)
		vars->map.map[y][x] = 'P';
	if (vars->player.clear == 1)
		vars->map.map[y][x] = 'E';
	if (vars->player.clear == -1)
		vars->map.map[y][x] = 'T';
	vars->map.map[vars->player.i][vars->player.j] = '0';
	rendering_main(vars, &vars->img);
}

void	moving_player(int code, t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player.j;
	y = vars->player.i;
	if (code == W_KEY)
		y--;
	else if (code == A_KEY)
		x--;
	else if (code == S_KEY)
		y++;
	else if (code == D_KEY)
		x++;
	if (vars->map.map[y][x] == 'E' && vars->map.c_flag != 0)
		return ;
	if (vars->map.map[y][x] == '1')
		return ;
	vars->player.step++;
	update_map(vars, x, y);
}
