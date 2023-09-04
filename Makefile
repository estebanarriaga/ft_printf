
# Reglas:
# $(NAME), all, clean, fclean, re

NAME = libftprintf.a

CC = gcc

# CFLAGS = -Wall -Wextra -Werror

MY_SOURCES = ft_printf.c ft_printf_utils.c

MY_TESTS = tests/main.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

$(NAME): $(MY_OBJECTS) libftprintf.h Libft/libft.h
			@ar rcs $(NAME) $(MY_OBJECTS)

all:	$(NAME)

test: $(MY_TESTS) Libft/libft.a libftprintf.a

clean:
		@rm -f $(MY_OBJECTS)

fclean: clean
		@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus