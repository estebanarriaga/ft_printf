/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earriaga <earriaga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:17:22 by earriaga          #+#    #+#             */
/*   Updated: 2023/09/20 15:57:08 by earriaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

/* -------- Main ft_printf function ------ */
int			ft_printf(const char *str, ...);
/* -------- Printing functions ----------- */
int			ft_print_char(va_list ap);
int			ft_print_str(va_list ap);
int			ft_print_hex(va_list ap, const char c);
int			ft_print_ptr(va_list ap);
int			ft_print_unsigned(va_list ap);
int			ft_print_nbr(va_list ap);
/* -------- Helper functions ------------- */
size_t		ft_strlen(const char *str);
int			ft_putchar(char c);
char		*ft_itoa(int n);

#endif