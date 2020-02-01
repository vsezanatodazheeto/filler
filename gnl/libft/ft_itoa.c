/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:28:43 by yshawn            #+#    #+#             */
/*   Updated: 2019/09/18 16:46:25 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	z;
	unsigned int	size;
	char			*dest;

	size = ft_size_nbrstr(n);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = size - 1;
	if (n < 0)
		z = n * -1;
	else
		z = n;
	while (i > 0)
	{
		dest[i] = (z % 10) + 48;
		z = z / 10;
		i--;
	}
	dest[0] = (z % 10) + 48;
	if (n < 0)
		dest[0] = '-';
	dest[size] = '\0';
	return (dest);
}
