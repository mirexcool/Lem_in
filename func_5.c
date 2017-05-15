/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:06:31 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/11 19:07:05 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		*get_room_1(char *line, t_li *begin_list)
{
	t_li	*list;

	list = begin_list;
	while (list->next)
	{
		if (ft_strncmp(list->name, line, ft_strlen(list->name)) == 0
			&& line[ft_strlen(list->name)] == '-')
			return (list->name);
		list = list->next;
	}
	return (NULL);
}

char		*get_room_2(char *line, t_li *begin_list, char *r1)
{
	t_li	*list;
	size_t	i;

	i = 0;
	list = begin_list;
	while (*line == *r1)
	{
		line++;
		r1++;
	}
	if (*line != '-')
		ft_exit(0);
	line++;
	while (list->next)
	{
		if (ft_strncmp(list->name, line, ft_strlen(line)) == 0)
			return (list->name);
		list = list->next;
	}
	ft_exit(0);
	return (NULL);
}

int			check_for_zero(int **m, size_t i)
{
	size_t k;
	size_t n;

	k = 0;
	n = 0;
	while (n < i)
	{
		k = 0;
		while (k < i)
		{
			if (m[n][k] == 1)
				return (1);
			k++;
		}
		n++;
	}
	return (0);
}

int			way_len(t_ways *w)
{
	t_ways	*list;
	int		i;

	i = 0;
	list = w;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

long int	on_start(t_ways *b_w, long int ants, long int *k)
{
	t_ways *list;

	list = b_w;
	while (list && *k <= ants)
	{
		if (list->i)
		{
			if (ants - (*k) >= list->stop - 1)
				list->status[0] = (*k)++;
		}
		list = list->next;
	}
	return (*k);
}
