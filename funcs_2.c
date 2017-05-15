/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:38:18 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/12 15:38:56 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_room(char *line)
{
	int	i;
	int	k;

	k = ft_strlen(line);
	i = 0;
	while (line[i] != ' ' && i < k)
		i++;
	i++;
	while (line[i] != ' ' && i < k)
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		i++;
	}
	i++;
	while (line[i] != ' ' && i < k)
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		i++;
	}
	if (i == k && line[i] != ' ')
		return (1);
	else
		return (0);
}

void	make_list_start(t_li **begin_list)
{
	t_li	*str;
	char	*l;
	size_t	i;

	i = 0;
	get_next_line(0, &l);
	write(1, l, ft_strlen(l));
	write(1, "\n", 1);
	str = *begin_list;
	if (check_room(l) == 0 || l[0] == 'L' || l[0] == '#')
		ft_exit(3);
	else if (str->type == 'S')
		ft_exit(4);
	else if (room_exists(*begin_list, l))
		ft_exit(5);
	while (str->next != NULL)
		str = str->next;
	while (l[i] != ' ')
		i++;
	str->name = ft_strsub(l, 0, i);
	str->type = 'S';
	str->next = add_list();
	ft_strdel(&l);
}

void	make_list_end(t_li **begin_list)
{
	t_li	*str;
	char	*line;
	size_t	i;

	i = 0;
	get_next_line(0, &line);
	write(1, line, ft_strlen(line));
	write(1, "\n", 1);
	str = *begin_list;
	if (check_room(line) == 0 || line[0] == 'L' || line[0] == '#')
		ft_exit(3);
	else if (str->type == 'E')
		ft_exit(4);
	else if (room_exists(*begin_list, line))
		ft_exit(5);
	while (str->next != NULL)
		str = str->next;
	while (line[i] != ' ')
		i++;
	str->name = ft_strsub(line, 0, i);
	str->type = 'E';
	str->next = add_list();
	ft_strdel(&line);
}

void	make_list_sp(t_li **begin_list, char *line)
{
	t_li	*str;
	size_t	i;

	i = 0;
	if (check_room(line) == 0 || line[0] == 'L')
		ft_exit(3);
	else if (room_exists(*begin_list, line))
		ft_exit(5);
	str = *begin_list;
	while (str->next != NULL)
		str = str->next;
	while (line[i] != ' ')
		i++;
	str->name = ft_strsub(line, 0, i);
	str->type = 'R';
	str->next = add_list();
}

void	ft_exit(int i)
{
	if (i == 1)
		write(2, RED "ERROR:"RESET" Wrong number of ants !\n", 39);
	if (i == 0)
		write(2, RED "ERROR:"RESET" Invalid input !\n", 32);
	if (i == 3)
		write(2, RED "ERROR:"RESET" Wrong room !\n", 29);
	if (i == 4)
		write(2, RED "ERROR:"RESET" This type of room exists !\n", 43);
	if (i == 5)
		write(2, RED "ERROR:"RESET" Room is already exists !\n", 42);
	if (i == 10)
		write(2, RED "ERROR:"RESET" No possible paths !\n", 37);
	if (i == 9)
		ft_putendl("Usage: ./lem-in < [path to ant-farm_file]");
	exit(0);
}
