/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smbu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 05:39:01 by erodd             #+#    #+#             */
/*   Updated: 2020/01/23 05:23:05 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*parse_mantis(unsigned long mantisa)
{
	char	*str;
	int		j;

	str = (char *)malloc(sizeof(char) * 65);
	str[64] = '\0';
	j = 0;
	while (j <= 63)
	{
		str[j] = '0';
		j++;
	}
	str = make_mantisa(str, mantisa);
	return (str);
}

char	*itobs(uint64_t num, char *str)
{
	int			i;
	uint64_t	size;

	size = CHAR_BIT * sizeof(uint64_t);
	i = size - 1;
	while (i >= 0)
	{
		str[i] = (01 & num) + '0';
		i--;
		num >>= 1;
	}
	str[size] = '\0';
	return (str);
}

void	fill_rigth_left(t_mult *m, char **a, char **b)
{
	m->str2 = *a;
	m->str1 = *b;
	m->len1 = ft_strlen(*a) - 1;
	m->len2 = ft_strlen(*b) - 1;
}

char	*str_no_prec(char sharp)
{
	char	*full_str;

	full_str = NULL;
	if (sharp)
	{
		if (!(full_str = (char *)malloc(sizeof(char) * 3)))
			return (NULL);
		full_str[0] = '0';
		full_str[1] = '.';
		full_str[2] = '\0';
	}
	else
	{
		if (!(full_str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		full_str[0] = '0';
		full_str[1] = '\0';
	}
	return (full_str);
}
