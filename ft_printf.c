/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earriaga <earriaga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:27:06 by earriaga          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/05 17:50:03 by earriaga         ###   ########.fr       */
=======
/*   Updated: 2023/04/17 17:06:04 by earriaga         ###   ########.fr       */
>>>>>>> 220da7ff99e2171065a0512c8e2e476b367e86bb
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

int ft_print_string(const char *str)
{
	if (!str)
		write(1, "(NULL)", 7);
	else if (str)
		write(1, str, ft_strlen(str));
	return ((int)ft_strlen(str));
}

int ft_type(const char type, va_list args)
{
	int	str_size;

	str_size = 0;
	if (type == 's' )
		str_size = ft_print_string(va_arg(args, const char *));
	else if (type == 'c' )
		str_size = ft_print_char(va_arg(args, const char *));
	return (str_size);
}

int hola(va_list hello)
{
	
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int str_size;
	int	i;
	int var_num;

	if (!str)
		return (NULL);
	i = 0;
	var_num = 0;
	while (str[i])
	{
		if (str[i - 1] == '%' && str[i] != '%')
		{
			if (str[i] == s)
				char
		}
			var_num ++;
		i ++;
	}

	if (!str)
		return (0);
	i = 0;
	str_size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			str_size += ft_type(str[i + 1], args);
			i ++;
		}
		else
			ft_putchar(str[i]);
		str_size ++;
		i ++;
	}
	va_end(args);
	return (str_size);
}

// // Access the variable argument list using va_arg macro
// int arg1 = va_arg(args, int);
// double arg2 = va_arg(args, double);
// char *arg3 = va_arg(args, char *);

int	main(void)
{
	char *var = "estas";
	char *name = "Esteban";
	int ft_size;
	int or_size;

	ft_size = ft_printf("Hola como %s me llamo %s\n", var, name);
	or_size = printf("Hola como %s me llamo %s\n", var, name);
	
	printf("ft_size == %d\nor_size == %d\n", ft_size, or_size);
	
	char *var = "estás";
	ft_printf("Hola como %s", var);
	return (0);
}