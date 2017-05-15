/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:37:32 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/12 15:37:54 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	make_link_1(t_li *r1, t_li *r2, t_li **begin_list)
{
	t_link	*link;
	t_li	*list;

	list = *begin_list;
	while (list->next)
	{
		if (ft_strcmp(r1->name, list->name) == 0)
		{
			link = list->link;
			if (link == NULL)
			{
				link = add_link(r2);
				list->link = link;
			}
			else
			{
				link = list->link;
				while (link->next)
					link = link->next;
				link->next = add_link(r2);
			}
		}
		list = list->next;
	}
}

void	make_link_2(t_li *r1, t_li *r2, t_li **begin_list)
{
	t_link	*link;
	t_li	*list;

	list = *begin_list;
	while (list->next)
	{
		if (ft_strcmp(r2->name, list->name) == 0)
		{
			link = list->link;
			if (link == NULL)
			{
				link = add_link(r1);
				list->link = link;
			}
			else
			{
				link = list->link;
				while (link->next)
					link = link->next;
				link->next = add_link(r1);
			}
		}
		list = list->next;
	}
}

void	make_list(t_li **begin_list, char *line)
{
	t_li	*room2;
	t_li	*room1;
	t_li	*list;
	char	*room[2];

	list = *begin_list;
	room1 = NULL;
	room2 = NULL;
	make_num(begin_list);
	room[0] = get_room_1(line, *begin_list);
	if (room[0] == NULL)
		ft_exit(0);
	room[1] = get_room_2(line, *begin_list, room[0]);
	while (list->next)
	{
		if (ft_strcmp(room[0], list->name) == 0)
			room1 = list;
		if (ft_strcmp(room[1], list->name) == 0)
			room2 = list;
		list = list->next;
	}
	make_link_1(room1, room2, begin_list);
	make_link_2(room1, room2, begin_list);
}

void	reading(char *line, t_li *begin_list)
{
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) > 0)
			ft_putendl(line);
		if (is_ants(line))
			begin_list->ants = ft_atoi(line);
		else if (ft_strcmp(line, "##start") == 0)
			make_list_start(&begin_list);
		else if (ft_strcmp(line, "##end") == 0)
			make_list_end(&begin_list);
		else if (ft_strchr(line, ' ') && !ft_strstr(line, "#"))
			make_list_sp(&begin_list, line);
		else if (ft_strchr(line, '-') && !ft_strstr(line, "#"))
			make_list(&begin_list, line);
		else if (!ft_strstr(line, "#"))
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

int		main(int argc, char **argv)
{
	t_li	*b;

	b = add_list();
	reading(NULL, b);
	if (argc > 1)
		get_flags(argv, b);
	if (b->type == '0')
		ft_exit(9);
	write(1, "\n", 1);
	get_ways(b, list_len(b), 0, (int *)malloc(sizeof(int ) * list_len(b)));
	return (0);
}
