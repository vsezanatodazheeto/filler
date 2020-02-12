/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:16:41 by rretta            #+#    #+#             */
/*   Updated: 2019/09/16 17:30:18 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_null_term(void)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char));
	if (NULL == tmp)
		return (NULL);
	*tmp = '\0';
	return (tmp);
}

char			*ft_strtrim(char const *s)
{
	size_t	b;
	size_t	f;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (!*s)
		return (ft_null_term());
	b = 0;
	f = ft_strlen(s) - 1;
	i = 0;
	while (s[b] != '\0' && (s[b] == ' ' || s[b] == '\n' || s[b] == '\t'))
		b++;
	while (b != ft_strlen(s) && (s[f] == ' ' || s[f] == '\n' || s[f] == '\t'))
		f--;
	str = (char *)malloc(sizeof(char) * (f - b + 1 + 1));
	if (NULL == str)
		return (NULL);
	while (b <= f)
		str[i++] = s[b++];
	str[i] = '\0';
	return (str);
}
