/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:55:48 by rretta            #+#    #+#             */
/*   Updated: 2019/09/11 18:04:27 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	q;
	char	*tmp;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	q = 0;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (NULL == tmp)
		return (NULL);
	while (q < i)
	{
		tmp[q] = (*f)(q, s[q]);
		q++;
	}
	tmp[q] = '\0';
	return (tmp);
}
