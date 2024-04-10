NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes/
MLXFLAGS = -framework OpenGL -framework AppKit -g3

FILES = srcs/errors \
		srcs/ft_calloc \
		srcs/ft_split \
		srcs/ft_sstrlen \
		srcs/ft_strdup  \
		srcs/ft_strjoin \
		srcs/map_utils \
		srcs/player \
		srcs/so_long \
		srcs/get_next_line/get_next_line \
		srcs/get_next_line/get_next_line_utils \

SRCS = $(addsuffix .c,$(FILES))
OBJS = $(addsuffix .o,$(FILES))

all: $(NAME)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME):  $(OBJS)
	@make -C srcs/minilibx
	@make -C srcs/printf
	mv srcs/printf/libftprintf.a libftprintf.a
	mv srcs/minilibx/libmlx.a libmlx.a
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $^ libftprintf.a libmlx.a -o $@

clean:
	make clean  -C srcs/printf
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re



# $(NAME):  $(SOURCE) $(HDRS) $(PRINT)
# gcc $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(PRINT) -o $(NAME)