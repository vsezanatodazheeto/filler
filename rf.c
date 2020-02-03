#include <sys/types.h> //for open
#include <sys/stat.h> //for open
#include <fcntl.h> //for open
#include <unistd.h> //for read
#include <stdio.h> // for fwrite

// #include "gnl/libft/libft.h"
// int     get_next_line(int fd, char **line);

void    cheburek(char **line)
{
    *line = "ahuet, cto proishodit";
    return ;
}
void    kek(char **line, char **gig)
{
    *line = "pizda";
    *gig++;
    *gig++;
    *gig++;
    cheburek(&(*line));
    return ;
}

int     main(int ac, char **av)
{
    char *line;
    char *gig;
    int fd;
    FILE *myfile;

    gig = "zaebumba";
    line = "hahahha, classic";
    printf("%s\n", line);
    printf("%s\n", gig);
    kek(&line, &gig);
    printf("%s\n", line);
    printf("%s\n", gig);
    return (0);
}