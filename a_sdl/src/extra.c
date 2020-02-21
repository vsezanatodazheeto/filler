/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:17:40 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/21 21:33:52 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

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
			ft_printf("pizdeeeeec\n");
			if (ft_strinstr(*line, "p1"))
				record_player(f, TRUE);
			else
				record_player(f, FALSE);
			i = 1;
		}
	}
	return;
}

// void		print_everything(t_f *f)
// {
// 	int 	i;
// 	int		j;
// 	int		x;
// 	int		xx;
// 	int		y;

// 	i = 0;
// 	j = 0;
// 	x = 0;
// 	xx = 0;
// 	y = 0;

// 	ft_printf("    ");
// 	while (x < f->m->width)
// 	{
// 		if (xx > 9)
// 			xx = 0;
// 		ft_printf("{orange}%d{eoc}", xx);
// 		x++;
// 		xx++;
// 	}
// 	ft_printf("\n");
// 	while (i < f->m->height)
// 	{
// 		j = 0;
// 		ft_printf("{orange}%3d{eoc} ", y);
// 		while (j < f->m->width)
// 		{
// 			if (f->m->m[i][j] == -1)
// 				ft_printf("{green}O");
// 			else if (f->m->m[i][j] == -2)
// 				ft_printf("{red}X");
// 			else
// 				ft_printf("{eoc}.");
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 		y++;
// 	}
// 		ft_printf("\n");
// 	return ;
// }

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

void		init_struct_player(t_player *player)
{
	player->p1 = NULL;
	player->p2 = NULL;
	return ;
}

void 		init_structs(t_f *curlst, t_p *p, t_m *m, t_pos *pos)
{
    m = new_t_map();
    pos = new_t_pos();
    p = new_t_piece();
	p->width = 0;
	p->height = 0;
	p->piece = NULL;
	m->width = 0;
	m->height = 0;
	m->map = NULL;
	pos->i = 0;
	pos->j = 0;
	pos->turn = '\0';
	curlst->ally = '\0';
	curlst->enemy = '\0';
	curlst->m = m;
	curlst->p = p;
	curlst->pos = pos;
}