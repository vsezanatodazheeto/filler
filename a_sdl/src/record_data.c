/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:21:48 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/20 18:21:25 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

void			record_got_pos(t_f *f, char **line)
{
	char	**tmp;

	if (ft_is_strstr(*line, "O"))
		f->pos->turn = 'O';
	else
		f->pos->turn = 'X';
	tmp = ft_strsplit(*line, ' ');
	f->pos->i = ft_atoi(&(tmp[2][1]));
	f->pos->j = ft_atoi(&(tmp[3][0]));
	// ft_printf("positions: [%d, %d]\n", f->pos->i, f->pos->j);
	ft_memdel((void **)tmp);
	return ;
}

void			record_piece_positions(t_f *f, char **line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < f->p->height && get_next_line(0, &(*line)))
	{
		j = 0;
		while (j < f->p->width)
		{
			if ((*line)[j] == '.')
				f->p->piece[i][j] = 0;
			if ((*line)[j] == '*')
				f->p->piece[i][j] = 1;
			j++;
		}
		i++;
	}
	return ;
}

void			record_piece(t_f *f, char **line)
{	
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(*line, ' ');
	f->p->height = ft_atoi(*(tmp + 1));
	f->p->width = ft_atoi(*(tmp + 2));
	ft_memdel((void **)tmp);
	if (!(f->p->piece = (int **)malloc(sizeof(int *) * f->p->height)))
		exit(1);
	while (j < f->p->height)
	{
		if (!(f->p->piece[j] = (int *)malloc(sizeof(int) * f->p->width)))
			exit(1);
		j++;
	}
	return ;
}

void			record_map_positions(t_f *f, char **line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (get_next_line(0, &(*line)))
	 		;
	while (i < f->m->height && get_next_line(0, &(*line)))
	{
		j = 0;
		while (j < f->m->width)
		{
			if ((*line + HGT)[j] == '.')
				f->m->map[i][j] = 0;
			else if (ft_toupper((*line + HGT)[j]) == 'O' || ft_toupper((*line + HGT)[j]) == 'X')
			{
				if ((f->ally == 'O' && ft_toupper((*line + HGT)[j]) == 'O') ||
											(f->ally == 'X' && ft_toupper((*line + HGT)[j]) == 'X'))
					f->m->map[i][j] = -1;
				else
					f->m->map[i][j] = -2;
			}
			j++;
		}
		i++;
	}
	return ;
}

void			record_map(t_f *f, char **line)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(*line, ' ');
	f->m->height = ft_atoi(*(tmp + 1));
	f->m->width = ft_atoi(*(tmp + 2));
	ft_memdel((void **)tmp);
	if (!(f->m->map = (int **)malloc(sizeof(int *) * f->m->height)))
		exit(1);
	while (j < f->m->height)
	{
		if (!(f->m->map[j] = (int *)malloc(sizeof(int) * f->m->width)))
			exit(1);
		j++;
	}
	return ;
}

void 			record_player(t_f *f, int i)
{
	if (i)
	{
		f->ally = 'O';
		f->enemy = 'X';
	}
	else
	{
		f->ally = 'X';
		f->enemy = 'O';
	}
}

void			check_player(t_f *f, t_player *players, char **line)
{
	int			i;
	int			z;
	char		**p_1;
	char		**p_2;

	i = 0;
	z = 0;
	p_1 = NULL;
	p_2 = NULL;
	while (get_next_line(0, &(*line)))
	{
		if (**line == 'l' && z == 1)
		{
			p_2 = ft_strsplit(*line, '/');
			players->p2 = ft_strdup(p_2[1]);
			break ;
		}
		if (**line == 'l' && z == 0)
		{
			p_1 = ft_strsplit(*line, '/');
			players->p1 = ft_strdup(p_1[1]);
			z = 1;
		}
		if (**line == '$' && !f->ally && i == 0)
		{
			if (ft_is_strstr(*line, "p1"))
				record_player(f, TRUE);
			else
				record_player(f, FALSE);
			i = 1;
		}
	}
	return;
}