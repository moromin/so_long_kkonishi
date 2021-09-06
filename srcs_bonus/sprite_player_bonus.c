#include "../includes/so_long_bonus.h"

void	*sprite_player_direction_sd(t_vars *vars, t_data *img)
{
	void	*img_ptr;
	int		key;

	img_ptr = NULL;
	key = vars->player.key;
	if (vars->player.frame == 1 && key == S_KEY)
		img_ptr = img->p_s_1_img;
	if (vars->player.frame == 2 && key == S_KEY)
		img_ptr = img->p_s_2_img;
	if (vars->player.frame == 3 && key == S_KEY)
		img_ptr = img->p_s_3_img;
	if (vars->player.frame == 1 && key == D_KEY)
		img_ptr = img->p_d_1_img;
	if (vars->player.frame == 2 && key == D_KEY)
		img_ptr = img->p_d_2_img;
	if (vars->player.frame == 3 && key == D_KEY)
		img_ptr = img->p_d_3_img;
	return (img_ptr);
}

void	*sprite_player_direction_wa(t_vars *vars, t_data *img)
{
	void	*img_ptr;
	int		key;

	img_ptr = NULL;
	key = vars->player.key;
	if (vars->player.frame == 1 && key == W_KEY)
		img_ptr = img->p_w_1_img;
	if (vars->player.frame == 2 && key == W_KEY)
		img_ptr = img->p_w_2_img;
	if (vars->player.frame == 3 && key == W_KEY)
		img_ptr = img->p_w_3_img;
	if (vars->player.frame == 1 && key == A_KEY)
		img_ptr = img->p_a_1_img;
	if (vars->player.frame == 2 && key == A_KEY)
		img_ptr = img->p_a_2_img;
	if (vars->player.frame == 3 && key == A_KEY)
		img_ptr = img->p_a_3_img;
	return (img_ptr);
}

void	sprite_player(t_vars *vars, t_data *img, int i, int j)
{
	void	*img_ptr;
	int		key;

	img_ptr = NULL;
	key = vars->player.key;
	if (vars->player.key == S_KEY || vars->player.key == D_KEY)
		img_ptr = sprite_player_direction_sd(vars, img);
	if (vars->player.key == W_KEY || vars->player.key == A_KEY)
		img_ptr = sprite_player_direction_wa(vars, img);
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		mlx_put_image_to_window(vars->mlx, vars->win, img_ptr,
			j * TILESIZE, i * TILESIZE);
}
