/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:53:58 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/23 10:00:12 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse_float_nan_inf(t_format *spec, char str_num)
{
	if (str_num == 'n' || str_num == 'i' || str_num == 'N' || str_num == 'I')
	{
		if (str_num == 'n' || str_num == 'N')
		{
			spec->space = 0;
			spec->plus = 0;
		}
		spec->zero = 0;
	}
	return ;
}

int		parse_float(t_format *spec, va_list vl)
{
	long double		fval;
	size_t			len_num;
	size_t			len_flag;
	char			*str_num;
	char			*str_flag;

	str_flag = NULL;
	str_num = NULL;
	fval = 0;
	ft_cast_size_float(spec, vl, &fval);
	if (spec->accur >= 0)
	{
		if (spec->accur == 0)
			(spec->sharp) ? (spec->sharp += 0) : (spec->accur--);
	}
	else
		spec->accur = 6;
	str_num = parse_float_number(fval, spec);
	len_num = ft_strlen(str_num);
	parse_float_nan_inf(spec, *str_num);
	str_flag = parse_float_flag(spec, len_num);
	len_flag = ft_strlen(str_flag);
	record_float(spec, &str_flag, &str_num);
	return (len_num + len_flag + (spec->sign | spec->plus) + spec->space);
}
