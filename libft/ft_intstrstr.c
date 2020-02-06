/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intstrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 23:32:36 by rretta            #+#    #+#             */
/*   Updated: 2020/02/01 23:37:47 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intstrstr(const char *where, const char *what)
{
	unsigned int	j;

	if (!*what)
		return (1);
	while (*where)
	{
		j = 0;
		while (*(what + j) && (*(where + j) == *(what + j)))
			j++;
		if (*(what + j) == '\0')
			return (1);
		where++;
	}
	return (0);
}
