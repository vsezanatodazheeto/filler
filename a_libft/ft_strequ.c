/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:05:11 by rretta            #+#    #+#             */
/*   Updated: 2019/09/11 21:11:46 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned char *str1;
	unsigned char *str2;

	if (!s1 || !s2)
		return (0);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	if ((*str1 && !*str2) || (*str2 && !*str1))
		return (0);
	return (1);
}
