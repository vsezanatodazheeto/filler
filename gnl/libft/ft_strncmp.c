/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 01:52:40 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/19 17:57:01 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	if (((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0')) \
			&& n != 0 && i < n)
		return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
	return (0);
}
