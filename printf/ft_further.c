/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_further.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonclus <mmonclus@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:41:35 by mmonclus          #+#    #+#             */
/*   Updated: 2023/01/25 15:46:03 by mmonclus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int	ft_ptr(char format, unsigned long *ptr)
{
	int	len;

	if (!*ptr)
		return (0);
	len = 0;
	len += ft_char('0');
	len += ft_char('x');
	while (ptr[len++])
		len += ft_hex_num(format, ptr[len]);
	return (len);
}

int	ft_num(int num)
{
	unsigned long	aux;
	int				len;

	len = 1;
	aux = num;
	if (num < 0)
	{
		ft_char('-');
		aux = aux * -1;
		len++;
	}
	while (aux > 9)
	{
		aux = ft_num(aux / 10);
		len++;
	}
	ft_char(aux % 10 + '0');
	return (len);
}

int	ft_unsigned_int(unsigned int num)
{
	
}

int	ft_hex_num(char format, unsigned long num)
{
	int	len;

	len = 0;
	if (!num)
		return (0);
	if (format == 'x')
	{
		while (num >= 16)
		{
			len = ft_char("0123456789abcdef"[num % 16 + '0']);
			num = num / 16;
		}
	}
	if (format == 'X')
	{
		while (num >= 16)
		{
			len += ft_char("0123456789ABCEF"[num % 16 + '0']);
			num = num / 16;
		}
	}
	return (len);
}

int	ft_percentage(void)
{
	write(1, '%', 1);
	return (1);
}
