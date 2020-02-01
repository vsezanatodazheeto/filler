#include "filler.h"

int     to_digit(char *line)
{
    int i;

    i = 0;
    while ((line[i] < '0' || line[i] > '9') && line[i])
        i++;
    return (line[i] > '0' && line[i] < '9' ? i : 0);
}

int     from_digit(char *line)
{   
    int i;

    i = 0;
    while (line[i] > '0' && line[i] < '9' && line[i])
        i++;
    return ((line[i] < '0' || line[i] > '9') ? i : 0);
}