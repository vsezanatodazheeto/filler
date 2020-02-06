/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:18:01 by rretta            #+#    #+#             */
/*   Updated: 2019/09/10 20:43:50 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int ch, size_t num)
{
	unsigned char			*tmpdest;
	const unsigned char		*tmpsrc;
	unsigned char			c;

	tmpdest = (unsigned char*)dest;
	tmpsrc = (const unsigned char*)src;
	c = (unsigned char)ch;
	while (num > 0)
	{
		*(tmpdest) = *(tmpsrc);
		if (*(tmpdest) == c)
			return ((void *)(tmpdest + 1));
		tmpdest++;
		tmpsrc++;
		num--;
	}
	return (NULL);
}
