/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kek.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:05:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/01 15:35:43 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../a_libft/libft.h"

typedef struct		s_t
{
	char			*k;
}					t_t;

typedef struct		s_k
{
	char			*k;
	t_t				*t;
	struct s_k		*next;
}					t_k;

t_k  *new_t_filler()
{
        t_k  *ptr;

        if (!(ptr = malloc(sizeof(t_k))))
			return (NULL);
        ptr->next = NULL;
        return (ptr);
}

void    add_struct(t_k **lst)
{
        t_k  *ptr;

		ptr = new_t_filler();
		(*lst)->next = ptr;
		*lst = (*lst)->next;
		return ;
}

void	freestruct(t_k **lst)
{
	t_k *cur;

	while ((*lst)->next)
	{
		cur = *lst;
		ft_strdel(&cur->k);
		*lst = (*lst)->next;
		free(cur);
	}
	ft_strdel(&(*lst)->k);
	free(*lst);
	lst= NULL;
	return ;
}

int		main() 
{ 
	t_k *k;
	t_k *fst;
	t_k *fst_l;

	k = new_t_filler();
	fst = k;
	fst_l = k;

	k->k = ft_itoa(555);
	add_struct(&k);
	k->k = ft_itoa(666);
	add_struct(&k);
	k->k = ft_itoa(777);
	// freestruct(&fst_l);
	return (0);
}