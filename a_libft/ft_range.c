/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:53:10 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/18 17:04:01 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int z;
	int n;
	int *array;

	n = 0;
	i = max - min;
	if (i <= 0)
		return (0);
	array = (int *)malloc(sizeof(int) * i);
	if (array == NULL)
		return (0);
	z = min;
	while (z < max)
	{
		array[n] = z;
		z++;
		n++;
	}
	return (array);
}
