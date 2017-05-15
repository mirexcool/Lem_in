/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:01:34 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/12 15:40:13 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		room_exists(t_li *b_l, char *line)
{
	t_li *list;

	list = b_l;
	while (list->next)
	{
		if (ft_strncmp(list->name, line, ft_strlen(list->name)) == 0
			&& line[ft_strlen(list->name)] == ' ')
			return (1);
		list = list->next;
	}
	return (0);
}

size_t	list_len(t_li *b_l)
{
	size_t	i;
	t_li	*list;

	list = b_l;
	i = 0;
	while (list->next)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	find_to_dell(int **m, size_t i, t_ways *b_w)
{
	size_t k;
	size_t n;

	n = 0;
	while (n < i)
	{
		k = 0;
		while (k < i)
		{
			if (m[n][k] == 1)
				break ;
			if (k + 1 == i)
				mark_way(n, b_w);
			k++;
		}
		n++;
	}
}

void	mark_way(int n, t_ways *b_w)
{
	t_ways *list;

	list = b_w;
	while (list)
	{
		if (n == 0)
			list->i = 0;
		n--;
		list = list->next;
	}
}
