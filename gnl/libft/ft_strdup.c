/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:53:30 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/18 16:58:27 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	l;
	char	*tmp;

	i = 0;
	l = ft_strlen(s);
	tmp = NULL;
	tmp = (char *)malloc(sizeof(char) * l + 1);
	if (tmp == NULL)
		return (NULL);
	while (i < l)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
