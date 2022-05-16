/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:22:44 by macar             #+#    #+#             */
/*   Updated: 2022/02/16 10:43:34 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long long a, int *s)
{
	if (a < 16)
	{
		if (a < 10)
		{
			*s += ft_putchar(a + 48);
		}
		else
			*s += ft_putchar(a + 87);
	}
	else
	{
		ft_pointer(a / 16, s);
		ft_pointer(a % 16, s);
	}
	return (*s);
}
/* 	while (a != 0)
	{
		temp = a % 16;
		if (temp < 10)
		{
			len += ft_putchar_fd(temp + 48);
		}
		else
			len += ft_putchar_fd(temp + 87);
		a = a / 16;
	} */