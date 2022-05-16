/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:16:53 by macar             #+#    #+#             */
/*   Updated: 2022/02/16 10:57:13 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	howmany(const char *s, char c)
{
	int	i;
	int	count ;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	*print_it(char *p, const char *s, int i, int k)
{
	int	x;

	x = 0;
	while (k > 0)
	{
		p[x] = s[i - k];
		x++;
		k--;
	}
	p[x] = '\0';
	return (p);
}

char	*word_split(char **p, const char *s, char c, int howmny)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < howmny)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			k++;
		}
		p[j] = (char *)malloc(sizeof(char) * (k + 1));
		if (!p)
			return (0);
		print_it(p[j], s, i, k);
		j++;
		k = 0;
	}
	p[j] = 0;
	return (p[j]);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		howmny;

	if (s)
	{
		howmny = howmany(s, c);
		p = (char **)malloc(sizeof(char *) * (howmny + 1));
		if (!p)
			return (0);
		word_split(p, s, c, howmny);
		return (p);
	}
	return (0);
}

/*int main()
{
	char const	*k = " ali- ayse --fatma -";
	char c = '-';
	int i = 0;
	char **p = ft_split(k,c);
	while (p[i] != 0)
	{
		printf("> %s\n",p[i]);
		i++;
	}
	
}*/