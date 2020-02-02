/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:31:23 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:56:32 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*record_per(t_format *spec, int i)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (i))))
		return (0);
	str[--i] = '\0';
	if (spec->minus == 1)
		while (i > 0)
			str[i--] = ' ';
	str[i--] = '%';
	if (spec->minus == 0)
	{
		while (i > 0)
		{
			if (spec->zero == 0)
				str[i--] = ' ';
			else if (spec->zero == 1)
				str[i--] = '0';
		}
		if (spec->zero == 0)
			str[i] = ' ';
		else if (spec->zero == 1)
			str[i] = '0';
	}
	return (str);
}
