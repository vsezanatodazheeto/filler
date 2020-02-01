/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:15:47 by yshawn            #+#    #+#             */
/*   Updated: 2019/10/02 21:15:50 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_len_before_chr(const char *s, int c)
{
	int		i;
	int		n;
	char	chr;

	i = ft_strlen(s);
	n = 0;
	chr = c;
	while (n <= i)
	{
		if (s[n] == chr)
			return (n);
		n++;
	}
	return (-1);
}

static void		free_n_overlap(char **temp_str, char *buf, char *tmp, int chr)
{
	if (chr == -1)
	{
		tmp = ft_strjoin(*temp_str, buf);
		free(*temp_str);
		*temp_str = tmp;
	}
	else if (chr != -1)
	{
		tmp = ft_strdup(&((*temp_str)[chr + 1]));
		free(*temp_str);
		*temp_str = tmp;
	}
	return ;
}

static int		ft_rewrite(char **temp_str, char **line, char *buf, char *tmp)
{
	int		is_chr;

	if ((is_chr = ft_len_before_chr(*temp_str, '\n')) != -1)
	{
		*line = ft_strsub(*temp_str, 0, is_chr);
		free_n_overlap(&(*temp_str), &(*buf), &(*tmp), is_chr);
		if ((*temp_str)[0] == '\0')
			ft_memdel((void**)temp_str);
	}
	else
	{
		*line = ft_strdup(*temp_str);
		ft_memdel((void**)temp_str);
	}
	return (1);
}

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
