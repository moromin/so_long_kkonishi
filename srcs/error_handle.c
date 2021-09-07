/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:54:38 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/08 00:08:53 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	print_args_err(t_vars *vars)
{
	ft_putstr_fd("Error\n", 2);
	if (vars->err == ARGS_NUM_ERROR)
		ft_putstr_fd("Invalid number of arguments.\n", 2);
	if (vars->err == FILE_OPEN_ERROR)
		ft_putstr_fd("File open error.\n", 2);
	if (vars->err == INVALID_MAP_CHAR)
		ft_putstr_fd("Map includes invalid character.\n", 2);
	if (vars->err == LACK_ESSENTIAL_CHAR)
		ft_putstr_fd("Lack essential character (C, E, or P).\n", 2);
	if (vars->err == NOT_RECTANGULAR)
		ft_putstr_fd("Map is not rectangular.\n", 2);
	if (vars->err == INVALID_EXTENSION)
		ft_putstr_fd("Invalid extension file.\n", 2);
	if (vars->err == NOT_CLOSED_BY_WALL)
	{
		free_map(vars);
		ft_putstr_fd("Map is not closed by wall.\n", 2);
	}
	return (EXIT_FAILURE);
}
