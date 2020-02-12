/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:55:23 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 23:55:37 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*record_bit(t_format *spec, char *str, int str_len, uint64_t unval)
{
	int	i;
	int bit;

	i = 0;
	bit = str_len - spec->width - 1;
	if (!(str = (char *)malloc(sizeof(char) * (str_len + spec->width + 1))))
		return (0);
	str[str_len] = '\0';
	if (spec->minus == 0 && spec->width)
		while (spec->width--)
			str[i++] = ' ';
	while (bit >= 0)
	{
		if (unval & 1 << bit--)
			str[i] = '1';
		else
			str[i] = '0';
		i++;
	}
	if (spec->minus == 1 && spec->width)
		while (spec->width--)
			str[i++] = ' ';
	return (str);
}
