/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:24:42 by maneddam          #+#    #+#             */
/*   Updated: 2022/11/07 19:24:53 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static int	check_hexa(const char *s, int i, va_list list)
{
	int	len;

	len = 0;
	if (s[i] == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putnbr_add(va_arg(list, unsigned long), "0123456789abcdef");
	}
	else if (s[i] == 'u')
		len += ft_putnbr_u_dec(va_arg(list, unsigned int), "0123456789");
	else if (s[i] == 'x')
	{
		len += ft_putnbr_add(va_arg(list, unsigned int), "0123456789abcdef");
	}
	else if (s[i] == 'X')
	{
		len += ft_putnbr_add(va_arg(list, unsigned int), "0123456789ABCDEF");
	}
	else if (s[i] == 'd' || s[i] == 'i')
		len += ft_putnbr(va_arg(list, int), "0123456789");
	else if (s[i] == 'c')
		len += ft_putchar(va_arg(list, int));
	else if (s[i] == 's')
		len += ft_putstr(va_arg(list, char *));
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	list;

	va_start(list, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '%')
				len += ft_putchar('%');
			len += check_hexa(s, i, list);
		}
		else
		{
			ft_putchar(s[i]);
			len++;
		}
		i++;
	}
	va_end(list);
	return (len);
}
