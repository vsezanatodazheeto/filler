/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:04:48 by rretta            #+#    #+#             */
/*   Updated: 2019/09/17 23:18:44 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	char	buf;

	if (!str)
		return (NULL);
	i = 0;
	while (i < (ft_strlen(str) + 1) / 2)
	{
		buf = str[i];
		str[i] = str[ft_strlen(str) - i];
		str[ft_strlen(str) - i] = buf;
		i++;
	}
	return (str);
}
