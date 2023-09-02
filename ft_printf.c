/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earriaga <earriaga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:27:06 by earriaga          #+#    #+#             */
/*   Updated: 2023/09/02 16:24:40 by earriaga         ###   ########.fr       */
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
 * %c Imprime un solo carácter.
 * %s Imprime una string (como se define por defecto en C.
 * %p El puntero void * dado como argumento se imprime en formato hexadecimal.
 * %d Imprime un número decimal (base 10).
 * %i Imprime un entero en base 10.
 * %u Imprime un número decimal (base 10) sin signo.
 * %x Imprime un número hexadecimal (base 16) en minúsculas.
 * %X Imprime un número hexadecimal (base 16) en mayúsculas.
 * %% para imprimir el símbolo del porcentaje.
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"
#include "../Libft/libft.h"

static int ft_count_format_specifiers(const char *str)
{
	int counted_specifiers;
	const char *p = str;
	
	counted_specifiers = 0;
	while (*p != '\0')
	{
		if (*p == '%')
			counted_specifiers ++;
		p ++;
	}
	return (counted_specifiers);
}

// Por ahora no va a hacer falta:
static char *ft_get_format_specifiers(const char *str)
{
	const char *p = str;
	int counter;
	size_t p_size;
	char *specifiers;
	char specifiers_count;

	counter = 0;
	specifiers = 0;
	p_size = ft_strlen(p);
	specifiers = (char *)malloc(5);
	while (counter <= p_size)
	{
		if (p[counter] == '%')
			if (p[counter + 1])
			{
				specifiers[specifiers_count] = p[counter + 1];
				specifiers_count++;
			}
		counter ++;
	}
	return (specifiers);
}

int ft_print_variable(va_list ap, char c)
{
	if (c == 0) return (0);
	else if (c == 'c')
		write(1, "character", 1);
	else if (c == 's')
		write(1, va_arg(ap, char *), 1);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list ap, ap2;
	
	va_start(ap, str);
	int count;
	char *s, *s2;
	int num_args;
	char *specifiers;
	char percentage = '%';
	
		/* Por ahora no va a hacer falta
	num_args = ft_count_format_specifiers(str);
	printf("num_args: %d\n", num_args); */
		/* Por ahora no va a hacer falta
	specifiers = ft_get_format_specifiers(str);
	printf("Specifiers: %s\n", speci fiers); */
	count = 0;
	printf("str = %s\n", str);
	while (str[count] != 0)
	{
		if (str[count] == '%')
		{
			if (str[count + 1] == '%')
				write(1, &percentage, 1);
			else
				ft_print_variable(ap, str[count + 1]);
			count++;
		} else count ++;
	}
	va_end(ap);
	return (0);
}


int	main(void)
{
	char var = 'a';
	char name[] = "Esteban";
	int ft_size;
	int or_size;

	ft_printf("Hola como %c me llamo %s", var, name);
	// ft_size = ft_printf("Hola como %s me llamo %s\n", var, name);
	// or_size = printf("Hola como %s me llamo %s\n", var, name);

	// printf("or_size: %d\n ft_size: %d\n", or_size, ft_size);

	return (0);
}