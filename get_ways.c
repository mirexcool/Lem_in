/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:52:32 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/11 18:57:35 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_ways_l(t_ways *begin_list, t_li *room, int i, t_ways *list)
{
	t_li	*rooms;

	rooms = room;
	list = begin_list;
	while (list)
	{
		i = 0;
		while (i++ < list->i)
		{
			while (rooms)
			{
				if (rooms->number == list->n[i])
				{
					write(1, rooms->name, ft_strlen(rooms->name));
					write(1, "->", 2);
					break ;
				}
				rooms = rooms->next;
			}
			rooms = room;
		}
		if (list->i != 0)
			write(1, "\n", 1);
		list = list->next;
	}
}

void	get_ways(t_li *begin_list, size_t k, size_t i, int *m)
{
	t_ways	*ways;
	t_li	*list;

	m = (int *)malloc(sizeof(int ) * k);
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
	if (begin_list->flag_p == 'P')
		print_ways_l(ways->next, begin_list, 0, NULL);
	move_ants(ways->next, begin_list, 0, 0);
	free_all(begin_list, ways, NULL);
	free(m);
}
