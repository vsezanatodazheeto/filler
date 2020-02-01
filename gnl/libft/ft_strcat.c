/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:36:08 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/18 16:54:33 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t z;

	z = 0;
	i = ft_strlen(dest);
	while (src[z] != '\0')
	{
		dest[i] = src[z];
		z++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
