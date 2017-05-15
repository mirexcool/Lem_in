/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:57:38 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/12 13:58:31 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_room(char *str, int n, char t)
{
	if (n == 0)
		write(1, CYAN "\n-------------------\n"
				"BEST POSSIBLE WAYS:\n"
				"-------------------\n\n", 67);
	write(1, str, ft_strlen(str));
	if (t != 'E')
		write(1, " -> ", 4);
	else
		write(1, "\n", 1);
}

void	print_ways_l(t_ways *begin_list, t_li *room, int *i, t_ways *list)
{
	t_li	*rooms;

	rooms = room;
	list = begin_list;
	while (list)
	{
		i[0] = 0;
		while (i[0] < list->i)
		{
			while (rooms)
			{
				if (rooms->number == list->n[i[0]])
				{
					print_room(rooms->name, i[1]++, rooms->type);
					break ;
				}
				rooms = rooms->next;
			}
			i[0]++;
			rooms = room;
		}
		list = list->next;
	}
	write(1, "\n-------------------\n\n" RESET, 27);
}

void	get_ways(t_li *begin_list, size_t k, size_t i, int *m)
{
	t_ways	*ways;
	t_li	*list;

	while (i < k)
		m[i++] = -1;
	ways = add_way(m, 0);
	list = begin_list;
	while (list->next != NULL)
	{
		if (list->type == 'S')
			make_ways(list, m, 0, &ways);
		list = list->next;
	}
	if (ways == NULL || ways->next == NULL)
		ft_exit(10);
	if (way_len(ways->next) < begin_list->ants)
		sort_same_len(ways->next, 0, 0);
	sort_and_clean_ways(ways->next);
	way_filter(ways->next, k);
	ft_bzero(m, 8);
	if (begin_list->flag_p == 'P')
		print_ways_l(ways->next, begin_list, m, NULL);
	move_ants(ways->next, begin_list, 0, 0);
	free_all(begin_list, ways, NULL);
	free(m);
}
