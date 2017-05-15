/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:05 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/12 10:27:02 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	c;
	size_t	j;

	j = 0;
	i = 0;
	c = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		j = i;
		while (s1[j] == s2[c] && j < n)
		{
			j++;
			c++;
			if (s2[c] == '\0')
				return ((char*)&s1[i]);
		}
		i++;
		c = 0;
	}
	return (NULL);
}
