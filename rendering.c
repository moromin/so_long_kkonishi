#include "so_long.h"

void	tile_path_set(t_vars *vars)
{
	vars->map.space = "images/space.xpm";
	vars->map.wall = "images/wall.xpm";
	vars->map.collectible = "images/collectible.xpm";
	vars->map.exit = "images/exit.xpm";
	vars->map.player = "images/player.xpm";
	vars->player.step = 0;
}

void	map_screen(t_vars *vars, t_data *img, char tile)
{
	char	*select;

	select = NULL;
	if (tile == '0')
		select = vars->map.space;
	else if (tile == '1')
		select = vars->map.wall;
	else if (tile == 'C')
		select = vars->map.collectible;
	else if (tile == 'E')
		select = vars->map.exit;
	else if (tile == 'P')
		select = vars->map.player;
	img->img = mlx_xpm_file_to_image(vars->mlx, select,
			&img->width, &img->height);
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
			map_screen(vars, img, vars->map.map[i][j]);
			mlx_put_image_to_window(vars->mlx, vars->win, img->img,
				j * TILESIZE, i * TILESIZE);
			if (vars->map.map[i][j] == 'P')
			{
				vars->player.i = i;
				vars->player.j = j;
			}
			j++;
		}
		i++;
	}
	printf("Player step is %d\n", vars->player.step);
}

void	update_map(t_vars *vars, int x, int y)
{
	if (vars->map.map[y][x] == 'C')
		vars->map.c_flag--;
	if (vars->map.map[y][x] == 'E' && vars->map.c_flag == 0)
	{
		printf("MAP CLEAR!\n");
		close_window(0, vars);
	}
	vars->map.map[y][x] = 'P';
	vars->map.map[vars->player.i][vars->player.j] = '0';
	free(vars->img.img);
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
