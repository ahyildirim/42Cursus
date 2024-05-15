NAME = libftprintf.a

INCLUDE = ft_printf.h
SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf
CC = gcc
LIB1 = ar -rc
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			$(LIB1) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all