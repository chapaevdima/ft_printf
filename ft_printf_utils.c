/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:54:50 by anatasha          #+#    #+#             */
/*   Updated: 2021/12/19 15:22:19 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	unsigned int	nbr;
	int				res;

	res = 0;
	if (n < 0)
	{
		res += ft_putchar('-');
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		res += ft_putnbr(nbr / 10);
	res += ft_putchar((char)(nbr % 10 + '0'));
	return (res);
}

int	ft_putuns(unsigned int n)
{
	int	res;

	res = 0;
	if (n >= 10)
		res += ft_putuns(n / 10);
	res += ft_putchar((char)(n % 10 + '0'));
	return (res);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_putstr(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return (write(1, s, ft_strlen(s)));
}
