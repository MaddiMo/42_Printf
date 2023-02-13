/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_further.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonclus <mmonclus@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:41:35 by mmonclus          #+#    #+#             */
/*   Updated: 2023/02/13 16:30:32 by mmonclus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num(int num, char format)
{
	unsigned long	aux;
	int				len;

	len = 1;
	aux = num;
	if (format == 'd' || format == 'i')
	{
		if (num < 0)
		{
			len += ft_char('-');
			aux = aux * -1;
		}
		if (aux > 9)
			len += ft_num(aux / 10, format);
		ft_char(aux % 10 + '0');
	}	
	return (len);
}

int	ft_unsigned_int(unsigned int num)
{
	int	len;

	len = 1;
	if (num > 9)
		len += ft_unsigned_int(num / 10);
	ft_char(num % 10 + '0');
	return (len);
}

int	ft_pointer(unsigned long pointer)
{	
	ft_char('0');
	ft_char('x');
	return (ft_hex_num(pointer, 'p') + 2);
}

int	ft_hex_num(unsigned long num, char format)
{
	int		len;
	char	*aux;

	len = 1;
	aux = "0123456789abcdef";
	if (format == 'X')
		aux = "0123456789ABCDEF";
	if (num > 15)
		len += ft_hex_num(num / 16, format);
	ft_char(aux[num % 16]);
	return (len);
}
