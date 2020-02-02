#include "filler.h"

void 		init_structs(t_filler *filler, t_map *map, t_piece *piece)
{
	filler->ally = 0;
	filler->enemy = 0;
	filler->x = 0;
	filler->y = 0;
	filler->piece = NULL;
	filler->map = NULL;
	piece->width = 0;
	piece->height = 0;
	piece->piece = NULL;
	map->width = 0;
	map->height = 0;
	map->map = NULL;
	filler->map = map;
	filler->piece = piece;
}

int    		ft_td(char *line)
{
    int		i;

    i = 0;
    while ((line[i] < '0' || line[i] > '9') && line[i])
        i++;
    return (line[i] > '0' && line[i] < '9' ? i : FALSE);
}

int     	ft_fdtd(char *line)
{   
    int 	i;

    i = 0;
    while (line[i] > '0' && line[i] < '9' && line[i])
        i++;
    return ((line[i] < '0' || line[i] > '9') ? i : FALSE);
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

/*
int			ft_strstr_symb(char *str_dad, char *str_son, char ch)
{
	size_t	i;

	i = 0;
	while (*str_dad && *str_son && *str_dad != ch)
	{
		if (*str_dad != *str_son)
			return (0);
		str_dad++;
		str_son++;
		i++;
	}
	return ((*str_dad == ch && !*str_son) ? i : 0);
}
*/