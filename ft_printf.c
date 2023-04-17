/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earriaga <earriaga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:27:06 by earriaga          #+#    #+#             */
/*   Updated: 2023/04/17 17:06:04 by earriaga         ###   ########.fr       */
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
 * % % para imprimir el símbolo del porcentaje.
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int hola(va_list hello)
{
	
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);
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

	// Access the variable argument list using va_arg macro
	int arg1 = va_arg(args, int);
	double arg2 = va_arg(args, double);
	char *arg3 = va_arg(args, char *);

	va_end(args);
	return (0);
}

int	main(void)
{
	char *var = "estás";
	ft_printf("Hola como %s", var);
	return (0);
}