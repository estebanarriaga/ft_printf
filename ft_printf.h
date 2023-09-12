#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);
int ft_print_char(va_list ap);
int ft_print_str(va_list ap);
int ft_print_int(va_list ap);
int ft_print_ptr_hex(va_list ap);
int ft_print_ptr_hex_upper(va_list ap);
int ft_print_hex(va_list ap, char c);
int ft_print_unsigned(va_list ap, char c);

#endif