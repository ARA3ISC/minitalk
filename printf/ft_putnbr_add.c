/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:27:26 by maneddam          #+#    #+#             */
/*   Updated: 2022/11/05 15:26:10 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_add(unsigned long n, char *base)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_putnbr_add(n / 16, base);
		i += ft_putnbr_add(n % 16, base);
	}
	else
	{
		i += ft_putchar((base[n]));
	}
	return (i);
}
