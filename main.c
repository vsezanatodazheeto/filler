#include "filler.h"

void		record_map_positions(t_filler *filler, char *line, int i)
{
	int		j;

	j = 0;
	while (j < filler->map->width)
	{
		if (line[j] == '.')
			filler->map->map[i][j] = 0;
		if (line[j] == 'O' || line[j] == 'X')
		{
			if ((filler->ally == 'O' && line[j] == 'O') || (filler->ally == 'X' && line[j] == 'X'))
				filler->map->map[i][j] = 1;
			else
				filler->map->map[i][j] = 2;
		}
		printf("%d", filler->map->map[i][j]);
		j++;
	}
	printf(" : %d\n", j);
	i++;
	return ;
}

void		record_map(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	line = line + ft_td(line);
	filler->map->height = ft_atoi(line);
	line = line + ft_fdtd(line);
	filler->map->width = ft_atoi(line);
	if (!(filler->map->map = (int **)malloc(sizeof(int *) * filler->map->height)))
		exit(1);
	while (i < filler->map->height)
	{
		if (!(filler->map->map[i] = (int *)malloc(sizeof(int) * filler->map->width)))
			exit(1);
		i++;
	}
	return ;
}

void		record_player(t_filler *filler, int i)
{
	if (i == 0)
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

void		check_starting_data(t_filler *filler, char **line)
{
	int		fd;
	int 	i;

	i = -1;
	/* ДЛЯ ПРОВЕРКИ */
    if ((fd = open("example", O_RDONLY)) < 0)
    {
        ft_printf("не смог открыть, еба!\n");
        exit(1);
    }

	while (get_next_line(fd, &(*line)))
	{
		if (**line == '$' && !filler->ally)
		{
			if (ft_is_strstr(*line, NAME_ALLY))
				record_player(filler, 0);
			else
				record_player(filler, 1);
		}
		if (**line == 'P' && !filler->map->map)
			if (ft_is_strstr(*line, NAME_FIELD))
				record_map(filler, *line);
		if (**line >= '0' && **line <= '9')
			if (++i < filler->map->height)
				record_map_positions(filler, *line + SKIP_HEIGHT, i);
		if (**line == 'P' && ft_is_strstr(*line, NAME_PIECE))
		{
			printf("ЗАЕБУМБА\n");
			break;
		}
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
	char 		*line;

	/* зачищаем всякую хуйню */
	line = NULL;
	init_structs(filler, map, piece);
	/* считываем карту, записываем данные */
	check_starting_data(filler, &line);
	printf("zarbumba: %s\n", line);
	return (0);
}