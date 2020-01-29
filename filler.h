#ifndef FILLER_H
# define FILLER_H

#include <sys/types.h> //for open
#include <sys/stat.h> //for open
#include <fcntl.h> //for open
#include <unistd.h> //for read

#define BUF_SIZE 1000
typedef struct		s_position
{
	int				ally;
    int             enemy;
    int             map;
}					t_position;

int     ft_printf(const char *str, ...);
void    follow_position(t_position *pos, char *buf);



#endif
