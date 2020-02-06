/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:17:44 by rretta            #+#    #+#             */
/*   Updated: 2019/09/16 21:26:41 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	if (!s1 || !s2)
		return (0);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (*str1 && *str2 && n != 0)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
		n--;
	}
	if (((*str1 && !*str2) || (*str2 && !*str1)) && n != 0)
		return (0);
	return (1);
}
