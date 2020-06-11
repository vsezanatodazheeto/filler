/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 07:54:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/23 22:58:44 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int			count_summ(t_f *f, int x, int y, int count)
{
	int i;
	int j;
	int s;

	if (x + f->p->height > f->m->height || y + f->p->width > f->m->width)
		return (0);
	s = 0;
	i = -1;
	while (++i < f->p->height)
	{
		j = -1;
		while (++j < f->p->width)
		{
			if (f->m->map[i + x][j + y] == -1 && f->p->piece[i][j] == 1)
				count++;
			if (f->m->map[i + x][j + y] == -2 && f->p->piece[i][j] == 1)
				return (0);
			if (count > 1)
				return (0);
			if (f->m->map[i + x][j + y] && f->p->piece[i][j] == 1)
				s = s + f->m->map[i + x][j + y];
		}
	}
	return (count == 1 ? s : 0);
}

void		find_best_pos(t_f *f)
{
	int		i;
	int		j;
	int		s;
	int		min;

	min = INT_MAX;
	f->pos->i = 0;
	f->pos->j = 0;
	s = 0;
	i = -1;
	while (++i < f->m->height)
	{
		j = -1;
		while (++j < f->m->width)
		{
			s = count_summ(f, i, j, 0);
			if (s && s < min)
			{
				min = s;
				f->pos->i = i;
				f->pos->j = j;
			}
		}
	}
	return ;
}

int			min_distance(t_f *f, int x, int y)
{
	int i;
	int j;
	int min;

	i = 0;
	min = ((f->m->height * f->m->width) - 2);
	while (i < f->m->height)
	{
		j = 0;
		while (j < f->m->width)
		{
			if (f->m->map[i][j] == -2 && manhattan_formula(i, j, x, y) < min)
				min = manhattan_formula(i, j, x, y);
			j++;
		}
		i++;
	}
	return (min);
}

void		fill_manhattan_distance(t_f *f)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < f->m->height)
	{
		j = 0;
		while (j < f->m->width)
		{
			if (f->m->map[i][j] != -1 && f->m->map[i][j] != -2)
				f->m->map[i][j] = min_distance(f, i, j);
			j++;
		}
		i++;
	}
	return ;
}

void		solving_filler(t_f *f, char **line)
{
	while (get_next_line(0, &(*line)))
	{
		if (**line == 'P' && ft_strinstr(*line, NAME_FIELD))
		{
			if (!f->m->map)
				if (record_map(f, &(*line)) == 1)
					break ;
			if (!(get_next_line(0, &(*line))))
				break ;
			record_map_positions(f, &(*line));
			fill_manhattan_distance(f);
		}
		else if (**line == 'P' && ft_strinstr(*line, NAME_PIECE))
		{
			if (record_piece(f, &(*line)) == 1)
				break ;
			record_piece_positions(f, &(*line));
			find_best_pos(f);
			ft_printf("%d %d\n", f->pos->i, f->pos->j);
		}
	}
	return ;
}
