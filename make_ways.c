/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:07:52 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/11 19:07:59 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_ways	*add_way(int *m, int i)
{
	t_ways	*new;
	int		n;

	n = 0;
	new = (t_ways *)malloc(sizeof(t_ways));
	new->n = (int *)malloc(sizeof(int) * (i + 1));
	new->status = (long int *)malloc(sizeof(long int) * (i + 10));
	ft_bzero(new->status, sizeof(long int) * (i + 10));
	while (n < i + 1)
	{
		new->n[n] = m[n];
		n++;
	}
	new->next = NULL;
	new->i = i + 1;
	return (new);
}

int		check_way(int i, int *m, int c)
{
	int k;

	k = 0;
	while (k < c)
	{
		if (i == m[k])
			return (0);
		k++;
	}
	return (1);
}

void	make_ways(t_li *begin_list, int *m, int c, t_ways **ways)
{
	t_link	*list;
	t_ways	*way;

	way = *ways;
	if (check_way(begin_list->number, m, c) == 0)
		return ;
	m[c] = begin_list->number;
	if (begin_list->type == 'E')
	{
		while (way->next != NULL)
			way = way->next;
		way->next = add_way(m, c);
		return ;
	}
	list = begin_list->link;
	while (list)
	{
		make_ways(list->begin_link, m, c + 1, ways);
		list = list->next;
	}
}
