#include "filler.h"

void    check_size_map(t_filler *filler, char *line)
{
    int i;
    t_map map[1];

    i = 0;
    while (*line)
    {
        if ((i = to_digit(line)))
        {
            line = line + i;
            map->height = ft_atoi(line);
        }
        if ((i = from_digit(line)))
        {
            line = line + i;
            map->width = ft_atoi(line);
            break;
        }
        else
            exit(1);
    }
    if (!(map->map = (int**)malloc(sizeof(int*) * map->height)))
        exit(1);
    i = 0;
	while (i < map->height)
	{
		map->map[i] = (int*)malloc(sizeof(int) * map->width);
		i++;
	}
    filler->map = map;
    return ;
}

void read_output(t_filler *filler)
{
    char *line;
    int fd;

    if ((fd = open("example", O_RDONLY)) < 0) // ДЛЯ ПРОВЕРКИ
    {
        ft_printf("не смог открыть, еба!\n");
        exit(1);
    }
    while (get_next_line(fd, &line) && *line != 'P')
        ;
    /* здесь должна быть проверка на PLATEAU */
    close(fd); // ДЛЯ ПРОВЕРКИ
    check_size_map(filler, line);
    return ;
}

void init_struct(t_filler *filler)
{
    filler->ally = 0;
    filler->enemy = 0;
    filler->piece = NULL;
    filler->map = NULL;
}

int     main()
{
    t_filler filler[1];
    t_piece piece[1];

    /* зачищаем всякую хуйню */
    init_struct(filler);
    /* считываем карту */
    read_output(filler);
    return (0);
}