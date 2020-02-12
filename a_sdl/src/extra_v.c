/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_v.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:17:40 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/12 07:21:13 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler_v.h"

void		printf_map(t_filler *filler)
{
	int 	i;
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
	while (x < filler->map->width)
	{
		if (xx > 9)
			xx = 0;
		ft_printf("%d", xx);
		x++;
		xx++;
	}
	ft_printf("\n");
	while (i < filler->map->height)
	{
		j = 0;
		ft_printf("%3d ", y);
		while (j < filler->map->width)
		{
			if (filler->map->map[i][j] == -1)
				ft_printf("{green}O");
			else if (filler->map->map[i][j] == -2)
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

void 		init_structs(t_filler *cur_lst, t_piece *piece, t_map *map, t_pos *pos)
{
	piece->width = 0;
	piece->height = 0;
	piece->piece = NULL;
	map->width = 0;
	map->height = 0;
	map->map = NULL;
	pos->i = 0;
	pos->j = 0;
	pos->turn = '\0';
	cur_lst->ally = '\0';
	cur_lst->enemy = '\0';
	cur_lst->piece = NULL;
	cur_lst->map = map;
	cur_lst->piece = piece;
	cur_lst->pos = pos;
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