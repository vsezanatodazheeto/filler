/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:36:14 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/19 17:58:50 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		count_pointers(char const *s, char c)
{
	unsigned int i;
	unsigned int z;

	i = 0;
	z = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			z++;
			i++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (z);
}

static unsigned int		pointer_placed(char const *s, char c, unsigned int n)
{
	while (s[n] == c && s[n] != '\0')
		n++;
	if (s[n] != c && s[n] != '\0')
	{
		while (s[n] != c && s[n] != '\0')
			n++;
	}
	return (n);
}

static unsigned int		size_of_word(char const *s, char c, int n)
{
	unsigned int	word;

	word = 0;
	while (s[n] == c && s[n] != '\0')
		n++;
	if (s[n] != c && s[n] != '\0')
	{
		while (s[n] != c && s[n] != '\0')
		{
			n++;
			word++;
		}
	}
	return (word);
}

static void				*ft_free(char **dest)
{
	size_t i;

	i = 0;
	while (dest[i])
	{
		ft_memdel((void *)dest[i]);
		i++;
	}
	return (NULL);
}

char					**ft_strsplit(char const *s, char c)
{
	char				**dest;
	unsigned int		i;
	unsigned int		n;
	unsigned int		word;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	dest = (char**)malloc(sizeof(char*) * (count_pointers(s, c) + 1));
	if (!dest)
		return (NULL);
	while (i < count_pointers(s, c))
	{
		word = size_of_word(s, c, n);
		n = pointer_placed(s, c, n);
		if (!(dest[i] = ft_strsub(s, n - word, word)))
			return (ft_free(dest));
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
