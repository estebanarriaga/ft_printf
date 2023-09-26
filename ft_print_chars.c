/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earriaga <earriaga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:17:11 by earriaga          #+#    #+#             */
/*   Updated: 2023/09/20 15:42:49 by earriaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int	ft_print_char(va_list ap)
{
	char	c;
	int		size;

	size = 0;
	c = va_arg(ap, int);
	size = write(1, &c, 1);
	return (size);
}

int	ft_print_str(va_list ap)
{
	char	*str;
	int		size;

	size = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		size = write(1, "(null)", 6);
	else
		size = write(1, str, ft_strlen(str));
	return (size);
}
