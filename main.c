/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 07:54:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/18 23:26:53 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/filler.h"

int         count_summ(t_filler *filler, int x, int y)
{
    int count;
    int i;
    int j;
    int s;
    s = 0;
    count = 0;
    if (x + filler->piece->height > filler->map->height
        || y + filler->piece->width > filler->map->width)
        return (0);
    i = 0;
    while (i < filler->piece->height)
    {
        j = 0;
        while (j < filler->piece->width)
        {
            if (filler->map->map[x + i][y + j] == -2)
                return (0);
            if (filler->map->map[x + i][y + j] == -1 && filler->piece->piece[i][j] ==1)
                count++;
            if (count > 1)
                return (0);
            if (filler->map->map[x + i][y + j])
                s += filler->map->map[x + i][y + j];
            j++;
        }
        i++;
    }
    return (count == 1 ? s : 0);
}

void        find_best_pos(t_filler *filler)
{
    int i;
    int j;
    int s;
    int min;

    i = 0;
    s = 0;
    min = 10000;
    filler->pos->i = 0;
    filler->pos->j = 0;
    while (i < filler->map->height)
    {
        j = 0;
        while (j < filler->map->width)
        {
            if (filler->map->map[i][j] != -2)
            {
                s = count_summ(filler, i, j);
                if (s && s < min)
                {           
                    min = s;
                    filler->pos->i = i;
					// ft_printf("%d ", filler->pos->i);
                    filler->pos->j = j;
					// ft_printf("%d\n", filler->pos->j);
                }
            }
            j++;
        }
        i++;
    }
    return ;            
}

int         min_distance(t_filler *filler, int x, int y)
{
    int i;
    int j;
    int min;

    i = 0;
    min = ((filler->map->height * filler->map->width) - 2);
    while (i < filler->map->height)
    {
        j = 0;
        while (j < filler->map->width)
        {
            if (filler->map->map[i][j] == -2 && manhattan_formula(i, j, x, y) < min)
                min = manhattan_formula(i, j, x, y);
            j++;
        }
        i++;
    }
    return (min);           
}

void        fill_manhattan_distance(t_filler *filler)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < filler->map->height)
    {
        j = 0;
        while (j < filler->map->width)
        {
            if (filler->map->map[i][j] != -1 && filler->map->map[i][j] != -2)
                filler->map->map[i][j] = min_distance(filler, i, j);
            j++;
        }
        i++;
    }
    return ;
}

void        solving_filler(t_filler *filler, char **line)
{
	while (get_next_line(filler->fd, &(*line)))
	{
		if (**line == 'P' && ft_is_strstr(*line, NAME_FIELD))
		{
			if (!filler->map->map)
				if (record_map(filler, &(*line)) == 1)
					break ;
			record_map_positions(filler, &(*line));
			fill_manhattan_distance(filler);
		}
		else if (**line == 'P' && ft_is_strstr(*line, NAME_PIECE))
		{
			if (record_piece(filler, &(*line)) == 1)
				break ;
			record_piece_positions(filler, &(*line));
		 	find_best_pos(filler);
            // printf_map_fill(filler);
			// if (filler->pos->i == 0 && filler->pos->j == 0)
			// 	return ;
            // if (filler->pos->i != 0)
            //     (filler->pos->i)--;
			ft_printf("%d %d\n", filler->pos->i, filler->pos->j);
		}
	}
	return ;
}

int			check_starting_data(t_filler *filler, char **line)
{
	while (get_next_line(filler->fd, &(*line)))
	{
		if (**line == '$' && !filler->ally)
		{
			if (ft_is_strstr(*line, NAME_ALLY) && ft_is_strstr(*line, "p1"))
				record_player(filler, TRUE);
			else
				record_player(filler, FALSE);
			break ;
		}
	}
    return (filler->ally && filler->enemy ? 0: 1);
}

int			main(void)
{
	t_filler	filler[1];
	t_piece		piece[1];
	t_map		map[1];
	t_pos		pos[1];
	char 		*line;

	line = NULL;
    filler->fd = 0;
    // filler->fd = open("z_example", O_RDONLY);
	init_structs(filler, piece, map, pos);
	if (check_starting_data(filler, &line) == 1)
	{
		ft_strdel(&line);
		return (1);
	}
    solving_filler(filler, &line);
    free_data(filler, &line);
	// close(filler->fd);
	return (0);
}