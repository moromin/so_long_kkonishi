/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:32 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/08 00:00:42 by kkonishi         ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (i < vars->map.height)
	{
		free(vars->map.map[i]);
		vars->map.map[i] = NULL;
		i++;
	}
	free(vars->map.map);
}

void	free_all_ptr(t_vars *vars)
{
	free(vars->img.img);
	free(vars->mlx);
	free(vars->win);
}

int	extension_check(char *filename)
{
	char	*extension;

	extension = ft_strchr(filename, '.');
	if (extension == NULL)
		return (-1);
	else
	{
		if (ft_strncmp(extension, ".ber", 4))
			return (-1);
	}
	return (0);
}
