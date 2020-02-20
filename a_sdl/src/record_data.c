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

void			record_got_pos(t_filler *filler, char **line)
{
	char	**tmp;

	if (ft_is_strstr(*line, "O"))
		filler->pos->turn = 'O';
	else
		filler->pos->turn = 'X';
	tmp = ft_strsplit(*line, ' ');
	filler->pos->i = ft_atoi(&(tmp[2][1]));
	filler->pos->j = ft_atoi(&(tmp[3][0]));
	// ft_printf("positions: [%d, %d]\n", filler->pos->i, filler->pos->j);
	ft_memdel((void **)tmp);
	return ;
}

void			record_piece_positions(t_filler *filler, char **line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < filler->piece->height && get_next_line(0, &(*line)))
	{
		j = 0;
		while (j < filler->piece->width)
		{
			if ((*line)[j] == '.')
				filler->piece->piece[i][j] = 0;
			if ((*line)[j] == '*')
				filler->piece->piece[i][j] = 1;
			j++;
		}
		i++;
	}
	return ;
}

void			record_piece(t_filler *filler, char **line)
{	
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(*line, ' ');
	filler->piece->height = ft_atoi(*(tmp + 1));
	filler->piece->width = ft_atoi(*(tmp + 2));
	ft_memdel((void **)tmp);
	if (!(filler->piece->piece = (int **)malloc(sizeof(int *) * filler->piece->height)))
		exit(1);
	while (j < filler->piece->height)
	{
		if (!(filler->piece->piece[j] = (int *)malloc(sizeof(int) * filler->piece->width)))
			exit(1);
		j++;
	}
	return ;
}

void			record_map_positions(t_filler *filler, char **line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (get_next_line(0, &(*line)))
	 		;
	while (i < filler->map->height && get_next_line(0, &(*line)))
	{
		j = 0;
		while (j < filler->map->width)
		{
			if ((*line + HGT)[j] == '.')
				filler->map->map[i][j] = 0;
			else if (ft_toupper((*line + HGT)[j]) == 'O' || ft_toupper((*line + HGT)[j]) == 'X')
			{
				if ((filler->ally == 'O' && ft_toupper((*line + HGT)[j]) == 'O') ||
											(filler->ally == 'X' && ft_toupper((*line + HGT)[j]) == 'X'))
					filler->map->map[i][j] = -1;
				else
					filler->map->map[i][j] = -2;
			}
			j++;
		}
		i++;
	}
	return ;
}

void			record_map(t_filler *filler, char **line)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(*line, ' ');
	filler->map->height = ft_atoi(*(tmp + 1));
	filler->map->width = ft_atoi(*(tmp + 2));
	ft_memdel((void **)tmp);
	if (!(filler->map->map = (int **)malloc(sizeof(int *) * filler->map->height)))
		exit(1);
	while (j < filler->map->height)
	{
		if (!(filler->map->map[j] = (int *)malloc(sizeof(int) * filler->map->width)))
			exit(1);
		j++;
	}
	return ;
}

void 			record_player(t_filler *filler, int i)
{
	if (i)
	{
		filler->ally = 'O';
		filler->enemy = 'X';
	}
	else
	{
		filler->ally = 'X';
		filler->enemy = 'O';
	}
}

void			check_player(t_filler *filler, t_player *players, char **line)
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
		if (**line == '$' && !filler->ally && i == 0)
		{
			if (ft_is_strstr(*line, NAME_ALLY) && ft_is_strstr(*line, "p1"))
				record_player(filler, TRUE);
			else
				record_player(filler, FALSE);
			i = 1;
		}
	}
	return;
}