#include "so_long.h"

void	init_map(t_vars *vars)
{
	vars->map.c_flag = 0;
	vars->map.e_flag = 0;
	vars->map.p_flag = 0;
	vars->map.width = 0;
	vars->map.height = 0;
}

int	line_check(char *line, t_vars *vars)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (ft_strchr(VALID_CHAR, line[i]) == NULL)
			return (INVALID_MAP_CHAR);
		if (line[i] == 'C')
			vars->map.c_flag = 1;
		if (line[i] == 'E')
			vars->map.e_flag = 1;
		if (line[i] == 'P')
			vars->map.p_flag = 1;
		i++;
	}
	if (!vars->map.c_flag || !vars->map.e_flag || !vars->map.p_flag)
		return (LACK_ESSENTIAL_CHAR);
	return (vars->err);
}

int	map_check(char *argv, t_vars *vars)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (FILE_OPEN_ERROR);
	init_map(vars);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		vars->err = line_check(line, vars);
		free(line);
		vars->map.height++;
	}
	close(fd);
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
	vars->err = map_check(argv[1], vars);
	return (vars->err);
}
