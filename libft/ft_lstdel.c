/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:39:32 by rretta            #+#    #+#             */
/*   Updated: 2019/09/17 18:22:06 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*tmp;

	if (!alst || !del)
		return ;
	ptr = *alst;
	while (ptr)
	{
		tmp = ptr->next;
		ft_lstdelone(&ptr, del);
		ptr = tmp;
	}
	*alst = NULL;
}
