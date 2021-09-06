#include "../includes/so_long_bonus.h"

void	player_sprite_set(t_vars *vars)
{
	vars->img.p_w_1_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_W_1,
			&vars->img.width, &vars->img.height);
	vars->img.p_w_2_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_W_2,
			&vars->img.width, &vars->img.height);
	vars->img.p_w_3_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_W_3,
			&vars->img.width, &vars->img.height);
	vars->img.p_a_1_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_A_1,
			&vars->img.width, &vars->img.height);
	vars->img.p_a_2_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_A_2,
			&vars->img.width, &vars->img.height);
	vars->img.p_a_3_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_A_3,
			&vars->img.width, &vars->img.height);
	vars->img.p_d_1_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_D_1,
			&vars->img.width, &vars->img.height);
	vars->img.p_d_2_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_D_2,
			&vars->img.width, &vars->img.height);
	vars->img.p_d_3_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_D_3,
			&vars->img.width, &vars->img.height);
	vars->img.p_s_1_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_S_1,
			&vars->img.width, &vars->img.height);
	vars->img.p_s_2_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_S_2,
			&vars->img.width, &vars->img.height);
	vars->img.p_s_3_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_S_3,
			&vars->img.width, &vars->img.height);
}

void	enemy_sprite_set(t_vars *vars)
{
	vars->img.t_w_1_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_W_1,
			&vars->img.width, &vars->img.height);
	vars->img.t_w_2_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_W_2,
			&vars->img.width, &vars->img.height);
	vars->img.t_w_3_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_W_3,
			&vars->img.width, &vars->img.height);
	vars->img.t_a_1_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_A_1,
			&vars->img.width, &vars->img.height);
	vars->img.t_a_2_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_A_2,
			&vars->img.width, &vars->img.height);
	vars->img.t_a_3_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_A_3,
			&vars->img.width, &vars->img.height);
	vars->img.t_d_1_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_D_1,
			&vars->img.width, &vars->img.height);
	vars->img.t_d_2_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_D_2,
			&vars->img.width, &vars->img.height);
	vars->img.t_d_3_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_D_3,
			&vars->img.width, &vars->img.height);
	vars->img.t_s_1_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_S_1,
			&vars->img.width, &vars->img.height);
	vars->img.t_s_2_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_S_2,
			&vars->img.width, &vars->img.height);
	vars->img.t_s_3_img = mlx_xpm_file_to_image(vars->mlx, ENEMY_S_3,
			&vars->img.width, &vars->img.height);
}

void	tile_path_set(t_vars *vars)
{
	vars->map.collectibles = vars->map.c_flag;
	vars->player.step = 0;
	vars->player.frame = 1;
	vars->img.s_img = mlx_xpm_file_to_image(vars->mlx, SPACE,
			&vars->img.width, &vars->img.height);
	vars->img.w_img = mlx_xpm_file_to_image(vars->mlx, WALL,
			&vars->img.width, &vars->img.height);
	vars->img.c_img = mlx_xpm_file_to_image(vars->mlx, COLLECTIBLE,
			&vars->img.width, &vars->img.height);
	vars->img.e_img = mlx_xpm_file_to_image(vars->mlx, EXIT,
			&vars->img.width, &vars->img.height);
	player_sprite_set(vars);
	enemy_sprite_set(vars);
}
