/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:05:34 by rretta            #+#    #+#             */
/*   Updated: 2019/09/11 21:08:29 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	c;
	size_t	i;

	c = (char)ch;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i--;
	}
	if (str[i] == c)
		return ((char *)(str + i));
	return (NULL);
}
