/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:40:03 by macar             #+#    #+#             */
/*   Updated: 2022/02/16 10:56:12 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	if ((*needle) == 0)
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		c = 0;
		while (haystack[i + c] == needle[c] && i + c < len && needle[c] != 0)
			c++;
		if (!needle[c])
			return ((char *)(haystack + i));
	i++;
	}
	return (0);
}

/*int main(void)
{
const char *largestring = "aa";
const char *smallstring = "aa";
char *ptr;
size_t a = 0;
ptr = strnstr(largestring, smallstring, a);
printf(":> orj:%s\n", ptr);
const char *ls = "aa";
const char *ss = "aa";
char *p;

p = ft_strnstr(ls, ss, a);
printf(":> ben:%s", p);
 return 0;
}*/
