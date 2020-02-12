/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:52:56 by rretta            #+#    #+#             */
/*   Updated: 2019/09/10 20:20:47 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)ptr;
	while (num != 0)
	{
		num--;
		tmp[num] = (unsigned char)value;
	}
	return (ptr);
}
