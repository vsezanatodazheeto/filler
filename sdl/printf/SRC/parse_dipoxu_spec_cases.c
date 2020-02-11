/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:39:02 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/24 00:05:09 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse_dipoxu_width(t_format *spec, int num_len)
{
	spec->width = spec->width - spec->sign - spec->space - spec->plus -
								spec->sharp - num_len;
	if (spec->accur > 0)
		spec->width = spec->width - spec->accur;
	if (spec->width <= 0)
		spec->width = 0;
	return ;
}

void	parse_dipoxu_accur(t_format *spec, uint64_t unval, int *num_len)
{
	if (spec->accur == 0 && unval == 0)
		*num_len = 0;
	if (spec->accur > *num_len)
		spec->accur = spec->accur - *num_len;
	else
		spec->accur = 0;
	return ;
}

void	parse_dipoxu_space(t_format *spec, int num_len)
{
	if (spec->type == 'u')
		spec->space = 0;
	if (spec->plus || spec->sign)
		spec->space = 0;
	if (spec->width > num_len + spec->accur && spec->accur != -1 &&
		spec->minus == 0 && spec->zero == 0)
		spec->space = 0;
	return ;
}

void	parse_dipoxu_plus(t_format *spec)
{
	if (spec->type == 'u')
		spec->plus = 0;
	if (spec->sign == 1)
		spec->plus = 0;
	return ;
}

void	parse_dipoxu_sharp(t_format *spec, uint64_t unval)
{
	if (spec->type == 'o')
	{
		if (unval == 0 && spec->accur != 0)
			spec->sharp = 0;
		else
			spec->sharp = 1;
	}
	if ((spec->accur == 0 && unval == 0 && spec->type != 'o') ||
		(unval == 0 && spec->type != 'o') ||
		(spec->accur > 0 && spec->type == 'o'))
		spec->sharp = 0;
	if (spec->type == 'p')
		spec->sharp = 2;
	return ;
}
