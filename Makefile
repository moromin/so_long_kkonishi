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


all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTPATH)
	make -C $(GNLPATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTFLAG) $(GNLFLAG) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lbsd -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -O3 -c $< -o $@

bonus: $(B_OBJS)
	make -C $(LIBFTPATH)
	make -C $(GNLPATH)
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBFTFLAG) $(GNLFLAG) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lbsd -o $(NAME)

clean:
	make clean -C $(LIBFTPATH)
	make clean -C $(GNLPATH)
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	make fclean -C $(LIBFTPATH)
	make fclean -C $(GNLPATH)
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCDIR)
	norminette $(B_SRCDIR)
	norminette $(INCDIR)
	norminette $(LIBFTPATH)
	norminette $(GNLPATH)

.PHONY: all clean fclean re bonus $(NAME) norm