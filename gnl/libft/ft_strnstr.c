/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:29:47 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/19 17:55:59 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t i;
	size_t s2_len;

	if (!*src)
		return ((char *)dest);
	s2_len = ft_strlen(src);
	while (*dest && len >= s2_len)
	{
		i = 0;
		while (*(src + i) && *(dest + i) == *(src + i))
			i++;
		if (*(src + i) == '\0')
			return ((char *)dest);
		dest++;
		len--;
	}
	return (NULL);
}
