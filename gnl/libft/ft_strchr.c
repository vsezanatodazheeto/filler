/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 02:47:14 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/18 16:54:43 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	size_t	i;
	size_t	n;

	i = ft_strlen(s);
	n = 0;
	chr = c;
	while (n <= i)
	{
		if (s[n] == chr)
			return ((char *)s + n);
		n++;
	}
	return (NULL);
}
