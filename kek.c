#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_piece_of_shit
{
	int			**piece;
}				t_piece;

typedef struct	s_filler
{
	t_piece		*piece;
}				t_filler;

// int				get_next_line(const int fd, char **line);
void	kek(int ***arr)
{
	int i;

	i = 0;
	int		**k;

	k = *arr;
	while (**arr)
	{
		free(**arr);
		(*arr)++;
	}
	free(k);
	k = NULL;
	return ;
}
int 	main()
{
	t_filler f[1];
	t_piece  p[1];
	int i = 0;
	int j = 0;
	char *line;

	f->piece = p;
	f->piece->piece = (int **)malloc(sizeof(int *) * (2 + 1));
	f->piece->piece[0] = (int *)malloc(sizeof(int) * 5);
	// f->piece->piece[1] = (int *)malloc(sizeof(int) * 5);
	f->piece->piece[2] = NULL;
	// while (i < 2)
	// {
	// 	j = 0;
	// 	while (j < 5)
	// 	{
	// 		f->piece->piece[i][j] = 2;
	// 		j++;
	// 	}
	// 	i++;
	// }
	kek(&(f->piece->piece));
	return (0);
}