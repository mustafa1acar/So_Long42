/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:59:21 by macar             #+#    #+#             */
/*   Updated: 2022/02/16 10:44:00 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int n, int *s)
{
	if (n < 0)
	{
		*s += ft_putchar('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		*s += ft_putchar(n + 48);
	if (n > 9)
	{
		ft_unsigned(n / 10, s);
		ft_unsigned(n % 10, s);
	}
	return (*s);
}
