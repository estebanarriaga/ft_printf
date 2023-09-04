
#include "../libftprintf.h"

int	main(void)
{
	int var = 12399;
	char chr = 'n';
	char name[] = "Antonio";
	int *ptr;
	int ft_size;
	int or_size;

	ft_size = ft_printf("Tengo %x armas, %s\n", var, name);
	or_size = printf("Tengo %x armas, %s\n", var, name);

	printf("ft_size: %d\n", ft_size);
	printf("or_size: %d\n", or_size);

	return (0);
}