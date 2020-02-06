#ifndef FILLER_H
# define FILLER_H

#include <sys/types.h> //for open
#include <sys/stat.h> //for open
#include <fcntl.h> //for open
#include <unistd.h> //for read
#include <stdio.h> // for fwrite
#include "gnl/libft/libft.h"

#define NAME_ALLY "a.out"
#define NAME_FIELD "Plateau"
#define NAME_PIECE "Piece"
#define BUF_SIZE 1000
#define HGT 4
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
	int			**piece;
}				t_piece;

typedef struct	s_position
{
	int			i;
	int			j;
	int			x;
	int			y;
}				t_pos;

typedef struct	s_filler
{
	char		ally;
	char		enemy;
	t_piece		*piece;
	t_map		*map;
	t_pos		*pos;
}				t_filler;

/*
* вспомогательные функции из библиотеки
*/
int				ft_tolow(int ch);
int     		ft_printf(const char *str, ...);
int     		get_next_line(int fd, char **line);
char			**ft_strsplit(char const *str, char ch);

/*
* основные функции filler'a
*/
void    		init_structs(t_filler *filler, t_piece *piece, t_map *map, t_pos *pos);
void    		check_starting_data(t_filler *filler, char **line);
void			record_player(t_filler *filler, int i);
void			record_map(t_filler *filler, char **line);
void			record_map_positions(t_filler *filler, char **line, int fd);
void			record_piece(t_filler *filler, char **line);
void			record_piece_positions(t_filler *filler, char **line, int fd);
void			fill_manhattan_distance(t_filler *filler);

/*
* вспомогательные функции для filler'а
*/
int				ft_is_strstr(char *str_dad, char *str_son);
int				manhattan_formula(int x, int y, int i, int j);
void			printf_map(t_filler *filler); //delete me
void			printf_map_fill(t_filler *filler); // delete me

#endif

// int				ft_td(char *line);
// int				ft_fd(char *line);
// нужно зафришить после ft_strsplit, после создания тетраминки в record_piece и после record_map при выходе
// с программы