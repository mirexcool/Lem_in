/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:02:00 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/11 19:04:57 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	sort_and_clean_ways(t_ways *list)
{
	t_ways	*ways;
	int		buff;
	int		*n;

	ways = list;
	while (ways->next)
	{
		if (ways->i > ways->next->i)
		{
			buff = ways->i;
			n = ways->n;
			ways->i = ways->next->i;
			ways->n = ways->next->n;
			ways->next->i = buff;
			ways->next->n = n;
			ways = list;
		}
		else
			ways = ways->next;
	}
}

void	free_matrix(int **m, int i)
{
	int k;

	k = 0;
	while (k < i)
	{
		free(m[k]);
		k++;
	}
}

void	free_all(t_li *b_l, t_ways *b_w, t_li *next)
{
	t_ways	*n;
	t_link	*l;

	while (b_l)
	{
		next = b_l->next;
		while (b_l->link)
		{
			l = b_l->link->next;
			free(b_l->link);
			b_l->link = l;
		}
		if (b_l->next)
			free(b_l->name);
		free(b_l);
		b_l = next;
	}
	while (b_w)
	{
		n = b_w->next;
		free(b_w->n);
		free(b_w->status);
		free(b_w);
		b_w = n;
	}
}

char	*get_room(t_li *b_l, int i)
{
	t_li *list;

	list = b_l;
	while (list)
	{
		if (i == list->number)
			return (list->name);
		list = list->next;
	}
	return (NULL);
}
