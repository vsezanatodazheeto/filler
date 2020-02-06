/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:56:28 by rretta            #+#    #+#             */
/*   Updated: 2019/09/16 21:30:10 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned char *tmp;

	if (size + 1 == 0)
		return (NULL);
	tmp = (unsigned char *)malloc(sizeof(char) * (size + 1));
	if (NULL == tmp)
		return (NULL);
	*tmp = '\0';
	while (size != 0)
	{
		*(tmp + size) = '\0';
		size--;
	}
	return ((char *)tmp);
}
