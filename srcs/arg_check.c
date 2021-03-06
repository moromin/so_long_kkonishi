/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:54:35 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/30 17:48:16 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	line_check(char *line, t_vars *vars, int count)
{
	int				i;
	static size_t	line_size;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (ft_strchr(VALID_CHAR, line[i]) == NULL)
			return (INVALID_MAP_CHAR);
		if (line[i] == 'C')
			vars->map.c_flag++;
		if (line[i] == 'E')
			vars->map.e_flag++;
		if (line[i] == 'P')
			vars->map.p_flag++;
		i++;
		if (map_size_check(i, count) < 0)
			return (MAP_IS_TOO_BIG);
	}
	if (count > 0 && line_size != ft_strlen(line))
		return (NOT_RECTANGULAR);
	line_size = ft_strlen(line);
	return (vars->err);
}

int	storage_map(char *filename, size_t height, t_vars *vars)
{
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (FILE_OPEN_ERROR);
	vars->map.map = (char **)ft_calloc((height + 1), sizeof(char *));
	if (vars->map.map == NULL)
	{
		close(fd);
		return (MALLOC_ERROR);
	}
	vars->map.map[height] = NULL;
	i = 0;
	while (1)
	{
		vars->map.map[i] = get_next_line(fd);
		if (vars->map.map[i] == NULL)
			break ;
		i++;
	}
	close_check(close(fd), vars, 0);
	map_gnl_check(vars, i);
	return (-1);
}

int	closed_check(char *filename, int height, int width, t_vars *vars)
{
	int	i;
	int	j;

	if (vars->err < 0)
		vars->err = storage_map(filename, height, vars);
	if (vars->err >= 0)
		return (vars->err);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (vars->map.map[i][j] && j < width - 1)
		{
			if (((i == 0 || i == height - 1) && (j > 0 && j < width - 2)))
				if (vars->map.map[i][j] != '1')
					vars->err = NOT_CLOSED_BY_WALL;
			if ((i > 0 && i < height - 1) && (j == 0 || j == width - 2))
				if (vars->map.map[i][j] != '1')
					vars->err = NOT_CLOSED_BY_WALL;
			j++;
		}
		i++;
	}
	return (vars->err);
}

int	map_check(char *filename, t_vars *vars)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (FILE_OPEN_ERROR);
	init_map(vars);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		vars->err = line_check(line, vars, vars->map.height++);
		vars->map.width = (int)ft_strlen(line);
		free(line);
	}
	if (!vars->map.c_flag || !vars->map.e_flag || !vars->map.p_flag)
		vars->err = LACK_ESSENTIAL_CHAR;
	if (vars->map.p_flag != 1)
		vars->err = TOO_MUCH_PLAYERS;
	close_check(close(fd), vars, 1);
	vars->err = closed_check(filename, vars->map.height, vars->map.width, vars);
	return (vars->err);
}

int	args_check(int argc, char *argv[], t_vars *vars)
{
	vars->err = -1;
	if (argc != 2)
	{
		vars->err = ARGS_NUM_ERROR;
		return (vars->err);
	}
	if (extension_check(argv[1]) < 0)
	{
		vars->err = INVALID_EXTENSION;
		return (vars->err);
	}
	vars->err = map_check(argv[1], vars);
	return (vars->err);
}
