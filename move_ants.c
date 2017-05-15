/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:48:12 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/11 18:50:48 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		go_to_next_room(long int *status, int *rooms, int size, t_li *b_l)
{
	long int i;

	i = size - 1;
	while (i > 0)
	{
		i--;
		if (status[i] > 0)
		{
			status[i + 1] = status[i];
			write(1, "L", 1);
			ft_putnbr(status[i]);
			write(1, "-", 1);
			ft_putstr(get_room(b_l, rooms[i + 1]));
			write(1, " ", 1);
			status[i] = 0;
			if (i == size - 2)
				status[i + 1] = 0;
		}
	}
}

void		move_it(t_ways *b_w, t_li *b_l)
{
	t_ways *list;

	list = b_w;
	while (list)
	{
		go_to_next_room(list->status, list->n, list->i, b_l);
		list = list->next;
	}
	write(1, "\n", 1);
}

int			ants_on_way(t_ways *b_w, long int n, long int ants)
{
	t_ways	*list;
	int		k;

	list = b_w;
	while (list)
	{
		k = 0;
		while (k < list->i)
		{
			if (list->status[k] > 0)
				return (1);
			k++;
		}
		list = list->next;
	}
	if (n < ants)
		return (1);
	return (0);
}

void		start_move(t_ways *b_w, t_li *b_l)
{
	long int	k;

	k = 1;
	while (ants_on_way(b_w, k, b_l->ants) || k <= b_l->ants)
	{
		k = on_start(b_w, b_l->ants, &k);
		move_it(b_w, b_l);
	}
}

void		move_ants(t_ways *b_w, t_li *b_l, long int stop, int i)
{
	t_ways		*way;
	int			start;

	way = b_w;
	while (!way->i)
		way = way->next;
	start = way->i;
	while (way)
	{
		if (way->i)
		{
			if (i == 0)
				way->stop = i;
			else if (start == way->i)
				way->stop = i;
			else
				way->stop = stop + i - 1 + way->i - start;
			stop = way->stop;
			i++;
		}
		way = way->next;
	}
	start_move(b_w, b_l);
}
