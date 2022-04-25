/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:14:20 by anatasha          #+#    #+#             */
/*   Updated: 2021/12/19 15:24:43 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	check_type(const char *s, va_list el)
{
	if (*s == '%')
		return (write (1, s, 1));
	else if (*s == 'd' || *s == 'i')
		return (ft_putnbr(va_arg(el, int)));
	else if (*s == 'c')
		return (ft_putchar(va_arg(el, int)));
	else if (*s == 'u')
		return (ft_putuns(va_arg(el, unsigned int)));
	else if (*s == 's')
		return (ft_putstr(va_arg(el, char *)));
	else if (*s == 'x')
		return (ft_put_hex_low(va_arg(el, unsigned int)));
	else if (*s == 'X')
		return (ft_put_hex_up(va_arg(el, unsigned int)));
	else if (*s == 'p')
		return (ft_put_point(va_arg(el, unsigned long)));
	return (0);
}

int	my_print(va_list el, const char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		if (*str != '%')
			res += write(1, str, 1);
		if (*str == '%')
			res += check_type(++str, el);
		str++;
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	el;
	int		res;

	va_start(el, str);
	res = my_print(el, str);
	va_end(el);
	return (res);
}
