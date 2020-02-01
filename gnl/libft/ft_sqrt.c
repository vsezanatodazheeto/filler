/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:22:49 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/18 16:54:23 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb > 0)
	{
		while (i <= 46340)
		{
			if (i * i == nb)
				return (i);
			i++;
		}
	}
	return (0);
}
