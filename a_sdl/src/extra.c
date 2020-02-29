/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:17:40 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/29 12:43:12 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

void			check_player(t_player *player, char **line)
{
	char		**player_name;
	int			i;

	i = 0;
	player_name = NULL;
	while (get_next_line(0, &(*line)))
	{
		if (**line == 'l')
		{
			if (!player_name)
			{
				player_name = ft_strsplit(*line, '/');
				player->p1 = ft_strdup(player_name[1]);
				ft_arrdel((void ***)&player_name);
			}
			else
			{
				player_name = ft_strsplit(*line, '/');
				player->p2 = ft_strdup(player_name[1]);
				ft_arrdel((void ***)&player_name);
				break ;
			}
		}
		if (**line == '$' && !player->ally && i != 1)
		{
			if (ft_strinstr(*line, "p1"))
				record_player(player, TRUE);
			else
				record_player(player, FALSE);
			i = 1;
		}
	}
	return;
}

char 		*ft_namefield(int height, int width)
{
	char	*tmp;
	int		strlen;
	char	*num1;
	char	*num2;
	int		len1;
	int		len2;

	tmp = NULL;
	num1 = ft_itoa(height);
	num2 = ft_itoa(width);
	len1 = ft_strlen(num1);
	len2 = ft_strlen(num2);
	strlen = len1 + len2 + ft_strlen(FIELD) + 1 + 1;

	if(!(tmp = (char *)malloc(sizeof(char) * (strlen))))
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
	ft_strdel(&num1);
	ft_strdel(&num2);
	return (tmp);
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

void		init_struct_player(t_player *player)
{
	player->p1 = NULL;
	player->p2 = NULL;
	player->field = NULL;
	player->ally = '\0';
	player->enemy = '\0';
	return ;
}

void 		init_structs(t_f *curlst, t_p *p, t_m *m, t_pos *pos)
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