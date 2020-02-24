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

void	parse_dipoxu_case(t_format *spec, uint64_t unval, int *num_len)
{
	if (spec->zero)
		if (spec->accur >= 0)
			spec->zero = 0;
	if (spec->accur >= 0)
		parse_dipoxu_accur(spec, unval, num_len);
	if (spec->sharp || spec->type == 'p')
		parse_dipoxu_sharp(spec, unval);
	if (spec->plus)
		parse_dipoxu_plus(spec);
	if (spec->space)
		parse_dipoxu_space(spec, *num_len);
	if (spec->width)
		parse_dipoxu_width(spec, *num_len);
	return ;
}

int		parse_dipoxu(t_format *spec, va_list vl)
{
	int			num_len;
	int64_t		ival;
	uint64_t	unval;

	ival = 0;
	unval = 0;
	if (spec->type == 'd' || spec->type == 'i')
	{
		ft_cast_size_di(spec, vl, &ival);
		if (ival < 0)
			(unval = ival * (-1));
		else
			(unval = ival);
	}
	else
		ft_cast_size_poxu(spec, vl, &unval);
	num_len = ft_numlen(unval, spec->base);
	parse_dipoxu_case(spec, unval, &num_len);
	return (parse_num(spec, unval, num_len));
}
