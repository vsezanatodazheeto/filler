/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:53:57 by rretta            #+#    #+#             */
/*   Updated: 2019/09/10 22:15:00 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char			*tmpdest;
	const unsigned char		*tmpsrc;

	tmpdest = (unsigned char*)dest;
	tmpsrc = (const unsigned char*)src;
	if (dest == src)
		return (dest);
	if (tmpdest < tmpsrc)
	{
		while (num > 0)
		{
			*(tmpdest++) = *(tmpsrc++);
			num--;
		}
	}
	else
	{
		while (num > 0)
		{
			*(tmpdest + num - 1) = *(tmpsrc + num - 1);
			num--;
		}
	}
	return (dest);
}
