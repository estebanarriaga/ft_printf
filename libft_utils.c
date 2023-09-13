
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int index;
	index = 0;
	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		n = 147483648;
		index += 2;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		index ++;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
		index ++;
	}
	return (index);
}

int	ft_putstr(char *s)
{
	int size;

	size = 0;
	if (s)
		write(1, s, ft_strlen(s));
	return (size);
}