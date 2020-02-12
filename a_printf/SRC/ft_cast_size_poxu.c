/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:57:22 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/22 20:49:09 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_cast_size_poxu(t_format *spec, va_list ap, u_int64_t *ival)
{
	if (spec->size == 1)
		*ival = (unsigned short)va_arg(ap, int);
	else if (spec->size == 2)
		*ival = (unsigned char)va_arg(ap, int);
	else if (spec->size == 3)
		*ival = va_arg(ap, unsigned long);
	else if (spec->size == 4)
		*ival = va_arg(ap, unsigned long long);
	else if (spec->type == 'p')
		*ival = va_arg(ap, unsigned long long);
	else
		*ival = va_arg(ap, unsigned int);
	if (spec->type == 'u')
		spec->base = 10;
	else if (spec->type == 'o')
		spec->base = 8;
	else
		spec->base = 16;
	return ;
}
