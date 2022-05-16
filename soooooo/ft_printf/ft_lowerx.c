/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowerx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:59:19 by macar             #+#    #+#             */
/*   Updated: 2022/02/16 10:43:29 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowerx(unsigned int a, int *s)
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
