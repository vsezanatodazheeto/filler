/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:40:59 by yshawn            #+#    #+#             */
/*   Updated: 2020/06/15 00:02:15 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int			ft_isupch(char ch_1, char ch_2, char ch_3)
{
	return ((ft_toupper(ch_1) == ch_2 || ft_toupper(ch_1) == ch_3) ? 1 : 0);
}

int			ft_isupch_2(char str_ch_1, char str_ch_2, char ch_1, char ch_2)
{
	return (((ft_toupper(str_ch_1) == ch_1 && str_ch_2 == ch_1)
			|| (ft_toupper(str_ch_1) == ch_2 && str_ch_2 == ch_2)) ? 1 : 0);
}

int			ft_stsp(char *s)
{
	int		i;

	i = 0;
	while (s)
	{
		if (*s == ' ')
			return (i + 1);
		i++;
		s++;
	}
	return (0);
}

int			ft_strinstr(char *str_dad, char *str_son)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	if (!*str_dad || !*str_son)
		return (FALSE);
	while (str_dad[++i] && n == 0)
	{
		n = 0;
		if (str_dad[i] == str_son[n])
		{
			while (str_son[n] && str_dad[i])
			{
				if (str_son[n] != str_dad[i])
				{
					n = 0;
					break ;
				}
				i++;
				n++;
			}
		}
	}
	return (n == 0 ? FALSE : i);
}
