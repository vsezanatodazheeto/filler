#include "filler.h"

void		record_piece_positions(t_filler *filler, char **line, int fd)
{
	return ;
}

void		record_piece(t_filler *filler, char **line)
{	
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(*line, ' ');
	filler->piece->height = ft_atoi(*(tmp + 1));
	filler->piece->width = ft_atoi(*(tmp + 2));
	// printf("%d\n", filler->piece->height);
	// printf("%d\n", filler->piece->width);
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

int         min_distance(t_filler *filler, int x, int y)
{
    int i;
    int j;
    int min;
    i = x;
    min = manhattan_formula(filler->pos->x, filler->pos->y, x, y);
    while (i < filler->map->height)
    {
        j = y;
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
            printf("%3d", filler->map->map[i][j]);
            j++;
        }
        printf("\n");
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
	if (!(get_next_line(fd, &(*line))))
			exit(1);
	while (i < filler->map->height)
	{
		if (!(get_next_line(fd, &(*line))))
			exit(1);
		j = 0;
		while (j < filler->map->width)
		{
			if ((*line + HGT)[j] == '.')
				filler->map->map[i][j] = 0;
			if ((*line + HGT)[j] == 'O' || (*line + HGT)[j] == 'X')
			{
				if ((filler->ally == 'O' && (*line + HGT)[j] == 'O') ||
											(filler->ally == 'X' && (*line + HGT)[j] == 'X'))
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

void		record_map(t_filler *filler, char **line, int fd)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(*line, ' ');
	filler->map->height = ft_atoi(*(tmp + 1));
	filler->map->width = ft_atoi(*(tmp + 2));
	if (!(filler->map->map = (int **)malloc(sizeof(int *) * filler->map->height)))
		exit(1);
	while (j < filler->map->height)
	{
		if (!(filler->map->map[j] = (int *)malloc(sizeof(int) * filler->map->width)))
			exit(1);
		j++;
	}
	// printf("width: %d\n", filler->map->width);
	// printf("height: %d\n", filler->map->height);
	return ;
}

void		record_player(t_filler *filler, int i)
{
	if (i == 1)
	{
		filler->ally = 'O';
		filler->enemy = 'X';
	}
	else
	{
		filler->ally = 'X';
		filler->enemy = 'O';
	}
	// printf("%c\n", filler->ally);
	// printf("%c\n", filler->enemy);
}

void		check_starting_data(t_filler *filler, char **line)
{
	int		fd;

	fd = 0;
	/* ДЛЯ ПРОВЕРКИ */
    if ((fd = open("example", O_RDONLY)) < 0)
    {
        ft_printf("не смог открыть, еба!\n");
        exit(1);
    }

	while (TRUE)
	{
		if (!(get_next_line(fd, &(*line))))
			exit(1);
		if (**line == '$' && !filler->ally)
		{
			if (ft_is_strstr(*line, NAME_ALLY))
				record_player(filler, TRUE);
			else
				record_player(filler, FALSE);
		}
		if (**line == 'P' && ft_is_strstr(*line, NAME_FIELD))
		{
			record_map(filler, &(*line), fd);
			record_map_positions(filler, &(*line), fd);
			break;
		}
	}

	/* ЭТО ДОЛЖНО БЫТЬ В ОТДЕЛЬНОЙ ФУНКЦИИ */
	while (TRUE)
	{
		if (!(get_next_line(fd, &(*line))))
			exit(1);
		if (**line == 'P' && ft_is_strstr(*line, NAME_PIECE))
			record_piece(filler, &(*line));
		fill_manhattan_distance(filler);
		break ;
	}
	

	/* ДЛЯ ПРОВЕРКИ */
	close(fd);
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
	// printf("zaebumba: %s\n", line);
	return (0);
}