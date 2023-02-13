/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonclus <mmonclus@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:08:01 by mmonclus          #+#    #+#             */
/*   Updated: 2023/02/13 17:09:37 by mmonclus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_string(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (write (1, "(null)", 6));
	while (*str)
	{
		len = len + ft_char(*str);
		str++;
	}
	return (len);
}

int	ft_which_format(va_list arg, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_char(va_arg(arg, int));
	if (format == 's')
		len = ft_string(va_arg(arg, char *));
	if (format == 'p')
		len = ft_pointer(va_arg(arg, unsigned long));
	if (format == 'd' || format == 'i')
		len = ft_num(va_arg(arg, int), format);
	if (format == 'u')
		len = ft_unsigned_int(va_arg(arg, unsigned int));
	if (format == 'x' || format == 'X')
		len = ft_hex_num(va_arg(arg, unsigned int), format);
	if (format == '%')
		len = ft_char('%');
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
			len = len + ft_char(*format);
		if (*format == '%')
		{
			format++;
			len = len + ft_which_format(arg, *format);
		}
		format++;
	}
	va_end(arg);
	return (len);
}

int	main(void)
{
	char	 		character = 'f';
	char 			*string = " %%";
	int				d_num = -455;
	int				i_num = -455;
	void			*ptr = NULL;
	unsigned int	hex_cap = 45;
	unsigned int	hex_low = 45;
	unsigned int	unsig_int = '3242';

	ft_printf("My Char:\t\t%c\n", character);
	printf("Original Char:\t\t%c\n\n", character);
	ft_printf("My String:\t\t%s\n", string);
	printf("Original:\t\t%s\n\n", string);
	ft_printf("My Num:\t\t\t%d\n", d_num);
	printf("Original Num:\t\t%d\n\n", d_num);
	ft_printf("My Num:\t\t\t%i\n", i_num);
	printf("Original Num:\t\t%i\n\n", i_num);
	ft_printf("My Percentage:\t\t%%\n");
	printf("Original Percentage:\t%%\n\n"); 
	ft_printf("My Pointer:\t\t%p\n", ptr);
	printf("Original Pointer:\t%p\n\n", ptr);
	ft_printf("My CAP Hex: \t\t%X\n", hex_cap);
	printf("Original CAP Hex: \t%X\n\n", hex_cap);
	ft_printf("My LOW Hex:\t\t%x\n", hex_low);
	printf("Original LOW Hex:\t%x\n\n", hex_low);
	ft_printf("My UnSig Int: \t\t%u\n", unsig_int);
	printf("Original UnSig Int: \t%u\n", unsig_int);
	return (0);
}