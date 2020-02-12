/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:15:09 by rretta            #+#    #+#             */
/*   Updated: 2019/09/11 21:14:04 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t num)
{
	const unsigned char	*tmpstr;
	unsigned char		c;

	tmpstr = (const unsigned char *)str;
	c = (unsigned char)ch;
	while (num != 0)
	{
		if (*(tmpstr) == c)
			return ((void *)tmpstr);
		num--;
		tmpstr++;
	}
	return (NULL);
}
