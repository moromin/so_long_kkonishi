/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:20 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/21 19:17:05 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	my_mlx_error_handle(t_vars *vars, void *ptr, int mlx_type)
{
	if (ptr == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		if (mlx_type >= MLX_INIT)
			free_map(vars);
		if (mlx_type >= MLX_XPM_IMAGE)
		{
			img_ptr_destroy(vars);
			mlx_destroy_display(vars->mlx);
			free(vars->mlx);
		}
		if (mlx_type == MLX_INIT)
			ft_putstr_fd("mlx_init() return NULL.\n", 2);
		else if (mlx_type == MLX_XPM_IMAGE)
			ft_putstr_fd("mlx_xpm_file_to_image() return NULL.\n", 2);
		else if (mlx_type == MLX_NEW_WIN)
			ft_putstr_fd("mlx_new_window() return NULL.\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	map_size_check(int x, int y)
{
	if (x > DISP_WIDTH_MAX / TILESIZE || y + 1 > DISP_HEIGHT_MAX / TILESIZE)
		return (-1);
	else
		return (0);
}

void	close_check(int status, t_vars *vars, int first)
{
	if (status == -1)
	{
		if (!first)
			free_map(vars);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("File close error", 2);
		exit(EXIT_FAILURE);
	}	
}

void	map_gnl_check(t_vars *vars, int i)
{
	if (i != vars->map.height)
	{
		free_map(vars);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("GNL malloc error.\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	print_args_err(t_vars *vars)
{
	ft_putstr_fd("Error\n", 2);
	if (vars->err == ARGS_NUM_ERROR)
		ft_putstr_fd("Invalid number of arguments.\n", 2);
	if (vars->err == FILE_OPEN_ERROR)
		ft_putstr_fd("File open error.\n", 2);
	if (vars->err == INVALID_MAP_CHAR)
		ft_putstr_fd("Map includes invalid character.\n", 2);
	if (vars->err == LACK_ESSENTIAL_CHAR_BONUS)
		ft_putstr_fd("Lack essential character (C, E, P or T).\n", 2);
	if (vars->err == NOT_RECTANGULAR)
		ft_putstr_fd("Map is not rectangular.\n", 2);
	if (vars->err == INVALID_EXTENSION)
		ft_putstr_fd("Invalid extension file.\n", 2);
	if (vars->err == NOT_CLOSED_BY_WALL)
		ft_putstr_fd("Map is not closed by wall.\n", 2);
	if (vars->err == MAP_IS_TOO_SMALL)
		ft_putstr_fd("Map is too small.\n", 2);
	if (vars->err == MAP_IS_TOO_BIG)
		ft_putstr_fd("Map is too big to display.\n", 2);
	if (vars->err == NOT_CLOSED_BY_WALL)
		free_map(vars);
	if (vars->err == MAP_IS_TOO_SMALL)
		close_window(vars);
	return (EXIT_FAILURE);
}
