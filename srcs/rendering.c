/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:54:47 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/15 23:32:03 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		img_ptr = img->e_img;
	else if (tile == 'P')
		img_ptr = img->p_img;
	mlx_put_image_to_window(vars->mlx, vars->win, img_ptr,
		j * TILESIZE, i * TILESIZE);
}

void	rendering_main(t_vars *vars, t_data *img, int count)
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
			j++;
		}
		i++;
	}
	if (count == 1)
		printf("Player step is %d\n", vars->player.step);
}

void	update_map(t_vars *vars, int x, int y)
{
	if (vars->map.map[y][x] == 'C')
		vars->map.c_flag--;
	if (vars->map.map[y][x] == 'E' && vars->map.c_flag == 0)
	{
		printf("Player step is %d\n", vars->player.step);
		printf("MAP CLEAR!\n");
		close_window(vars);
	}
	vars->map.map[y][x] = 'P';
	vars->map.map[vars->player.i][vars->player.j] = '0';
	rendering_main(vars, &vars->img, 1);
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
