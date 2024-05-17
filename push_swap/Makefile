NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror

SOURCE := main.c errors.c ft_atoi.c ft_split.c init_commands.c push_commands.c push_swap.c rotate_commands.c sort_commands.c stack_commands.c swap_commands.c
OBJS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(SOURCE)
		@$(CC) $(CFLAGS) $(SOURCE) -o $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all