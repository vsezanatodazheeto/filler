/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 04:46:08 by erodd             #+#    #+#             */
/*   Updated: 2020/01/23 07:19:56 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*str_nan_inf(char ch, char type)
{
	int		i;
	char	*str;

	i = -1;
	if (!(str = (char *)malloc(sizeof(char) * 4)))
		return (NULL);
	if (ch == 'i')
		while (++i < NAN_INF_SIZE)
		{
			if (type == 'f')
				str[i] = INF_F[i];
			else
				str[i] = INF_F_UP[i];
		}
	else
		while (++i < NAN_INF_SIZE)
		{
			if (type == 'f')
				str[i] = NAN_F[i];
			else
				str[i] = NAN_F_UP[i];
		}
	str[i] = '\0';
	return (str);
}

char	*ft_is_nan(unsigned long mantisa, char type)
{
	uint64_t head;
	uint64_t tail;

	head = mantisa >> 62;
	tail = mantisa << 2;
	if (head == 0)
	{
		if (tail == 0)
			return (str_nan_inf('i', type));
		else
			return (str_nan_inf('n', type));
	}
	else if ((head == 1) || (head == 3))
		return (str_nan_inf('n', type));
	else
	{
		if (tail == 0)
			return (str_nan_inf('i', type));
		else
			return (str_nan_inf('n', type));
	}
}

char	*ft_str_multiply(t_mult *m, char *tmp)
{
	int i;
	int j;
	int shift;
	int mem;
	int res;

	shift = 0;
	i = m->len2 + 1;
	while (--i >= 0)
	{
		j = m->len1 + 1;
		mem = 0;
		while (--j >= 0)
		{
			res = (m->str2[j] - '0') * (m->str1[i] - '0') +
			(tmp[j + m->len2 + 1 - shift] - '0') + mem;
			mem = res / 10;
			tmp[j + m->len2 + 1 - shift] = res % 10 + '0';
			if (j == 0)
				tmp[i] = mem + '0';
		}
		shift++;
	}
	tmp[m->len2 + m->len1 - 1] = '\0';
	return (tmp);
}

char	*ft_pow(char *res, int pow)
{
	int len;
	int ret;
	int dec;
	int j;

	len = pow * 0.301 + 1;
	ret = 0;
	res[len] = '\0';
	res[len - 1] = '2';
	j = -1;
	while (j++ < (len - 2))
		res[j] = '0';
	while (pow > 1)
	{
		len = ft_strlen(res) - 1;
		while (len >= 0)
		{
			dec = res[len] - '0';
			res[len--] = (dec * 2 + ret) % 10 + '0';
			ret = (dec * 2 + ret) < 10 ? 0 : 1;
		}
		res[len] = ret + '0';
		pow--;
	}
	return (res);
}

char	*ft_pow5(char *res, int pow)
{
	int len;
	int ret;
	int dec;
	int j;

	len = pow;
	ret = 0;
	res[pow] = '\0';
	res[len - 1] = '5';
	j = 0;
	while (j < (len - 2))
		res[j++] = '0';
	while (pow > 1)
	{
		len = ft_strlen(res) - 1;
		while (len > 0)
		{
			dec = res[len] - '0';
			res[len--] = (dec * 5 + ret) % 10 + '0';
			ret = (dec * 5 + ret) < 10 ? 0 : ((dec * 5 + ret) / 10);
		}
		res[len] = ret + '0';
		pow--;
	}
	return (res);
}
