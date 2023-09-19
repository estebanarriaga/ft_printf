/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earriaga <earriaga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:27:06 by earriaga          #+#    #+#             */
/*   Updated: 2023/09/19 21:32:38 by earriaga         ###   ########.fr       */
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
 * -- %d Imprime un número decimal (base 10).
 * -- %i Imprime un entero en base 10.
 * -- %u Imprime un número decimal (base 10) sin signo.
 * -- %x Imprime un número hexadecimal (base 16) en minúsculas.
 * -- %X Imprime un número hexadecimal (base 16) en mayúsculas.
 * -- %% para imprimir el símbolo del porcentaje.
 */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	ft_print_variable(va_list ap, char c)
{
	size_t	size;

	size = 0;
	if (c == 'c')
		size = ft_print_char(ap);
	else if (c == 's')
		size = ft_print_str(ap);
	else if (c == 'i' || c == 'd')
		size = ft_print_nbr(ap);
	else if (c == 'p')
		size = ft_print_ptr(ap);
	else if (c == 'x')
		size = ft_print_hex(ap, 'a');
	else if (c == 'X')
		size = ft_print_hex(ap, 'A');
	else if (c == 'u')
		size = ft_print_unsigned(ap);
	else if (c == '%')
		size = ft_putchar(c);
	else
		return (-1);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int			count;
	int			str_length;

	if (str == NULL)
		return (-1);
	va_start(ap, str);
	count = 0;
	str_length = 0;
	while (str[count])
	{
		if (str[count] == '%')
		{
			if (ft_strlen(str) > (size_t)count + 1)
				str_length += ft_print_variable(ap, str[count + 1]);
			count++;
		}
		else
			str_length += write(1, &str[count], 1);
		count++;
	}

	va_end(ap);
	return (str_length);
} 
