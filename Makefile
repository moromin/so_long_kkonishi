NAME	= so_long
SRCS	= main.c arg_check.c

OBJS	= $(SRCS:%.c=%.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
GNLPATH = ./gnl/
GNL_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C gnl/
	$(CC) $(CFLAGS) $(OBJS) -Lgnl -lgnl -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lbsd -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C gnl/
	rm -f $(OBJS)

fclean: clean
	make fclean -C gnl/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus $(NAME)