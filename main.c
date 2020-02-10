#include "filler.h"

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
                    filler->pos->j = j;
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
	while (get_next_line(0, &(*line)))
	{
		if (**line == 'P' && ft_is_strstr(*line, NAME_FIELD))
		{
			if (!filler->map->map)
				record_map(filler, &(*line));
			record_map_positions(filler, &(*line));
			fill_manhattan_distance(filler);
		}
		else if (**line == 'P' && ft_is_strstr(*line, NAME_PIECE))
		{
			record_piece(filler, &(*line));
			record_piece_positions(filler, &(*line));
		 	find_best_pos(filler);
            // printf_map_fill(filler);
			if (filler->pos->i == 0 && filler->pos->j == 0)
				return ;
			ft_printf("%d %d\n", filler->pos->i - 1, filler->pos->j);
		}
	}
	return ;
}

void		check_starting_data(t_filler *filler, char **line)
{
	while (get_next_line(0, &(*line)))
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
    return ;
}

int			main(void)
{
	t_filler	filler[1];
	t_piece		piece[1];
	t_map		map[1];
	t_pos		pos[1];
	char 		*line;

	line = NULL;
	init_structs(filler, piece, map, pos);
	check_starting_data(filler, &line);
    solving_filler(filler, &line);
    // free_data(filler, &line);
	return (0);
}