/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kek.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:05:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/29 12:19:25 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../a_libft/libft.h"

typedef struct	s_k
{
	char *k;
}				t_k;

void	test1(t_k *k)
{
	k->k = ft_itoa(500);
	return ;
}

void	test(t_k *k)
{
	test1(k);
	return ;
}

int		main() 
{ 
	t_k k[1];
	test(k);
	printf("%s\n", k->k);
	return (0);
}