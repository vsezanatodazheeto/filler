/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:32:16 by rretta            #+#    #+#             */
/*   Updated: 2019/09/09 14:50:52 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char		*tmpdest;
	const unsigned char	*tmpsrc;

	tmpdest = (unsigned char*)dest;
	tmpsrc = (const unsigned char*)src;
	if (tmpdest == tmpsrc)
		return (dest);
	while (num-- > 0)
		*(tmpdest++) = *(tmpsrc++);
	return (dest);
}
