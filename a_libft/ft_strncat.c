/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 02:28:43 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/19 17:54:56 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t z;

	z = 0;
	i = ft_strlen(dest);
	while (src[z] != '\0' && z < n)
		dest[i++] = src[z++];
	dest[i] = '\0';
	return (dest);
}
