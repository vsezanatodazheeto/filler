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
    int min;
    int s;
    min = 10000;
    s = 0;
    i = 0;
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

void		record_piece_positions(t_filler *filler, char **line, int fd)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < filler->piece->height)
	{
		if (!(get_next_line(fd, &(*line))))
			exit(1);
		j = 0;
		while (j < filler->piece->width)
		{
			if ((*line)[j] == '.')
				filler->piece->piece[i][j] = 0;
			if ((*line)[j] == '*')
				filler->piece->piece[i][j] = 1;
			// printf("%d", filler->piece->piece[i][j]);
			j++;
		}
		// printf(" : %d\n", j);
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
    min = manhattan_formula(filler->pos->x, filler->pos->y, x, y);
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
            // printf("%3d", filler->map->map[i][j]);
            j++;
        }
        // printf("\n");
        i++;
    }
    return ;
}

void		record_map_positions(t_filler *filler, char **line, int fd)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < filler->map->height)
	{
		if (!(get_next_line(fd, &(*line))))
			exit(1);
		j = 0;
		while (j < filler->map->width)
		{
			if ((*line + HGT)[j] == '.')
				filler->map->map[i][j] = 0;
			else if (ft_toupper((*line + HGT)[j]) == 'O' || ft_toupper((*line + HGT)[j]) == 'X')
			{
				if ((filler->ally == 'O' && ft_toupper((*line + HGT)[j]) == 'O') ||
											(filler->ally == 'X' && ft_toupper((*line + HGT)[j]) == 'X'))
				{
					filler->map->map[i][j] = -1;
					filler->pos->i = i;
					filler->pos->j = j;
				}
				else
				{
					filler->map->map[i][j] = -2;
					filler->pos->x = i;
					filler->pos->y = j;
				}
			}
			// printf("%3d", filler->map->map[i][j]);
			j++;
		}
		// printf(" : %d\n", j);
		i++;
	}
	return ;
}

void		check_starting_data(t_filler *filler, char **line)
{
	int		fd;

	fd = 0;
	/* ДЛЯ ПРОВЕРКИ */
	// if ((fd = open("example", O_RDONLY)) < 0)
	// {
	// 	ft_printf("не смог открыть, еба!\n");
	// 	exit(1);
	// }

	while (get_next_line(fd, &(*line)))
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
	while (TRUE)
	{
		if (!(get_next_line(fd, &(*line))))
			return ;
		if (**line == 'P' && ft_is_strstr(*line, NAME_FIELD))
		{
			if (!filler->map->map)
				record_map(filler, &(*line));
			record_map_positions(filler, &(*line), fd);
			fill_manhattan_distance(filler);
			// printf_map(filler);
			// printf_map_fill(filler);
		}
		else if (**line == 'P' && ft_is_strstr(*line, NAME_PIECE))
		{
			record_piece(filler, &(*line));
			record_piece_positions(filler, &(*line), fd);
		 	find_best_pos(filler);
			if (filler->pos->i == 0 && filler->pos->j == 0)
				return ;
			ft_printf("%d %d\n", filler->pos->i, filler->pos->j);
		}
	}

	/* ДЛЯ ПРОВЕРКИ */
	// close(fd);
	return ;
}

int			main()
{
	t_filler	filler[1];
	t_piece		piece[1];
	t_map		map[1];
	t_pos		pos[1];
	char 		*line;

	/* зачищаем всякую хуйню */
	line = NULL;
	init_structs(filler, piece, map, pos);
	/* считываем карту, записываем данные */
	check_starting_data(filler, &line);
	ft_printf("{orange}%s{eoc}\n", "дошли до конца или съебались");
	if (filler->map->map)
		ft_memdel((void **)&filler->map->map);
	if (filler->piece->piece)
		ft_memdel((void **)&filler->piece->piece);
	if (line)
	{
		ft_memdel((void **)&line);
		// ft_strdel(&line);
	}
	return (0);
}