/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:39:46 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/18 16:59:53 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	to_the_end(char const *s)
{
	size_t i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	return (i);
}

static size_t	to_the_start(char const *s, size_t n)
{
	while ((s[n] == ' ' || s[n] == '\t' || s[n] == '\n') && s[n] != 0)
		n--;
	return (n);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	n;
	size_t	z;
	char	*dest;

	if (!s)
		return (NULL);
	i = to_the_end(s);
	n = to_the_start(s, ft_strlen(s) - 1);
	z = 0;
	if (i == ft_strlen(s) || n == 0)
	{
		dest = (char *)malloc(sizeof(char) * 1);
		dest[0] = '\0';
		return (dest);
	}
	else
		dest = (char *)malloc(sizeof(char) * (n - i + 1 + 1));
	if (!dest)
		return (NULL);
	while (i <= n)
		dest[z++] = s[i++];
	dest[z] = '\0';
	return (dest);
}
