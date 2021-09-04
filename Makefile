NAME	= so_long
SRCS	= 	main.c \
			arg_check.c \
			error_handle.c \
			utils.c \
			rendering.c
B_SRCS	=	main_bonus.c \
			arg_check_bonus.c \
			error_handle_bonus.c \
			utils_bonus.c \
			rendering_bonus.c
SRCDIR	= ./srcs
OBJDIR  = ./obj
OBJS    = $(addprefix $(OBJDIR)/, $(SRCS:%.c=%.o))
B_OBJS  = $(addprefix $(OBJDIR)/, $(B_SRCS:%.c=%.o))
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
GNLPATH = ./gnl/
GNL_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C gnl/
	make -C libft/
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -Lgnl -lgnl -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lbsd -o $(NAME)

$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

bonus: $(B_OBJS)
	make -C gnl/
	make -C libft/
	$(CC) $(CFLAGS) $(B_OBJS) -Llibft -lft -Lgnl -lgnl -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lbsd -o $(NAME)

clean:
	make clean -C gnl/
	make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C gnl/
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus $(NAME)