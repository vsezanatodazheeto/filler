/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabasex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:53:11 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:54:52 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_itoabasex(t_format *spec, uint64_t i, char *s, int num_len)
{
	uint64_t nymsys;

	nymsys = spec->base;
	while (i > 0)
	{
		if (i < nymsys)
		{
			if (spec->type != 'X')
				(s[num_len] = IT[i]);
			else
				(s[num_len] = ITX[i]);
			return ;
		}
		else
		{
			if (spec->type != 'X')
				(s[num_len] = IT[i % nymsys]);
			else
				(s[num_len] = ITX[i % nymsys]);
		}
		i = i / nymsys;
		num_len--;
	}
	return ;
}
