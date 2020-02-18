/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 03:44:30 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/18 16:50:58 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_1;
	const unsigned char	*src_1;

	dest_1 = (unsigned char *)dest;
	src_1 = (unsigned char *)src;
	if (dest_1 == NULL && src_1 == NULL)
		return (NULL);
	while (n--)
	{
		*dest_1 = *src_1;
		dest_1++;
		src_1++;
	}
	return (dest);
}
