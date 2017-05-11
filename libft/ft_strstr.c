/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:05 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/02 11:21:48 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*src;
	char	*find;

	src = (char *)s1;
	find = (char *)s2;
	if ((!*s1) && (!*s2))
		return ((char *)s1);
	while (*s1)
	{
		src = (char *)s1;
		find = (char *)s2;
		while (*s1 && find && *s1 == *find)
		{
			s1++;
			find++;
		}
		if (!*find)
			return (src);
		s1 = (char *)src + 1;
	}
	return (NULL);
}
