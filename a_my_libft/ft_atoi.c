/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:20:16 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/19 17:10:09 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int			i;
	unsigned long long	n;
	int					neg;

	i = 0;
	n = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\n')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	if (n > 9223372036854775807)
		return (neg > 0 ? -1 : 0);
	else
		return ((int)n * neg);
}
