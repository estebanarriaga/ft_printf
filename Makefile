
# Reglas:
# $(NAME), all, clean, fclean, re

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MY_SOURCES = ft_printf.c ft_printf_utils.c libft_utils.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

$(NAME): $(MY_OBJECTS) ft_printf.h
			@ar rcs $(NAME) $(MY_OBJECTS)

all:	$(NAME)

clean:
		@rm -f $(MY_OBJECTS)

fclean: clean
		@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus