/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:26:00 by maneddam          #+#    #+#             */
/*   Updated: 2022/11/05 00:47:59 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u_dec(unsigned int n, char *base)
{
	int				i;
	unsigned long	len;

	len = ft_strlen(base);
	i = 0;
	if (n > 9)
	{
		i += ft_putnbr_u_dec(n / len, base);
		i += ft_putnbr_u_dec(n % len, base);
	}
	else
	{
		i += ft_putchar((base[n]));
	}
	return (i);
}
