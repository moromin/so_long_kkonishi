#include "../includes/so_long_bonus.h"

int	close_window(t_vars *vars)
{
	free_map(vars);
	img_ptr_destroy(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

void	destroy_player(t_vars *vars)
{
	if (vars->img.p_w_1_img)
		mlx_destroy_image(vars->mlx, vars->img.p_w_1_img);
	if (vars->img.p_w_2_img)
		mlx_destroy_image(vars->mlx, vars->img.p_w_2_img);
	if (vars->img.p_w_3_img)
		mlx_destroy_image(vars->mlx, vars->img.p_w_3_img);
	if (vars->img.p_a_1_img)
		mlx_destroy_image(vars->mlx, vars->img.p_a_1_img);
	if (vars->img.p_a_2_img)
		mlx_destroy_image(vars->mlx, vars->img.p_a_2_img);
	if (vars->img.p_a_3_img)
		mlx_destroy_image(vars->mlx, vars->img.p_a_3_img);
	if (vars->img.p_s_1_img)
		mlx_destroy_image(vars->mlx, vars->img.p_s_1_img);
	if (vars->img.p_s_2_img)
		mlx_destroy_image(vars->mlx, vars->img.p_s_2_img);
	if (vars->img.p_s_3_img)
		mlx_destroy_image(vars->mlx, vars->img.p_s_3_img);
	if (vars->img.p_d_1_img)
		mlx_destroy_image(vars->mlx, vars->img.p_d_1_img);
	if (vars->img.p_d_2_img)
		mlx_destroy_image(vars->mlx, vars->img.p_d_2_img);
	if (vars->img.p_d_3_img)
		mlx_destroy_image(vars->mlx, vars->img.p_d_3_img);
}

void	destroy_enemy(t_vars *vars)
{
	if (vars->img.t_w_1_img)
		mlx_destroy_image(vars->mlx, vars->img.t_w_1_img);
	if (vars->img.t_w_2_img)
		mlx_destroy_image(vars->mlx, vars->img.t_w_2_img);
	if (vars->img.t_w_3_img)
		mlx_destroy_image(vars->mlx, vars->img.t_w_3_img);
	if (vars->img.t_a_1_img)
		mlx_destroy_image(vars->mlx, vars->img.t_a_1_img);
	if (vars->img.t_a_2_img)
		mlx_destroy_image(vars->mlx, vars->img.t_a_2_img);
	if (vars->img.t_a_3_img)
		mlx_destroy_image(vars->mlx, vars->img.t_a_3_img);
	if (vars->img.t_s_1_img)
		mlx_destroy_image(vars->mlx, vars->img.t_s_1_img);
	if (vars->img.t_s_2_img)
		mlx_destroy_image(vars->mlx, vars->img.t_s_2_img);
	if (vars->img.t_s_3_img)
		mlx_destroy_image(vars->mlx, vars->img.t_s_3_img);
	if (vars->img.t_d_1_img)
		mlx_destroy_image(vars->mlx, vars->img.t_d_1_img);
	if (vars->img.t_d_2_img)
		mlx_destroy_image(vars->mlx, vars->img.t_d_2_img);
	if (vars->img.t_d_3_img)
		mlx_destroy_image(vars->mlx, vars->img.t_d_3_img);
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
	destroy_player(vars);
	destroy_enemy(vars);
}
