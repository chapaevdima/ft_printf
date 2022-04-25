/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:14:50 by anatasha          #+#    #+#             */
/*   Updated: 2021/12/19 15:20:37 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_low(unsigned int n)
{
	int		res;
	char	*sym;

	sym = "0123456789abcdef";
	res = 0;
	if (n >= 16)
		res += ft_put_hex_low(n / 16);
	res += ft_putchar((char)(sym[n % 16]));
	return (res);
}

int	ft_put_hex_point(unsigned long n)
{
	int		res;
	char	*sym;

	sym = "0123456789abcdef";
	res = 0;
	if (n >= 16)
		res += ft_put_hex_point(n / 16);
	res += ft_putchar((char)(sym[n % 16]));
	return (res);
}

int	ft_put_hex_up(unsigned int n)
{
	int		res;
	char	*sym;

	sym = "0123456789ABCDEF";
	res = 0;
	if (n >= 16)
		res += ft_put_hex_up(n / 16);
	res += ft_putchar((char)(sym[n % 16]));
	return (res);
}

int	ft_put_point(unsigned long n)
{
	ft_putstr("0x");
	return (ft_put_hex_point(n) + 2);
}
