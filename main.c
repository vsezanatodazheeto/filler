/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 07:54:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/21 23:08:35 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/filler.h"

int			count_summ(t_f *f, int x, int y)
{
	int count;
	int count2;
	int i;
	int j;
	int s;

	i = 0;
	j = 0;
	s = 0;
	count = 0;
	count2 = 0;
	if (x + f->p->height > f->m->height || y + f->p->width > f->m->width)
		return (0);
	while (i < f->p->height)
	{
		j = 0;
		while (j < f->p->width)
		{
			if (f->m->map[i + x][j + y] == -2)
				return (0);
			if (f->m->map[i + x][j + y] == -1 && f->p->piece[i][j] == 1)
				count++;
			if (f->m->map[i + x][j + y] == -2 && f->p->piece[i][j] == 1)
				count2++;
			if (count > 1 || count2)
				return (0);
			if (f->m->map[i + x][j + y] && f->p->piece[i][j] == 1)
				s = s + f->m->map[i + x][j + y];
			j++;
		}
		i++;
	}
	return (count == 1 ? s : 0);
}

void		find_best_pos(t_f *f)
{
	int i;
	int j;
	int s;
	int min;

	i = 0;
	s = 0;
	min = 2000000;
	f->pos->i = 0;
	f->pos->j = 0;
	while (i < f->m->height)
	{
		j = 0;
		while (j < f->m->width)
		{
			s = count_summ(f, i, j);
			if (s && s < min)
			{
				min = s;
				f->pos->i = i;
				f->pos->j = j;
			}
			j++;
		}
		i++;
	}
	// ft_printf("%d\n", min);
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
			// printf_map_fill(f);
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
