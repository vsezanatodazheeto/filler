#ifndef FILLER_H
# define FILLER_H

#include <sys/types.h> //for open
#include <sys/stat.h> //for open
#include <fcntl.h> //for open
#include <unistd.h> //for read
#include <stdio.h> // for fwrite
#include "gnl/libft/libft.h"

#define NAME_ALLY "abanlin.filler"
#define NAME_FIELD "Plateau"
#define NAME_PIECE "Piece"
#define BUF_SIZE 1000
#define SKIP_HEIGHT 4
#define TRUE 1
#define FALSE 0

typedef struct	s_map
{
	int			width;
	int			height;
	int			**map;
}				t_map;

typedef struct	s_piece_of_shit
{
	int			width;
	int			height;
	char		**piece;
}				t_piece;

typedef struct	s_filler
{
	char		ally;
	char		enemy;
	int			x;
	int			y;
	t_piece		*piece;
	t_map		*map;
}				t_filler;

/*
* вспомогательные функции из библиотеки
*/
int     		ft_printf(const char *str, ...);
int     		get_next_line(int fd, char **line);

/*
* основные функции filler'a
*/
void    		init_structs(t_filler *filler, t_map *map, t_piece *piece);
void    		check_starting_data(t_filler *filler, char **line);
void			record_player(t_filler *filler, int i);
void			record_map(t_filler *filler, char *line);
void			record_map_positions(t_filler *filler, char *line, int i);
int 			check_summ_data(t_filler *filler);

/*
* вспомогательные функции для filler'а
*/
int				ft_td(char *line);
int				ft_fdtd(char *line);
int				ft_is_strstr(char *str_dad, char *str_son);

#endif

// int				ft_strstr_symb(char *str_dad, char *str_son, char ch);
