#include "../include/filler.h"

void		printf_map_fill(t_filler *filler)
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

	ft_printf("\n\n");
	ft_printf("    ");
	while (x < filler->map->width)
	{
		if (xx > 9)
			xx = 0;
		ft_printf("{yellow}%3d{eoc}", xx);
		x++;
		xx++;
	}
	ft_printf("\n");
	while (i < filler->map->height)
	{
		j = 0;
		ft_printf("{yellow}% 3d{eoc} ", y);
		while (j < filler->map->width)
		{
			if (filler->map->map[i][j] == -1)
				ft_printf("{green}%3d", filler->map->map[i][j]);
			else if (filler->map->map[i][j] == -2)
				ft_printf("{red}%3d", filler->map->map[i][j]);
			else
				ft_printf("{eoc}%3d", filler->map->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
		y++;
	}
		ft_printf("\n");
	return ;
}

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

void		free_data(t_filler *filler, char **line)
{
	if (filler->map->map)
		ft_arrdel((void ***)&filler->map->map);
	if (filler->piece->piece)
		ft_arrdel((void ***)&filler->piece->piece);
	if (*line)
		free(*line);
	return ;
}

void 		init_structs(t_filler *filler, t_piece *piece, t_map *map, t_pos *pos)
{
	filler->ally = '\0';
	filler->enemy = '\0';
	filler->piece = NULL;
	filler->map = NULL;
	filler->pos = NULL;
	piece->width = 0;
	piece->height = 0;
	piece->piece = NULL;
	map->width = 0;
	map->height = 0;
	map->map = NULL;
	pos->i = 0;
	pos->j = 0;
	pos->x = 0;
	pos->y = 0;
	filler->map = map;
	filler->piece = piece;
	filler->pos = pos;
}

int			manhattan_formula(int x, int y, int i, int j)
{
	int a;
	int b;

	if (i > x)
		a = i - x;
	else
		a = x - i;
	if (j > y)
		b = j - y;
	else
		b = y - j;
	return (a + b);
}

void		ft_arrdel(void ***arr)
{
	void	**first;

	first = *arr;
	while (**arr)
	{
		free(**arr);
		(*arr)++;
	}
	free(first);
	first = NULL;
	return ;
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