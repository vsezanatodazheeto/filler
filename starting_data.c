#include "filler.h"

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