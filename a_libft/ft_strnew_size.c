/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:07:54 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/27 17:14:15 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew_size(char *str, int size)
{
	int 	strlen;
	char	*tmp;

	strlen = ft_strlen(str);
	tmp = NULL;
	if (strlen >= size || strlen == 0)
		return (str);
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		return (str);

	tmp[size--] = '\0';
	while (--strlen >= 0)
	{
		tmp[size] = str[strlen];
		size--;
	}
	while (size >= 0)
	{
		tmp[size] = ' ';
		size--;
	}
	return (tmp);
}
