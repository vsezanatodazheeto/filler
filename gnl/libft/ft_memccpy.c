/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:08:49 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/19 17:59:24 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest_1;
	const unsigned char	*src_1;

	dest_1 = (unsigned char *)dest;
	src_1 = (unsigned char *)src;
	if (n != 0)
	{
		while (n--)
		{
			*dest_1 = *src_1;
			if (*src_1 == (unsigned char)c)
				return (dest_1 + 1);
			dest_1++;
			src_1++;
		}
	}
	return (NULL);
}
