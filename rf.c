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
void    kek(char **line)
{
    *line = "pizda";
    cheburek(&(*line));
    return ;
}

int     main(int ac, char **av)
{
    char *line;
    int fd;
    FILE *myfile;

    line = "hahahha, classic";
    printf("%s\n", line);
    kek(&line);
    printf("%s\n", line);
    /* ДЛЯ ПРОВЕРКИ */
    // if (ac != 3)
        // printf("пошел нахуй\n");
    /*
    fd = open(av[1], O_RDONLY);
    myfile = fopen("TRACE.TXT", "a");
    while (get_next_line(fd, &line))
        fprintf(myfile, "%s\n", line);
    fclose(myfile);
    close(fd);
    */
    return (0);
}