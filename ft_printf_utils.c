
#include "libftprintf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_is_desired_character(const char a, char b) {
	if (a == b)
		return (1);
	return (0);
}