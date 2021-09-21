/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:32 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/21 22:37:49 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_map(t_vars *vars)
{
	vars->map.c_flag = 0;
	vars->map.e_flag = 0;
	vars->map.p_flag = 0;
	vars->map.t_flag = 0;
	vars->map.width = 0;
	vars->map.height = 0;
}

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map.height)
	{
		free(vars->map.map[i]);
		vars->map.map[i] = NULL;
		i++;
	}
	free(vars->map.map);
}

int	is_valid_extension(char *filename)
{
	char	*extension;

	extension = ft_strchr(filename, '.');
	if (extension == NULL)
		return (0);
	else
	{
		if (ft_strcmp(extension, ".ber"))
			return (0);
	}
	return (1);
}

void	screen_size_check(t_vars *vars, int width, int height)
{
	int	width_win;
	int	height_win;

	mlx_get_screen_size(vars->mlx, &width_win, &height_win);
	if (height + 20 > height_win || width > width_win)
	{
		free_map(vars);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Map size is too big to display.", 2);
		exit(EXIT_FAILURE);
	}
}
