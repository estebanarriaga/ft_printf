#include "ft_printf.h"

static int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}

int	ft_print_ptr(va_list ap)
{
	int	length;
	unsigned long number;

	number = va_arg(ap, unsigned long);
	length = 0;
	length += write(1, "0x", 2);
	if (number == 0)
		length += write(1, "0", 1);
	else
	{
		ft_put_ptr(number);
		length += ft_ptr_len(number);
	}
	return (length);
}