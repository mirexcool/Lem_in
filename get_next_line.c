/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:07:20 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/11 19:08:43 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*add_list(int fd)
{
	t_gnl	*list;

	list = (t_gnl *)malloc(sizeof(t_gnl));
	list->fd = fd;
	list->buff = ft_strnew(0);
	list->next = NULL;
	return (list);
}

static	int		make_line(char **line)
{
	*line = *line;
	return (1);
}

static int		read_line(int fd, char **line)
{
	char	*rd;
	char	*ptr;

	rd = ft_strnew(sizeof(char) * BUFF_SIZE);
	while (read(fd, rd, BUFF_SIZE) > 0)
	{
		ptr = *line;
		if (ft_strchr(rd, '\n'))
		{
			free(rd);
			return (make_line(line));
		}
		*line = ft_strjoin(*line, rd);
		free(ptr);
		ft_bzero(rd, sizeof(char) * BUFF_SIZE);
	}
	free(rd);
	return (ft_strlen(*line));
}

static int		get_line(char **buf, char **line, int fd)
{
	int		i;

	i = 0;
	*line = ft_strnew(0);
	if (ft_strlen(*buf) > 0)
	{
		if (ft_strchr(*buf, '\n'))
		{
			while (*(*buf)++ != '\n')
				i++;
			free(*line);
			*line = ft_strnew(i);
			ft_memmove(*line, (*(buf++)) - i - 1, i);
			return (1);
		}
		else
		{
			free(*line);
			*line = ft_strdup(*buf);
			while (*(*buf)++ != '\0')
				i++;
			return (read_line(fd, line));
		}
	}
	return (read_line(fd, line));
}

int				get_next_line(int fd, char **line)
{
	static	t_gnl	*list;
	t_gnl			*begin_list;

	if (fd < 0 || !line || BUFF_SIZE < 1 || BUFF_SIZE > 65534
			|| read(fd, NULL, 0) == -1)
		return (-1);
	if (!list)
		list = add_list(fd);
	begin_list = list;
	while (begin_list != NULL)
	{
		if (begin_list->fd == fd)
			break ;
		if (begin_list->next == NULL)
			begin_list->next = add_list(fd);
		begin_list = begin_list->next;
	}
	if (get_line(&(begin_list->buff), line, fd))
		return (1);
	return (0);
}
