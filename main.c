#include "filler.h"

/*
int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	static char		*temp_str[MAX_FD];

	tmp = "";
	if (fd == -1 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!temp_str[fd])
			temp_str[fd] = ft_strdup(buf);
		else
			free_n_overlap(&temp_str[fd], &(*buf), &(*tmp), -1);
	}
	if (ret < 0 || fd[temp_str] == NULL)
		return (ret < 0 ? -1 : 0);
	else
		return (ft_rewrite(&temp_str[fd], line, &(*buf), &(*tmp)));
}
*/
void    init_struct(t_position *pos)
{
    pos->ally = 0;
    pos->enemy = 0;
    pos->map = 0;
}
void    follow_position(t_position *pos, char *buf)
{
    int i;

    i = 0;
    while (buf[i])
    {
        if (buf[i] == 'O')
            pos->ally = i;
        if (buf[i] == 'X')
            pos->enemy = i;
        i++;
    }
    pos->map = i - 2;
    ft_printf("our pos: %d\nenemy pos: %d\nsize of map: %d\n", pos->ally, pos->enemy, pos->map);
    return ;
}
int     main()
{
    int op;
    ssize_t ret;
    char buf[BUF_SIZE];

    t_position pos[1];

    /* открываем, читаем всякую хуйню */
    op = open("resources/maps/map01", O_RDONLY);
    ret = read(op, buf, BUF_SIZE);
    while (ret < BUF_SIZE)
        buf[ret++] = '\0';
    ft_printf("%s", buf);

    /* находим местоположение */
    init_struct(pos);
    follow_position(pos, buf);
    return (0);
}