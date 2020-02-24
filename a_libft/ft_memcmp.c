/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 01:02:48 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/15 20:10:02 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *dest, const void *src, size_t n)
{
	unsigned char	*dest_1;
	unsigned char	*src_1;
	size_t			i;

	i = 0;
	dest_1 = (unsigned char *)dest;
	src_1 = (unsigned char *)src;
	while (i < n)
	{
		if (*dest_1 == *src_1)
		{
			dest_1++;
			src_1++;
		}
		else
			return (*dest_1 - *src_1);
		i++;
	}
	return (0);
}
