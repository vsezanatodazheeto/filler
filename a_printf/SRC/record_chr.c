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

char	*record_chr(t_format *spec, char *str, char ch)
{
	int	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (spec->width))))
		return (NULL);
	i = spec->width - 1;
	str[i] = '\0';
	if (spec->minus == 1)
	{
		while (i > 0)
			str[i--] = ' ';
	}
	str[i--] = ch;
	if (spec->minus == 0)
	{
		while (i > 0)
			str[i--] = ' ';
		str[i] = ' ';
	}
	return (str);
}
