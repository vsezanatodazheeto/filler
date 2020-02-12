/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:33:06 by rretta            #+#    #+#             */
/*   Updated: 2019/09/10 22:37:15 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t num)
{
	const unsigned char *str1;
	const unsigned char *str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (num != 0 && *str1 == *str2)
	{
		num--;
		str1++;
		str2++;
	}
	if (num == 0)
		return (0);
	return ((int)(*str1 - *str2));
}
