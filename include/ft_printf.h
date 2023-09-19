#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

int	ft_printf(const char *str, ...);
int ft_print_char(va_list ap);
int ft_print_str(va_list ap);
int	ft_print_hex(va_list ap, const char c);
int	ft_print_ptr(va_list ap);
int ft_print_unsigned(va_list ap);
int ft_print_nbr(va_list ap);
size_t	ft_strlen(const char *str);
int	ft_putchar(char c);

#endif