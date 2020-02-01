#ifndef FILLER_H
# define FILLER_H

#include <sys/types.h> //for open
#include <sys/stat.h> //for open
#include <fcntl.h> //for open
#include <unistd.h> //for read
#include <stdio.h> // for fwrite

#include "gnl/libft/libft.h"

#define BUF_SIZE 1000
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

/* вспомогательные функции из библиотеки */
int     ft_printf(const char *str, ...);
int     get_next_line(int fd, char **line);

void    init_struct(t_filler *filler);
void    check_size_map(t_filler *filler, char *line);

int    	to_digit(char *line);
int    	from_digit(char *line);



#endif
