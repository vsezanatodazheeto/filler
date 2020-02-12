/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:54:11 by rretta            #+#    #+#             */
/*   Updated: 2019/09/17 17:17:07 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (NULL == ptr)
		return (NULL);
	if (content == NULL)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	else
	{
		ptr->content = malloc(content_size);
		if (NULL == ptr->content)
			return (NULL);
		ft_memmove(ptr->content, content, content_size);
		ptr->content_size = content_size;
	}
	ptr->next = NULL;
	return (ptr);
}
