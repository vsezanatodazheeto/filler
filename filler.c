#include "filler.h"

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

int			ft_tolow(int ch)
{
	return ((ch >= 'A' && ch <= 'Z') ? (ch - 'A' + 'a') : (ch));
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

int    		ft_td(char *line)
{
    int		i;

    i = 0;
    while ((line[i] < '0' || line[i] > '9') && line[i])
        i++;
    return (line[i] >= '0' && line[i] <= '9' ? i : FALSE);
}

int     	ft_fd(char *line)
{   
    int 	i;

    i = 0;
    while (line[i] >= '0' && line[i] <= '9' && line[i])
        i++;
    return ((line[i] >= '0' && line[i] <= '9') ? FALSE : i);
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