/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 23:39:07 by erodd             #+#    #+#             */
/*   Updated: 2020/01/23 07:20:04 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*parse_float_number(long double number, t_format *spec)
{
	t_cast		d1;
	char		*str_right;
	char		*str_left;
	char		*full_str;
	int			pow;

	full_str = NULL;
	d1 = (t_cast){ .ld = number };
	(spec->accur == -1) ? (spec->accur = 0) : (spec->accur += 0);
	pow = (int)d1.t_parts.exponent - 16383;
	if (d1.t_parts.exponent == 32767)
		return (ft_is_nan(d1.t_parts.mantisa, spec->type));
	if (d1.t_parts.exponent == 0)
		return (ft_zero_str(spec->accur, spec->sharp, full_str));
	str_right = parse_mantis(d1.t_parts.mantisa);
	str_left = parse_exponent(pow);
	full_str = ft_make_f_str(full_str, &str_right, &str_left);
	if (number >= 1 || number <= -1)
		full_str = make_dot(&full_str, d1.t_parts.exponent);
	else
		full_str = make_dot_zero(&full_str);
	full_str = ft_make_full_str(full_str, spec->accur, spec->sharp);
	return (full_str);
}

char	*ft_make_f_str(char *full, char **right, char **left)
{
	t_mult	m[1];
	int		k;
	int		i;

	i = 0;
	k = 0;
	m->len1 = 0;
	m->len2 = 0;
	m->str1 = NULL;
	m->str2 = NULL;
	if (!(full = (char *)malloc(sizeof(char) * 5000)))
		return (NULL);
	if (ft_strlen(*left) < ft_strlen(*right))
		fill_rigth_left(m, left, right);
	else
		fill_rigth_left(m, right, left);
	while (k < (m->len1 + m->len2))
	{
		full[k] = '0';
		k++;
	}
	full = ft_str_multiply(m, full);
	ft_clean_mult(m);
	return (full);
}

char	*ft_zero_str(int pres, char sharp, char *full_str)
{
	int g;

	g = 2;
	if (pres == 0)
		return (str_no_prec(sharp));
	else
	{
		if (!(full_str = (char *)malloc(sizeof(char) * (pres + 3))))
			return (NULL);
		full_str[0] = '0';
		full_str[1] = '.';
		while (g < (pres + 2))
			full_str[g++] = '0';
		full_str[g] = '\0';
		return (full_str);
	}
}

char	*parse_exponent(int pow)
{
	char	*str;

	if (pow > 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (pow * 0.301 + 1))))
			return (NULL);
		str = ft_pow(str, pow);
	}
	else if (pow == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = '1';
		str[1] = '\0';
		return (str);
	}
	else
	{
		pow = pow * -1;
		if (!(str = (char *)malloc(sizeof(char) * (pow + 1))))
			return (NULL);
		ft_bzero(str, pow - 1);
		str = ft_pow5(str, pow);
	}
	return (str);
}
