/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:53:30 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/29 04:36:25 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	strlen;
	char	*tmp;

	i = 0;
	strlen = ft_strlen(s);
	tmp = NULL;
	tmp = (char *)malloc(sizeof(char) * (strlen + 1));
	if (tmp == NULL)
		return (NULL);
	while (i < strlen)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
