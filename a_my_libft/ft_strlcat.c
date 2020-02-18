/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:07:27 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/19 17:39:23 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t n;

	i = ft_strlen(dest);
	n = ft_strlen(src);
	if (i > size)
		i = size;
	if (i == size)
		return (size + n);
	if (n < size - i)
		ft_memcpy(dest + i, src, n + 1);
	else
	{
		ft_memcpy(dest + i, src, size - i - 1);
		dest[size - 1] = '\0';
	}
	return (i + n);
}
