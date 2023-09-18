
#include "ft_printf.h"
#include "libft.h"

// Usar ft_itoa para covertir de numero a string

// Works fine but ft_putnbt needs to return legnth of 'number'
int ft_print_int(va_list ap)
{
	int number;
	int size;
	char *str_num;

	number = va_arg(ap, int);
	if (!number)
		return (0);
	str_num = ft_itoa(number);
	size = 0;
	size = write(1, str_num, ft_strlen(str_num));
	free(str_num);
	return (size);
}

int ft_print_decimal(va_list ap)
{
	int number;
	int size;
	char *str_num;

	number = va_arg(ap, int);
	if (!number)
		return (0);
	str_num = ft_itoa(number);
	size = 0;
	size = write(1, str_num, ft_strlen(str_num));
	free(str_num);
	return (size);
}

int ft_print_unsigned(va_list ap)
{
	unsigned int number;
	int size;
	char *str_num;

	size = 0;
	number = va_arg(ap, unsigned int);
	if (!number)
		return (0);
	str_num = ft_itoa(number);
	size = 0;
	size = write(1, str_num, ft_strlen(str_num));
	free(str_num);
	return (size);
}