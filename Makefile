NAME	= so_long
SRC		= 	main.c \
			arg_check.c \
			error_handle.c \
			utils.c \
			rendering.c
B_SRC	=	main_bonus.c \
			arg_check_bonus.c \
			error_handle_bonus.c \
			utils_bonus.c \
			rendering_bonus.c \
			display_bonus.c \
			tile_setting_bonus.c \
			destroy_ptr_bonus.c \
			sprite_player_bonus.c \
			sprite_exit_bonus.c \
			sprite_enemy_bonus.c \
			enemy_moving_bonus.c
SRCDIR	= ./srcs
B_SRCDIR  = ./srcs_bonus
INCDIR 	= includes
SRCS	= $(addprefix $(SRCDIR)/, $(SRC))
B_SRCS	= $(addprefix $(B_SRCDIR)/, $(B_SRC))
OBJS    = $(SRCS:%.c=%.o)
B_OBJS  = $(B_SRCS:%.c=%.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIBFTPATH	= ./libft/
LIBFTFLAG	= -Llibft -lft
GNLPATH = ./get_next_line/
GNLFLAG = -Lget_next_line -lgnl
MLXPATH = ./mlx_linux/
MLXFLAG = -Lmlx_linux -lmlx  -lXext -lX11 -lm -lbsd -Imlx_linux
GITMLX	= git clone https://github.com/42Paris/minilibx-linux.git mlx_linux

all: $(NAME)

$(MLXPATH):
	$(GITMLX)

$(NAME): $(MLXPATH) $(OBJS)
	make -C $(MLXPATH)
	make -C $(LIBFTPATH)
	make -C $(GNLPATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTFLAG) $(GNLFLAG) $(MLXFLAG) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

bonus: $(MLXPATH) $(B_OBJS)
	make -C $(MLXPATH)
	make -C $(LIBFTPATH)
	make -C $(GNLPATH)
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBFTFLAG) $(GNLFLAG) $(MLXFLAG) -o $(NAME)

clean:
	make clean -C $(LIBFTPATH)
	make clean -C $(GNLPATH)
	make clean -C $(MLXPATH)
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	make fclean -C $(LIBFTPATH)
	make fclean -C $(GNLPATH)
	rm -f $(MLXPATH)/libmlx.a
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCDIR)
	norminette $(B_SRCDIR)
	norminette $(INCDIR)
	norminette $(LIBFTPATH)
	norminette $(GNLPATH)

.PHONY: all clean fclean re bonus norm