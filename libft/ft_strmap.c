/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:30:42 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/12 14:31:49 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*ptr;

	if (!s || !f)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	if (!str)
		return (NULL);
	ptr = str;
	while (*s)
	{
		*str++ = f(*(s++));
	}
	return (ptr);
}
