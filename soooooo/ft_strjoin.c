/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:25:42 by macar             #+#    #+#             */
/*   Updated: 2022/02/16 11:52:24 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
} */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		i2;

	p = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	i = 0;
	i2 = 0;
	if (p == NULL)
		return (0);
	while (s1 && s1[i] != 0)
	{
		p[i] = s1[i];
		i++;
	}
	while (s2 && s2[i2] != 0)
	{
		p[i] = s2[i2];
		i2++;
		i++;
	}
	p[i] = 0;
	return (p);
}
/*int main()
{
	printf("dizi: %s", ft_strjoin("ali", "ata"));
}*/