/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:02:43 by rretta            #+#    #+#             */
/*   Updated: 2020/01/10 16:30:54 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		sfd_manage_next_line(char **sfd, char **line)
{
	unsigned int	len;
	char			*temp;

	len = 0;
	while ((*sfd)[len] != '\n' && (*sfd)[len])
		len++;
	if ((*sfd)[len] == '\n')
	{
		*line = ft_strsub(*sfd, 0, len);
		temp = ft_strdup(*sfd + len + 1);
		free(*sfd);
		*sfd = temp;
		if ((*sfd)[0] == '\0')
			ft_strdel(sfd);
	}
	else
	{
		*line = ft_strdup(*sfd);
		ft_strdel(sfd);
	}
	return (1);
}

static int		ft_er(int res, char **sfd)
{
	if (res < 0)
		return (-1);
	else if (*sfd == NULL)
		return (0);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*sfd[FD];
	char			strg[BUFF_SIZE + 1];
	char			*temp;
	int				res;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((res = read(fd, strg, BUFF_SIZE)) > 0)
	{
		strg[res] = '\0';
		if (sfd[fd] == NULL)
			sfd[fd] = ft_strdup(strg);
		else
		{
			temp = ft_strjoin(sfd[fd], strg);
			free(sfd[fd]);
			sfd[fd] = temp;
		}
		if (ft_strchr(sfd[fd], '\n') != NULL)
			break ;
	}
	if (res < 0 || sfd[fd] == NULL)
		return (ft_er(res, &sfd[fd]));
	return (sfd_manage_next_line(&sfd[fd], line));
}
