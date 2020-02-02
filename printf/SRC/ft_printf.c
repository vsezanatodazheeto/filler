/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:31:27 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/23 02:55:44 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	printf_printf(char *str, int *cnt)
{
	write(1, str, 1);
	(*cnt)++;
	return ;
}

int		print_b(t_format *spec, char *str, va_list vl, va_list fst_vl)
{
	int		cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == '{')
			str = parse_bcolor(str);
		if (*str != '%')
			printf_printf(str, &cnt);
		else if (*str == '%')
		{
			str = parse_specifiers(spec, ++str, vl);
			if (spec->type)
				cnt = cnt + parse_output(spec, vl, fst_vl);
			else if (*str != '%' && *str)
				printf_printf(str, &cnt);
		}
		if (!*str)
			return (cnt);
		str++;
	}
	return (cnt);
}

int		ft_printf(const char *format, ...)
{
	char		*str;
	va_list		fst_vl;
	va_list		vl;
	int			cnt;
	t_format	spec[1];

	va_start(vl, format);
	va_copy(fst_vl, vl);
	str = (char *)format;
	cnt = print_b(spec, str, vl, fst_vl);
	va_end(vl);
	return (cnt);
}
