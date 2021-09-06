#include "../includes/so_long_bonus.h"

void	tile_path_set(t_vars *vars)
{
	vars->map.collectibles = vars->map.c_flag;
	vars->player.step = 0;
	vars->img.s_img = mlx_xpm_file_to_image(vars->mlx, SPACE,
			&vars->img.width, &vars->img.height);
	vars->img.w_img = mlx_xpm_file_to_image(vars->mlx, WALL,
			&vars->img.width, &vars->img.height);
	vars->img.c_img = mlx_xpm_file_to_image(vars->mlx, COLLECTIBLE,
			&vars->img.width, &vars->img.height);
	vars->img.e_img = mlx_xpm_file_to_image(vars->mlx, EXIT,
			&vars->img.width, &vars->img.height);
	vars->img.p_img = mlx_xpm_file_to_image(vars->mlx, PLAYER,
			&vars->img.width, &vars->img.height);
	vars->img.t_img = mlx_xpm_file_to_image(vars->mlx, ENEMY,
			&vars->img.width, &vars->img.height);
	vars->img.p_s_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_SPRITE,
			&vars->img.width, &vars->img.height);
	vars->img.t_s_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_SPRITE,
			&vars->img.width, &vars->img.height);
}

void	img_ptr_destroy(t_vars *vars)
{
	if (vars->img.s_img)
		mlx_destroy_image(vars->mlx, vars->img.s_img);
	if (vars->img.w_img)
		mlx_destroy_image(vars->mlx, vars->img.w_img);
	if (vars->img.e_img)
		mlx_destroy_image(vars->mlx, vars->img.e_img);
	if (vars->img.c_img)
		mlx_destroy_image(vars->mlx, vars->img.c_img);
	if (vars->img.p_img)
		mlx_destroy_image(vars->mlx, vars->img.p_img);
	if (vars->img.t_img)
		mlx_destroy_image(vars->mlx, vars->img.t_img);
	if (vars->img.p_s_img)
		mlx_destroy_image(vars->mlx, vars->img.p_s_img);
	if (vars->img.t_s_img)
		mlx_destroy_image(vars->mlx, vars->img.t_s_img);
}
