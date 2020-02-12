/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:16:30 by rretta            #+#    #+#             */
/*   Updated: 2019/09/17 23:20:44 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_list_size(t_list *lst)
{
	t_list	*ptr;
	size_t	q;

	q = 0;
	if (!lst)
		return (q);
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		q++;
	}
	return (q);
}
