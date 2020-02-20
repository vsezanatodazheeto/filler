/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:40:59 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/20 20:22:23 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		free_data(t_f *f, char **line)
{
	if (f->m->map)
		ft_arrdel((void ***)&f->m->map);
	if (f->p->piece)
		ft_arrdel((void ***)&f->p->piece);
	if (*line)
		free(*line);
	return ;
}

int			get_size(int *height, int *width, char **line)
{
	char	**tmp;

	if (!(tmp = ft_strsplit(*line, ' ')))
		return (1);
	*height = ft_atoi(*(tmp + 1));
	*width = ft_atoi(*(tmp + 2));
	ft_arrdel((void ***)&tmp);
	return (0);
}

int			manhattan_formula(int x, int y, int i, int j)
{
	int		a;
	int		b;

	if (i > x)
		a = i - x;
	else
		a = x - i;
	if (j > y)
		b = j - y;
	else
		b = y - j;
	return (a + b);
}

void		init_structs(t_f *f, t_p *p, t_m *m, t_pos *pos)
{
	f->ally = '\0';
	f->enemy = '\0';
	f->p = NULL;
	f->m = NULL;
	f->pos = NULL;
	p->width = 0;
	p->height = 0;
	p->piece = NULL;
	m->width = 0;
	m->height = 0;
	m->map = NULL;
	pos->i = 0;
	pos->j = 0;
	pos->x = 0;
	pos->y = 0;
	f->m = m;
	f->p = p;
	f->pos = pos;
}
