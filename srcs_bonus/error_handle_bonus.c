/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:55:20 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/13 23:25:48 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	{
		free_map(vars);
		ft_putstr_fd("Map is not closed by wall.\n", 2);
	}
	if (vars->err == MAP_IS_TOO_SMALL)
	{
		ft_putstr_fd("Map is too small.\n", 2);
		close_window(vars);
	}
	return (EXIT_FAILURE);
}
