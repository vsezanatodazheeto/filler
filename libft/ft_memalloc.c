/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:53:45 by rretta            #+#    #+#             */
/*   Updated: 2020/01/10 19:43:59 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *tmp;

	tmp = (unsigned char *)malloc(size);
	if (NULL == tmp)
		return (NULL);
	while (size != 0)
	{
		size--;
		*(tmp + size) = 0;
	}
	return ((void *)tmp);
}
