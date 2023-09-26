/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earriaga <earriaga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:17:03 by earriaga          #+#    #+#             */
/*   Updated: 2023/09/20 16:00:56 by earriaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(va_list ap)
{
	int		number;
	int		size;
	char	*str_num;

	number = va_arg(ap, int);
	if (number == 0)
		return (write(1, "0", 1));
	str_num = ft_itoa(number);
	size = 0;
	size = write(1, str_num, ft_strlen(str_num));
	free(str_num);
	return (size);
}

static int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static char	*ft_unsigned_itoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(len + 1);
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(va_list ap)
{
	int		number;
	int		size;
	char	*str_num;

	size = 0;
	number = va_arg(ap, unsigned int);
	if (number == 0)
		size = write(1, "0", 1);
	else
	{
		str_num = ft_unsigned_itoa(number);
		size = write(1, str_num, ft_strlen(str_num));
		free(str_num);
	}
	return (size);
}
