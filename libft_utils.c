
#include <unistd.h>

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
