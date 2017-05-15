/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:23:23 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/12 11:53:15 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;

	if (lst)
	{
		res = malloc(sizeof(t_list));
		res = f(lst);
		res->next = ft_lstmap(lst->next, f);
		return (res);
	}
	return (NULL);
}
