/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonclus <mmonclus@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:48:32 by mmonclus          #+#    #+#             */
/*   Updated: 2023/01/27 16:12:54 by mmonclus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	main(void);
int	ft_printf(char const *format, ...);
int	ft_which_format(va_list arg, char format);
int	ft_string(char *str);
int	ft_char(char c);
int	ft_num(int num, char format);
int	ft_hex_num(unsigned long num, char format);
int	ft_unsigned_int(unsigned int num);

#endif
