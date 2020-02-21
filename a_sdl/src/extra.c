/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:17:40 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/20 18:21:38 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

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

int			ft_is_strstr(char *str_dad, char *str_son)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!*str_dad || !*str_son)
		return (FALSE);
	while (str_dad[i] && n == 0)
	{
		n = 0;
		if (str_dad[i] == str_son[n])
		{
			while (str_son[n] && str_dad[i])
			{
				if (str_son[n] != str_dad[i])
				{
					n = 0;
					break;
				}
				i++;
				n++;
			}
		}
		i++;
	}
	return ( n == 0 ? FALSE : i);
}