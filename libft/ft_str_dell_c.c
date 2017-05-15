/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dell_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:23:52 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/12 12:30:45 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_dell_c(const char *str, int c)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (*str)
	{
		if (*str == c)
		{
			str++;
		}
		else
		{
			res[i] = *str;
			str++;
			i++;
		}
	}
	return (res);
}
