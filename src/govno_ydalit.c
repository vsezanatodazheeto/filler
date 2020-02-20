/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   govno_ydalit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:40:59 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/20 19:54:06 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		printf_piece(t_f *f)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < f->p->height)
	{
		j = 0;
		while (j < f->p->width)
		{
			if (f->p->piece[i][j] == 0)
				ft_printf("%c", '.');
			else if (f->p->piece[i][j] == 1)
				ft_printf("%c", '*');
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("----------------\n");
	return ;
}

void		printf_map_fill(t_f *f)
{
	int		i;
	int		j;
	int		x;
	int		xx;
	int		y;

	i = 0;
	j = 0;
	x = 0;
	xx = 0;
	y = 0;
	ft_printf("\n\n");
	ft_printf("    ");
	while (x < f->m->width)
	{
		if (xx > 9)
			xx = 0;
		ft_printf("{yellow}%3d{eoc}", xx);
		x++;
		xx++;
	}
	ft_printf("\n");
	while (i < f->m->height)
	{
		j = 0;
		ft_printf("{yellow}% 3d{eoc} ", y);
		while (j < f->m->width)
		{
			if (f->m->map[i][j] == -1)
				ft_printf("{green}%3d", f->m->map[i][j]);
			else if (f->m->map[i][j] == -2)
				ft_printf("{red}%3d", f->m->map[i][j]);
			else
				ft_printf("{eoc}%3d", f->m->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
		y++;
	}
	ft_printf("\n");
	return ;
}

void		printf_map(t_f *f)
{
	int		i;
	int		j;
	int		x;
	int		xx;
	int		y;

	i = 0;
	j = 0;
	x = 0;
	xx = 0;
	y = 0;
	ft_printf("    ");
	while (x < f->m->width)
	{
		if (xx > 9)
			xx = 0;
		ft_printf("%d", xx);
		x++;
		xx++;
	}
	ft_printf("\n");
	while (i < f->m->height)
	{
		j = 0;
		ft_printf("%3d ", y);
		while (j < f->m->width)
		{
			if (f->m->map[i][j] == -1)
				ft_printf("{green}O");
			else if (f->m->map[i][j] == -2)
			{
				ft_printf("{red}X");
			}
			else
				ft_printf("{eoc}.");
			j++;
		}
		ft_printf("\n");
		i++;
		y++;
	}
	ft_printf("\n");
	return ;
}
