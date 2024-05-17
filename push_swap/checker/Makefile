NAME := checker

CC := gcc

CFLAGS := -Wall -Wextra -Werror

SOURCE := checker.c
GNL := gnl/get_next_line.c gnl/get_next_line_utils.c
PUSHSWAP := ../push_swap/errors.c ../push_swap/ft_atoi.c ../push_swap/ft_split.c ../push_swap/init_commands.c ../push_swap/push_commands.c ../push_swap/push_swap.c ../push_swap/rotate_commands.c ../push_swap/sort_commands.c ../push_swap/stack_commands.c ../push_swap/swap_commands.c
OBJS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(SOURCE)
		@$(CC) $(CFLAGS) $(GNL) $(PUSHSWAP) $(SOURCE) -o $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all