/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_accuracy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:56:50 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/23 20:57:00 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	record_sharp(t_format *spec, char *str, int *i)
{
	if (spec->sharp == 2)
	{
		if (spec->type != 'X')
			str[(*i)--] = 'x';
		else
			str[(*i)--] = 'X';
		str[(*i)--] = '0';
	}
	else
		str[(*i)--] = '0';
	return ;
}

void	record_sign(t_format *spec, char *str, int *i)
{
	if (spec->sign)
		str[(*i)--] = '-';
	else
		str[(*i)--] = '+';
	return ;
}

int		pcomic_i_num(t_format *spec, char *str, uint64_t unval, int num_len)
{
	int i;

	i = spec->width + spec->space + spec->plus + spec->sign +
		spec->sharp + num_len - 1;
	if (spec->accur > 0)
		i = i + spec->accur;
	while (spec->width > 0 && spec->minus == 1)
	{
		str[i--] = ' ';
		spec->width--;
	}
	if (unval == 0 && num_len > 0)
		str[i--] = '0';
	else if (unval > 0)
	{
		ft_itoabasex(spec, unval, str, i);
		i = i - num_len;
	}
	while (spec->accur > 0)
	{
		str[i--] = '0';
		spec->accur--;
	}
	return (i);
}

void	record_minus_num(t_format *spec, char *str, uint64_t unval, int nlen)
{
	int i;

	i = pcomic_i_num(spec, str, unval, nlen);
	if (spec->sharp)
		record_sharp(spec, str, &i);
	if (spec->plus || spec->sign)
		record_sign(spec, str, &i);
	if (spec->space)
		str[i--] = ' ';
	return ;
}

void	record_num(t_format *spec, char *str, uint64_t unval, int num_len)
{
	int i;

	i = pcomic_i_num(spec, str, unval, num_len);
	if (spec->zero == 0 && (spec->plus || spec->sign))
		record_sign(spec, str, &i);
	if (spec->sharp && spec->zero == 0)
		record_sharp(spec, str, &i);
	while (spec->width > 0)
	{
		if (spec->zero == 0)
			str[i--] = ' ';
		else
			str[i--] = '0';
		spec->width--;
	}
	if (spec->sharp && spec->zero == 1)
		record_sharp(spec, str, &i);
	if (spec->space)
		str[i--] = ' ';
	if (spec->zero == 1 && (spec->plus || spec->sign))
		record_sign(spec, str, &i);
	return ;
}
