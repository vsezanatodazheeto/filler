/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:56:42 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/23 07:02:08 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			parse_float_flag_2(t_format *spec, int num_len)
{
	if (spec->width)
		(spec->width >= num_len) ? (spec->width -= num_len) : (spec->width = 0);
	if (spec->space)
		if (spec->plus || spec->sign)
			spec->space = 0;
	if (spec->plus)
		if (spec->sign == 1)
			spec->plus = 0;
	if (spec->zero)
		if (spec->minus)
			spec->zero = 0;
	return (spec->width - spec->plus - spec->sign - spec->space);
}

char		*parse_float_flag(t_format *spec, int num_len)
{
	int			i;
	int			str_len;
	char		*str_flag;

	i = 0;
	str_flag = NULL;
	str_len = parse_float_flag_2(spec, num_len);
	if (str_len > 0)
	{
		if (!(str_flag = (char *)malloc(sizeof(char) * (str_len + 1))))
			return (NULL);
	}
	else
		return (NULL);
	str_flag[str_len] = '\0';
	while (i < str_len)
		if (spec->zero == 1)
			str_flag[i++] = '0';
		else
			(str_flag[i++] = ' ');
	return (str_flag);
}
