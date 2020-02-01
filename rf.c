#include <sys/types.h> //for open
#include <sys/stat.h> //for open
#include <fcntl.h> //for open
#include <unistd.h> //for read
#include <stdio.h> // for fwrite

// #include "gnl/libft/libft.h"
// int     get_next_line(int fd, char **line);

void    kek(char *line)
{
    line++;
    printf("%s\n", line);
    return ;
}

int     main(int ac, char **av)
{
    char *line;
    int fd;
    FILE *myfile;

    line = "vot eto da";
    kek(&(*line));
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