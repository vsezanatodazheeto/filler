/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:33:57 by rretta            #+#    #+#             */
/*   Updated: 2019/09/11 21:14:39 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	size_t	q;

	i = ft_strlen(src);
	q = 0;
	while (q <= i)
	{
		dest[q] = src[q];
		q++;
	}
	return (dest);
}
