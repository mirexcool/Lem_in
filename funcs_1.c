/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:58:00 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/12 15:39:40 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_link	*add_link(t_li *room)
{
	t_link	*links;

	links = (t_link *)malloc(sizeof(t_link));
	links->begin_link = room;
	links->next = NULL;
	return (links);
}

t_li	*add_list(void)
{
	t_li	*str;

	str = (t_li *)malloc(sizeof(t_li));
	str->next = NULL;
	str->ants = 0;
	str->number = 0;
	str->link = NULL;
	str->free = '1';
	str->type = '0';
	return (str);
}

void	make_num(t_li **begin_list)
{
	int		i;
	t_li	*list;

	i = 0;
	list = *begin_list;
	if (list->free == '0')
		return ;
	list->free = '0';
	while (list->next != NULL)
	{
		list->number = i;
		i++;
		list = list->next;
	}
}

int		is_ants(char *line)
{
	long long int	i;
	char			*str;

	i = ft_atoi(line);
	str = ft_itoa_long(i, 10, 0, 0);
	if (ft_strcmp(line, str) == 0)
	{
		if (i <= 0)
			ft_exit(1);
		free(str);
		return (1);
	}
	else
	{
		free(str);
		return (0);
	}
}

void	get_flags(char **line, t_li *b_l)
{
	if (ft_strcmp(line[1], "-p") == 0)
		b_l->flag_p = 'P';
}
