/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:54:06 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/15 00:10:47 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define VALID_CHAR "01CEP"
# define VALID_CHAR_BONUS "01CEPT"

# define DISP_STEP "PLAYER STEP :"
# define DISP_COLLECTIBLES "COLLECTIBLES :"
# define DISP_CLEAR "MAP CLEAR!"
# define COLOR 0x00FFDAB9

# define SPACE "images/space.xpm"
# define WALL "images/wall.xpm"
# define COLLECTIBLE "images/collectible.xpm"
# define EXIT "images/exit.xpm"
# define BACK "images/back.xpm"

# define PLAYER_S_1 "images/player_sprite/sprite1.xpm"
# define PLAYER_S_2 "images/player_sprite/sprite2.xpm"
# define PLAYER_S_3 "images/player_sprite/sprite3.xpm"
# define PLAYER_A_1 "images/player_sprite/sprite4.xpm"
# define PLAYER_A_2 "images/player_sprite/sprite5.xpm"
# define PLAYER_A_3 "images/player_sprite/sprite6.xpm"
# define PLAYER_D_1 "images/player_sprite/sprite7.xpm"
# define PLAYER_D_2 "images/player_sprite/sprite8.xpm"
# define PLAYER_D_3 "images/player_sprite/sprite9.xpm"
# define PLAYER_W_1 "images/player_sprite/sprite10.xpm"
# define PLAYER_W_2 "images/player_sprite/sprite11.xpm"
# define PLAYER_W_3 "images/player_sprite/sprite12.xpm"

# define ENEMY_S_1 "images/enemy_sprite/sprite1.xpm"
# define ENEMY_S_2 "images/enemy_sprite/sprite2.xpm"
# define ENEMY_S_3 "images/enemy_sprite/sprite3.xpm"
# define ENEMY_A_1 "images/enemy_sprite/sprite4.xpm"
# define ENEMY_A_2 "images/enemy_sprite/sprite5.xpm"
# define ENEMY_A_3 "images/enemy_sprite/sprite6.xpm"
# define ENEMY_D_1 "images/enemy_sprite/sprite7.xpm"
# define ENEMY_D_2 "images/enemy_sprite/sprite8.xpm"
# define ENEMY_D_3 "images/enemy_sprite/sprite9.xpm"
# define ENEMY_W_1 "images/enemy_sprite/sprite10.xpm"
# define ENEMY_W_2 "images/enemy_sprite/sprite11.xpm"
# define ENEMY_W_3 "images/enemy_sprite/sprite12.xpm"

# define EXIT_1 "images/exit_sprite/sprite1.xpm"
# define EXIT_2 "images/exit_sprite/sprite2.xpm"
# define EXIT_3 "images/exit_sprite/sprite3.xpm"

# define ARGS_NUM_ERROR 0
# define FILE_OPEN_ERROR 1
# define INVALID_MAP_CHAR 2
# define LACK_ESSENTIAL_CHAR 3
# define NOT_RECTANGULAR 4
# define NOT_CLOSED_BY_WALL 5
# define LACK_ESSENTIAL_CHAR_BONUS 6
# define INVALID_EXTENSION 7
# define MAP_IS_TOO_SMALL 8

# define MALLOC_ERROR 10

# define TILESIZE 48

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

#endif
