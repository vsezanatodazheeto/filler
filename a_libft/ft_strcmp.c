/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:17:18 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/18 16:55:13 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *dest_1;
	unsigned char *src_1;

	dest_1 = (unsigned char *)s1;
	src_1 = (unsigned char *)s2;
	while (*dest_1 != '\0' && *src_1 != '\0')
	{
		if (*dest_1 != *src_1)
			return (*dest_1 - *src_1);
		dest_1++;
		src_1++;
	}
	return (*dest_1 - *src_1);
}
