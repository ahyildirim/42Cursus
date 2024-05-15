NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := controls.c graphics.c errors.c map_controls.c map_destroy.c map_read.c recursive_map.c so_long.c
GNL := get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
LIBFT := libft/libft.a
PRINTF := ft_printf/ft_printf.c
LIBRARY := -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX := mlx/
OBJS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(SOURCE)
		@$(CC) $(CFLAGS) $(SOURCE) $(LIBFT) $(GNL) $(PRINTF) $(LIBRARY) -o $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all
