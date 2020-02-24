/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 00:48:47 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/18 16:50:49 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *dest;
	char chr;

	chr = (char)c;
	dest = (char *)s;
	while (n--)
	{
		if (*dest == chr)
			return (dest);
		dest++;
	}
	return (NULL);
}
