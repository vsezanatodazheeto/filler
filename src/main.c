/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 07:54:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/23 21:47:36 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int			main(void)
{
	t_f		f[1];
	t_p		p[1];
	t_m		m[1];
	t_pos	pos[1];
	char	*line;

	line = NULL;
	init_structs(f, p, m, pos);
	if (check_player(f, &line) == 1)
	{
		ft_strdel(&line);
		return (1);
	}
	solving_filler(f, &line);
	free_data(f, &line);
	return (0);
}
