/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:53:58 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:55:18 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		parse_chr(t_format *spec, va_list vl)
{
	char			ch;
	char			*str;

	str = NULL;
	ch = (char)va_arg(vl, int);
	if (spec->width > 1)
	{
		str = record_chr(spec, str, ch);
		if (str)
		{
			write(1, str, spec->width);
			free(str);
		}
	}
	else
	{
		write(1, &ch, 1);
		return (1);
	}
	return (spec->width);
}
