/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earriaga <earriaga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:27:06 by earriaga          #+#    #+#             */
/*   Updated: 2023/09/12 19:11:47 by earriaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Escribe una librería que contenga la función
 * ft_printf(), que imite el printf() original
 * 
 * Funciones autorizadas: malloc, free, write,
 * va_start, va_arg, va_copy, va_end
 * 
 * No implementes la gestión del buffer del printf() original.
 * Deberás implementar las siguientes conversiones: cspdiuxX %
 * Tu función se comparará con el printf() original.
 * Tienes que usar el comando ar para crear tu librería.
 * El uso de libtool command is forbidden.
 * Tu archivo libftprintf.a deberá ser creado en la raiz de tu repositorio.
 * 
 * -- %c Imprime un solo carácter.
 * -- %s Imprime una string (como se define por defecto en C.
 * -- %p El puntero void * dado como argumento se imprime en formato hexadecimal.
 * %d Imprime un número decimal (base 10).
 * -- %i Imprime un entero en base 10.
 * -- %u Imprime un número decimal (base 10) sin signo.
 * -- %x Imprime un número hexadecimal (base 16) en minúsculas.
 * -- %X Imprime un número hexadecimal (base 16) en mayúsculas.
 * -- %% para imprimir el símbolo del porcentaje.
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	ft_count_format_specifiers(const char *str)
{
	int					counted_specifiers;
	const char	*p;

	p = str;
	counted_specifiers = 0;
	while (*p != '\0')
	{
		if (*p == '%')
			counted_specifiers ++;
		p ++;
	}
	return (counted_specifiers);
}

static int	ft_print_variable(va_list ap, char c)
{
	size_t	size;

	size = 0;
	if (c == 0)
		return (0);
	else if (c == 'c')
		size = ft_print_char(ap);
	else if (c == 's')
		size = ft_print_str(ap);
	else if (c == 'i')
		size = ft_print_int(ap);
	else if (c == 'd')
		size = ft_print_decimal(ap);
	else if (c == 'p')
		size = ft_print_ptr_hex(ap);
	else if (c == 'x')
		size = ft_print_hex(ap, 'a');
	else if (c == 'X')
		size = ft_print_hex(ap, 'A');
	else if (c == 'u')
		size = ft_print_unsigned(ap);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int			count;
	int			num_args;
	size_t	str_size;
	char		percentage;

	percentage = '%';
	va_start(ap, str);
	num_args = ft_count_format_specifiers(str);
	count = 0;
	str_size = 0;
	while (str[count])
	{
		if (str[count] == '%')
		{
			if (str[count + 1] == '%')
			{
				str_size += write(1, &percentage, 1);
				count ++;
			}
			else {
				str_size += ft_print_variable(ap, str[count + 1]);
				count += 2;
			}
		}
		else
		{
			write(1, &str[count], 1);
			count ++;
		}
	}
	str_size += count - num_args * 2;
	va_end(ap);
	return (str_size);
} 
