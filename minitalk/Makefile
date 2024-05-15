NAME_C = client
NAME_S = server
FLAGS = -Wall -Wextra -Werror
FILE1 = client.c ft_printf.c
FILE2 = server.c ft_printf.c
CC = gcc

all: $(NAME_C) $(NAME_S)

$(NAME_C):
	$(CC) $(FLAGS) $(FILE1) -o $(NAME_C) 

$(NAME_S):
	$(CC) $(FLAGS) $(FILE2) -o $(NAME_S)
 
clean:
	rm -rf server
	rm -rf client

fclean: 
	rm -rf $(NAME_C)
	rm -rf $(NAME_S)

re: fclean all

.PHONY: all clean fclean re
