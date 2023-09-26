/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earriaga <earriaga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:16:58 by earriaga          #+#    #+#             */
/*   Updated: 2023/09/20 15:33:09 by earriaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(uintptr_t number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
		number = number / 16;
		len++;
	}
	return (len);
}

static void	ft_put_ptr(uintptr_t number)
{
	if (number >= 16)
	{
		ft_put_ptr(number / 16);
		ft_put_ptr(number % 16);
	}
	else
	{
		if (number <= 9)
			ft_putchar((number + '0'));
		else
			ft_putchar((number - 10 + 'a'));
	}
}

int	ft_print_ptr(va_list ap)
{
	int				length;
	unsigned long	number;

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
