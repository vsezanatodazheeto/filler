/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kek.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:05:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/03 19:40:30 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../a_libft/libft.h"

char		*ft_strnew_size1(char **str, int size)
{
	int 	strlen;
	char	*tmp;

	strlen = ft_strlen(*str);
	tmp = NULL;
	printf("len is: %d\n", strlen);
	if (strlen >= size || strlen == 0)
		return (*str);
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		return (*str);

	tmp[size--] = '\0';
	while (--strlen >= 0)
	{
		tmp[size] = (*str)[strlen];
		size--;
	}
	while (size >= 0)
	{
		tmp[size] = ' ';
		size--;
	}
	ft_strdel(&(*str));
	return (tmp);
}

int		main() 
{ 
	char *tmp;	

	tmp = ft_itoa(50);
	printf("%s\n", tmp);
	tmp = ft_strnew_size1(&tmp, 3);
	tmp = ft_strnew_size1(&tmp, 3);
	printf("%s\n", tmp);
	return (0);
}