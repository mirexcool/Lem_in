/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_filter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:46:17 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/11 18:47:52 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	find_doubles(int i, t_ways *begin_list, t_ways *hold)
{
	t_ways	*list;
	int		k;

	k = 1;
	list = begin_list;
	while (list)
	{
		while (k < list->i - 1)
		{
			if (i == list->n[k] && hold != list)
				list->i = 0;
			k++;
		}
		k = 1;
		list = list->next;
	}
}

void	way_filter(t_ways *begin_list, size_t q)
{
	t_ways	*list;
	size_t	i;
	size_t	k;

	i = 1;
	k = 1;
	list = begin_list;
	while (i <= q)
	{
		while (list)
		{
			if (list->i > 0)
			{
				while (k < (size_t)list->i - 1)
				{
					find_doubles(list->n[k], begin_list, list);
					k++;
				}
			}
			k = 1;
			list = list->next;
		}
		list = begin_list;
		i++;
	}
}

int		check_ways(t_ways *f, t_ways *s)
{
	int i;
	int j;

	i = 1;
	if (!f || !s)
		return (1);
	while (i < f->i - 1)
	{
		j = 1;
		while (j < s->i - 1)
		{
			if (f->n[i] == s->n[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		get_i(size_t n, size_t k, t_ways *b_w)
{
	t_ways	*f;
	t_ways	*s;
	t_ways	*list;

	list = b_w;
	f = NULL;
	s = NULL;
	while (list)
	{
		if (n == 0)
			f = list;
		if (k == 0)
			s = list;
		n--;
		k--;
		list = list->next;
	}
	return (check_ways(f, s));
}

void	sort_same_len(t_ways *b_w, size_t k, size_t n)
{
	int		**m;
	size_t	i;

	i = way_len(b_w);
	if (i == 1)
		return ;
	m = (int **)malloc(sizeof(int *) * i);
	while (k < i)
		m[k++] = (int *)malloc(sizeof(int) * i);
	while (n < i)
	{
		m[n][n] = 0;
		k = 0;
		while (k < i)
		{
			if (n != k)
				m[n][k] = get_i(n, k, b_w);
			k++;
		}
		n++;
	}
	if (check_for_zero(m, i) == 1)
		find_to_dell(m, i, b_w);
	free_matrix(m, i);
	free(m);
}
