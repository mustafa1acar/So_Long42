/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:33:56 by macar             #+#    #+#             */
/*   Updated: 2022/02/15 20:49:24 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
//# include "./libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_checker(char k, va_list *args);
int	ft_putchar(char c);
int	ft_putnbr(int n, int *s);
int	ft_putstr(char *s);
int	ft_unsigned(unsigned int n, int *s);
int	ft_upperx(unsigned int a, int *s);
int	ft_pointer(unsigned long long a, int *s);
int	ft_lowerx(unsigned int a, int *s);
int	ft_point(unsigned long long a, int *s);

#endif