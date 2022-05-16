/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:33:42 by macar             #+#    #+#             */
/*   Updated: 2022/02/16 10:43:24 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(char k, va_list *args)
{
	int	result;

	result = 0;
	if (k == 'c')
		result += ft_putchar(va_arg(*args, int));
	if (k == 'd' || k == 'i')
		ft_putnbr(va_arg(*args, int), &result);
	if (k == 's')
		result += ft_putstr(va_arg(*args, char *));
	if (k == '%')
		result += write(1, "%", 1);
	if (k == 'p')
	{
		result += write(1, "0x", 2);
		ft_pointer(va_arg(*args, unsigned long long ), &result);
	}
	if (k == 'u')
		ft_unsigned(va_arg(*args, unsigned int), &result);
	if (k == 'x')
		ft_lowerx(va_arg(*args, unsigned int), &result);
	if (k == 'X')
		ft_upperx(va_arg(*args, unsigned int), &result);
	return (result);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		result;

	va_start(args, s);
	result = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			result += ft_checker(s[i], &args);
		}
		else
		{
			result += write(1, &s[i], 1);
		}
	i++;
	}
	va_end(args);
	return (result);
}

/*   int main()
 {
	 printf("%X\n", -16);
	 ft_printf("%X", -16);
 }  */