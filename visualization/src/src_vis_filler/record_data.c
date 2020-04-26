/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:21:48 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/03 22:36:38 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vis_filler.h"
#include "../../include/vis_sdl.h"

extern int		fd;

void			record_got_pos(t_f *f, char **line)
{
	char		**tmp;

	if (ft_strinstr(*line, "O"))
		f->pos->turn = 'O';
	else
		f->pos->turn = 'X';
	tmp = ft_strsplit(*line, ' ');
	f->pos->i = ft_atoi(&tmp[2][1]);
	f->pos->j = ft_atoi(&tmp[3][0]);
	ft_arrdel((void ***)&tmp);
	return ;
}

void			record_piece_positions(t_f *f, char **line)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < f->p->height && get_next_line(fd, &(*line)))
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

int				record_piece(t_f *f, char **line)
{
	int			j;

	j = 0;
	if (get_size(&f->p->height, &f->p->width, &(*line)) == 1)
		return (1);
	if (f->p->piece)
		ft_arrdel((void ***)&f->p->piece);
	if (!(f->p->piece = (int **)malloc(sizeof(int *) * (f->p->height + 1))))
		return (1);
	else
		f->p->piece[f->p->height] = NULL;
	while (j < f->p->height)
	{
		if (!(f->p->piece[j] = (int *)malloc(sizeof(int) * f->p->width)))
		{
			f->p->piece[j - 1] = NULL;
			ft_arrdel((void ***)&f->p->piece);
			return (1);
		}
		j++;
	}
	return (0);
}

void			record_map_positions(t_f *f, t_player *player, char **line)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!player->field)
		player->field = ft_namefield(f->m->height, f->m->width);
	while (i < f->m->height && get_next_line(fd, &(*line)))
	{
		j = 0;
		while (j < f->m->width)
		{
			if ((*line + ft_stsp(*line))[j] == '.')
				f->m->map[i][j] = 0;
			else if (ft_isupch((*line + ft_stsp(*line))[j], 'O', 'X'))
			{
				if (ft_isupch_2((*line + ft_stsp(*line))[j], player->ally, 'O', 'X'))
				{
					f->m->map[i][j] = -1;
					f->ally_cnt++;
				}
				else
				{
					f->m->map[i][j] = -2;
					f->enemy_cnt++;
				}
			}
			j++;
		}
		i++;
	}
	f->field_cnt = f->m->width * f->m->height - f->ally_cnt - f->enemy_cnt;
	return ;
}

int				record_map(t_f *f, char **line)
{
	int			j;

	j = 0;
	if (get_size(&f->m->height, &f->m->width, &(*line)) == 1)
		return (1);
	if (!(f->m->map = (int **)malloc(sizeof(int *) * (f->m->height + 1))))
		return (1);
	else
		f->m->map[f->m->height] = NULL;
	while (j < f->m->height)
	{
		if (!(f->m->map[j] = (int *)malloc(sizeof(int) * f->m->width)))
		{
			f->m->map[j] = NULL;
			ft_arrdel((void ***)&f->m->map);
			return (1);
		}
		j++;
	}
	return (0);
}

void			record_player(t_player *player, int i)
{
	if (i)
	{
		player->ally = 'O';
		player->enemy = 'X';
	}
	else
	{
		player->ally = 'X';
		player->enemy = 'O';
	}
}
