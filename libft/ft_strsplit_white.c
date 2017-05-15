/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_white.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:05 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/12 14:30:28 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	size_t	ft_count_words(char const *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
			while ((*str == ' ' || *str == '\t' || *str == '\n') && *str)
				str++;
		if (*str == '\0')
			break ;
		while (*str && (*str != ' ' || *str != '\t' || *str != '\n'))
			str++;
		i++;
	}
	return (i);
}

static size_t	ft_len(char const *str)
{
	size_t	len;

	len = 0;
	while ((*str != ' ' || *str != '\t' || *str != '\n') && *str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

static	char	**ft_makearr(char **res, const	char *str)
{
	char	**tmp;
	size_t	words;
	size_t	index;

	index = 0;
	words = ft_count_words(str);
	tmp = res;
	while (words--)
	{
		while ((*str == ' ' || *str == '\t' || *str == '\n') && *str != '\0')
			str++;
		tmp[index] = ft_strsub(str, 0, ft_len(str));
		if (tmp[index] == NULL)
			return (NULL);
		str = str + ft_len(str);
		index++;
	}
	return (res);
}

char			**ft_strsplit_white(char const *str)
{
	char	**res;
	size_t	words;

	words = ft_count_words(str);
	if (!str || *str == '\0')
		return (ft_memalloc(sizeof(res)));
	if (words == 0)
		return (ft_memalloc(sizeof(res)));
	res = (char **)malloc(sizeof(res) * words + 1);
	if (res == 0)
		return (ft_memalloc(sizeof(res)));
	res = ft_makearr(res, str);
	res[words] = NULL;
	return (res);
}
