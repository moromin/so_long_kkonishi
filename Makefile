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
			destroy_ptr_bonus.c
SRCDIR	= ./srcs
B_SRCDIR  = ./srcs_bonus
SRCS	= $(addprefix $(SRCDIR)/, $(SRC))
B_SRCS	= $(addprefix $(B_SRCDIR)/, $(B_SRC))
OBJS    = $(SRCS:%.c=%.o)
B_OBJS  = $(B_SRCS:%.c=%.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIBFTPATH	= ./libft/
GNLPATH = ./get_next_line/
GNL_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTPATH)
	make -C $(GNLPATH)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -Lget_next_line -lgnl -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lbsd -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

bonus: $(B_OBJS)
	make -C $(LIBFTPATH)
	make -C $(GNLPATH)
	$(CC) $(CFLAGS) $(B_OBJS) -Llibft -lft -Lget_next_line -lgnl -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lbsd -o $(NAME)

clean:
	make clean -C $(LIBFTPATH)
	make clean -C $(GNLPATH)
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	make fclean -C $(LIBFTPATH)
	make fclean -C $(GNLPATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus $(NAME)