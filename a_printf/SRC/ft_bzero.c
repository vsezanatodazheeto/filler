/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <erodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:09:26 by erodd             #+#    #+#             */
/*   Updated: 2020/01/23 03:41:17 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_bzero(void *str, size_t n)
{
	char *str_new;

	str_new = str;
	while (n--)
		*(str_new++) = '0';
}
