/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:48:40 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/07 18:27:55 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;

	while ((*alst))
	{
		(*del)((*alst)->content, (*alst)->content_size);
		ptr = *alst;
		*alst = (*alst)->next;
		free(ptr);
	}
}
