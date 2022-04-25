/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:15:00 by anatasha          #+#    #+#             */
/*   Updated: 2021/12/19 15:19:24 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putuns(unsigned int n);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *str);
int		check_type(const char *s, va_list el);
int		my_print(va_list el, const char *str);
int		ft_printf(const char *str, ...);
int		ft_put_hex_up(unsigned int n);
int		ft_put_hex_low(unsigned int n);
int		ft_put_point(unsigned long n);
int		ft_put_hex_point(unsigned long n);
#endif