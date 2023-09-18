
#include "ft_printf.h"

// Usar ft_itoa para covertir de numero a string

int	ft_putnbr(int n)
{
	int index;
	index = 0;
	if (n == -2147483648)
	{
		index += write(1, "-", 1);
		index += write(1, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		index += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		n += 48;
		index += write(1, &n, 1);
	}
	return (index);
}

int ft_print_decimal(va_list ap)
{
	int number;
	int size;

	size = 0;
	number = va_arg(ap, int);
	ft_putnbr(number);
	return (size);
}

// Works fine but ft_putnbt needs to return legnth of 'number'
int ft_print_int(va_list ap)
{
	int number;
	int size;

	size = 0;
	number = va_arg(ap, int);
	if (!number)
		printf("hello");
	ft_putnbr(number);
	return (size);
}

int ft_print_unsigned(va_list ap)
{
	unsigned number;
	int size;

	size = 0;
	number = va_arg(ap, unsigned);
	ft_putnbr(number);
	return (size);
}