/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earriaga <earriaga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:43:47 by earriaga          #+#    #+#             */
/*   Updated: 2023/09/20 15:45:06 by earriaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(ft_strlen(s) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (s[i])
	{
		dest[i] = (char)s[i];
		i ++;
	}
	dest[i] = 0;
	return (dest);
}

static char	*ft_helper(char *num, int is_negative, int n)
{
	int		aux;
	size_t	count;

	aux = n;
	count = 1;
	while (aux > 9)
	{
		count ++;
		aux /= 10;
	}
	if (is_negative)
		count ++;
	num = (char *) malloc(sizeof(char) * count + 1);
	if (!num)
		return (0);
	num[count] = '\0';
	if (is_negative)
		num[0] = '-';
	while (n > 0)
	{
		num[count - 1] = (n % 10) + 48;
		count --;
		n /= 10;
	}
	return (num);
}

/*
	The ft_itoa() function converts an int into a string using malloc()
	Returns the resulting string
*/
char	*ft_itoa(int n)
{
	char	*num;
	int		is_negative;

	num = NULL;
	is_negative = 0;
	if (n == 0)
	{
		num = malloc(sizeof(char) * 2);
		if (!num)
			return (NULL);
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	return (ft_helper(num, is_negative, n));
}

/*
int	main(void)
{
	printf("VALUE: %s\n", ft_itoa(-2147483648));
	return (0);
}*/