/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:11:11 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/04 16:11:14 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vis_filler.h"
#include "../../include/vis_sdl.h"

void	add_struct(t_f **cur_lst)
{
	t_f *ptr;

	if (*cur_lst == NULL)
		*cur_lst = new_t_filler();
	else
	{
		ptr = new_t_filler();
		(*cur_lst)->next = ptr;
		ptr->prev = *cur_lst;
		*cur_lst = (*cur_lst)->next;
	}
	return ;
}

t_p		*new_t_piece(void)
{
	t_p *ptr;

	if (!(ptr = malloc(sizeof(t_p))))
		return (NULL);
	return (ptr);
}

t_m		*new_t_map(void)
{
	t_m *ptr;

	if (!(ptr = malloc(sizeof(t_m))))
		return (NULL);
	return (ptr);
}

t_pos	*new_t_pos(void)
{
	t_pos *ptr;

	if (!(ptr = malloc(sizeof(t_pos))))
		return (NULL);
	return (ptr);
}

t_f		*new_t_filler(void)
{
	t_f *ptr;

	if (!(ptr = malloc(sizeof(t_f))))
		return (NULL);
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}
