/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:18:30 by rretta            #+#    #+#             */
/*   Updated: 2019/09/09 22:55:08 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *where, const char *what, size_t n)
{
	unsigned int	j;
	size_t			q;

	if (!*what)
		return ((char *)where);
	while (*where && n != 0)
	{
		j = 0;
		q = n;
		while (*(what + j) && (*(where + j) == *(what + j)) && q != 0)
		{
			q--;
			j++;
		}
		if (*(what + j) == '\0')
			return ((char *)(where));
		where++;
		n--;
	}
	return (NULL);
}
