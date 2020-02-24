/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:18:41 by yshawn            #+#    #+#             */
/*   Updated: 2019/12/11 19:32:33 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		ft_str_sym_cmp(char *str_dad, char *str_son, char ch)
{
	int		i;

	i = 0;
	while (*str_dad && *str_son && *str_dad != ch)
	{
		if (*str_dad != *str_son)
			return (0);
		str_dad++;
		str_son++;
		i++;
	}
	return ((*str_dad == '}' && !*str_son) ? i : 0);
}
