/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonclus <mmonclus@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:08:01 by mmonclus          #+#    #+#             */
/*   Updated: 2023/01/25 15:43:19 by mmonclus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include <stdarg.h>

int	ft_string(char *str)
{
	int	len;

	len = 0;
	if (!*str)
		return (write (1, "(null)", 6));
	while (*str++)
		len += ft_char(*str);
	return (len);
}	

int	ft_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_which_format(va_list args, char format) // nombre FORMAT porque lo que hemos pasado en *str es qué 
//formato hemos encontrado despues del %
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_char(va_arg(args, char));
	if (format == 's')
		len = ft_string(va_arg(args, char *));
	if (format == 'p')
		len = ft_ptr(va_arg(args, unsigned long));
	if (format == 'd' || format == 'i')
		len = ft_num(va_arg(args, int), format);
	if (format == 'u')
		len = ft_unsigned_int(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		len = ft_hex_num(va_arg(args, unsigned long), args);
	if (format == '%')
		len = ft_percentage();
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args; // variable que apunta a los argumentos
	int		len; // cada función va a devolver el length de lo que ha imprimido

	if (!str)
		return (0);
	va_start(args, str); // inicializar la variable va_list
	len = 0;
	while (*str)
	{
		while (*str != '%')
		{
			str++;
			len =+ ft_char(args, *str);
		}
		if (*str == '%') // puntero al character a dónde apunta
		{
			str++;
			len =+ ft_which_format(args, *str);
		}
		str++;
	}
	va_end(args, str) // finalizar la variable va_list
	return (len);
}
