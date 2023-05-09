#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * The ft_strlen() function computes the length of the string s.
 * Missing error handling
*/
size_t	ft_strlen(const char *str);

int	ft_putchar(int c);

#endif