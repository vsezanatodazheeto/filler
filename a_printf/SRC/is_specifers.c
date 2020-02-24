/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:23:20 by yshawn            #+#    #+#             */
/*   Updated: 2020/01/13 22:31:38 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*is_flag(t_format *spec, char *str)
{
	while (*str == '-' || *str == '+' || *str == ' ' || *str == '#' \
		|| *str == '0')
	{
		if (spec->minus == 0 && *str == '-')
			spec->minus = 1;
		else if (spec->plus == 0 && *str == '+')
			spec->plus = 1;
		else if (spec->sharp == 0 && *str == '#')
			spec->sharp = 2;
		else if (spec->zero == 0 && *str == '0')
			spec->zero = 1;
		else if (spec->space == 0 && *str == ' ')
			spec->space = 1;
		str++;
	}
	return (str);
}

char	*is_width(t_format *spec, char *str, va_list vl)
{
	if (*str == '*')
	{
		if ((spec->width = va_arg(vl, int)) < 0)
		{
			spec->minus = 1;
			spec->width = spec->width * (-1);
		}
		if (spec->width < 0)
			spec->width = 0;
		str++;
	}
	if (*str >= '1' && *str <= '9')
	{
		if ((spec->width = ft_atoi(str)) < 0)
			spec->width = 0;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	if (*str == '$')
	{
		spec->dollar = spec->width;
		spec->width = 0;
		str++;
	}
	return (str);
}

char	*is_accuracy(int *accur, char *str, va_list vl)
{
	*accur = 0;
	if (!*str)
		return (str);
	if (*str == '*')
	{
		if ((*accur = va_arg(vl, int)) < 0)
			*accur = -1;
		str++;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	else
	{
		if ((*accur = ft_atoi(str)) < 0)
			*accur = -1;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	return (str);
}

char	*is_size(char *size, char *str)
{
	if (*str == 'h')
	{
		*size = 1;
		if (*(str + 1) == 'h')
			*size = 2;
	}
	else if (*str == 'l' || *str == 'z')
	{
		*size = 3;
		if (*(str + 1) == 'l')
			*size = 4;
	}
	else if (*str == 'L')
		*size = 5;
	while (*str == 'l' || *str == 'L' || *str == 'h' || *str == 'z')
		str++;
	return (str);
}

char	*is_type(char *type, char *str)
{
	int		i;

	i = 0;
	while (i < TYPES_SIZE)
		if (*str == TYPES[i++])
			*type = *str;
	return (str);
}
