/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upperx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:59:16 by macar             #+#    #+#             */
/*   Updated: 2022/02/16 10:44:09 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_point(unsigned long long a, int *s)
{
	if (a < 16)
	{
		if (a < 10)
		{
			*s += ft_putchar(a + 48);
		}
		else
			*s += ft_putchar(a + 55);
	}
	else
	{
		ft_point(a / 16, s);
		ft_point(a % 16, s);
	}
	return (*s);
}

int	ft_upperx(unsigned int a, int *s)
{
	if (a < 16)
	{
		if (a < 10)
		{
			*s += ft_putchar(a + 48);
		}
		else
			*s += ft_putchar(a + 55);
	}
	else
	{
		ft_point(a / 16, s);
		ft_point(a % 16, s);
	}
	return (*s);
}
