/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:28:43 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/29 04:48:20 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arrdel(void ***arr)
{
	void	**first;
	if (!(**arr) || !(*arr))
		return ;
	first = *arr;
	while (**arr)
	{
		free(**arr);
		(*arr)++;
	}
	free(first);
	first = NULL;
	return ;
}
