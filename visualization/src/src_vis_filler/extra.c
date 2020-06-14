/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:17:40 by yshawn            #+#    #+#             */
/*   Updated: 2020/06/14 23:49:29 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vis_filler.h"
#include "../../include/vis_sdl.h"

extern int		fd;

int				check_player(t_player *player, char **line)
{
	char		**player_name;
	int			n;

	n = 0;
	player_name = NULL;
	while (get_next_line(fd, &(*line)))
	{
		if (**line == 'l')
		{
			if (!player_name)
			{
				n = 0;
				player_name = ft_strsplit(*line, '/');
				while (player_name[n])
					n++;
				player->p1 = ft_strdup(player_name[n - 1]);
			}
			else
			{
				ft_arrdel((void ***)&player_name);
				player_name = ft_strsplit(*line, '/');
				n = 0;
				while (player_name[n])
					n++;
				player->p2 = ft_strdup(player_name[n - 1]);
				ft_arrdel((void ***)&player_name);
				return (0);
			}
		}
		if (**line == '$' && !player->ally)
		{
			if (ft_strinstr(*line, "p1"))
				record_player(player, TRUE);
			else
				record_player(player, FALSE);
		}
		if (**line == 'P' && ft_strinstr(*line, NAME_FIELD))
		{
			ft_printf("{neon}oh, you tried to load it with one player? wily you!{eoc}\n");
			ft_printf("{neon}something wrong with FILLER_VM, GG!{eoc}\n");
			break ;
		}
	}
	return (1);
}

char			*ft_namefield(int height, int width)
{
	char		*tmp;
	int			strlen;
	char		*num1;
	char		*num2;
	int			len1;
	int			len2;

	tmp = NULL;
	num1 = ft_itoa(height);
	num2 = ft_itoa(width);
	len1 = ft_strlen(num1);
	len2 = ft_strlen(num2);
	strlen = len1 + len2 + ft_strlen(FIELD) + 1 + 1;
	if (!(tmp = (char *)malloc(sizeof(char) * (strlen + 1))))
		return (NULL);
	tmp[strlen--] = '\0';
	while (--len1 >= 0)
	{
		tmp[strlen] = num1[len1];
		strlen--;
	}
	tmp[strlen--] = 'x';
	while (--len2 >= 0)
	{
		tmp[strlen] = num2[len2];
		strlen--;
	}
	tmp[strlen--] = ' ';
	while (strlen >= 0)
	{
		tmp[strlen] = FIELD[strlen];
		strlen--;
	}
	ft_memdel((void **)&num1);
	ft_memdel((void **)&num2);
	return (tmp);
}

void			ft_free_lst(t_f **lst)
{
	t_f			*cur_lst;

	while ((*lst)->next)
	{
		cur_lst = *lst;
		// for piece
		ft_arrdel((void ***)&cur_lst->p->piece);
		free(cur_lst->p);
		// for map
		ft_arrdel((void ***)&cur_lst->m->map);
		free(cur_lst->m);
		// for pos
		free(cur_lst->pos);
		*lst = (*lst)->next;
		free(cur_lst);
	}
	ft_arrdel((void ***)&(*lst)->p->piece);
	free((*lst)->p);
	ft_arrdel((void ***)&(*lst)->m->map);
	free((*lst)->m);
	free((*lst)->pos);
	free(*lst);
	lst = NULL;
	return ;
}

void			ft_free_player(t_player *player)
{
	ft_memdel((void **)&player->p1);
	ft_memdel((void **)&player->p2);
	ft_memdel((void **)&player->field);
	return ;
}

void			init_struct_player(t_player *player)
{
	player->p1 = NULL;
	player->p2 = NULL;
	player->field = NULL;
	player->ally = '\0';
	player->enemy = '\0';
	return ;
}

void			init_structs(t_f *curlst, t_p *p, t_m *m, t_pos *pos)
{
	p = new_t_piece();
	m = new_t_map();
	pos = new_t_pos();
	p->width = 0;
	p->height = 0;
	p->piece = NULL;
	m->width = 0;
	m->height = 0;
	m->map = NULL;
	pos->i = 0;
	pos->j = 0;
	pos->turn = '\0';
	curlst->ally_cnt = 0;
	curlst->enemy_cnt = 0;
	curlst->field_cnt = 0;
	curlst->m = m;
	curlst->p = p;
	curlst->pos = pos;
	return ;
}
