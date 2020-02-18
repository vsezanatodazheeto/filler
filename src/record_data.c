/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 07:53:09 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/18 23:27:21 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		record_piece_positions(t_filler *filler, char **line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < filler->piece->height && get_next_line(filler->fd, &(*line)))
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

int			record_piece(t_filler *filler, char **line)
{	
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(*line, ' ');
	filler->piece->height = ft_atoi(*(tmp + 1));
	filler->piece->width = ft_atoi(*(tmp + 2));
	ft_arrdel((void ***)&tmp);
	if (filler->piece->piece)
		ft_arrdel((void ***)&filler->piece->piece);
	if (!(filler->piece->piece = (int **)malloc(sizeof(int *) * (filler->piece->height + 1))))
		return (1);
	else
		filler->piece->piece[filler->piece->height] = NULL;
	while (j < filler->piece->height)
	{
		if (!(filler->piece->piece[j] = (int *)malloc(sizeof(int) * filler->piece->width)))
		{
			filler->piece->piece[j] = NULL;
			ft_arrdel((void ***)&filler->piece->piece);
			return (1);
		}
		j++;
	}
	return (0);
}

void		record_map_positions(t_filler *filler, char **line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	// exit(1);
	if (get_next_line(0, &(*line)))
	 		;
	while (i < filler->map->height && get_next_line(filler->fd, &(*line)))
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

int			record_map(t_filler *filler, char **line)
{
	int		j;
	char	**tmp;

	j = 0;
	int i = 0;
	tmp = ft_strsplit(*line, ' ');
	filler->map->height = ft_atoi(*(tmp + 1));
	filler->map->width = ft_atoi(*(tmp + 2));
	ft_arrdel((void ***)&tmp);
	if (!(filler->map->map = (int **)malloc(sizeof(int *) * (filler->map->height + 1))))
		return (1);
	else
		filler->map->map[filler->map->height] = NULL;
	while (j < filler->map->height)
	{
		if (!(filler->map->map[j] = (int *)malloc(sizeof(int) * filler->map->width)))
		{
			filler->map->map[j] = NULL;
			ft_arrdel((void ***)&filler->map->map);
			return (1);
		}
		j++;
	}
	return (0);
}

void		record_player(t_filler *filler, int i)
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
