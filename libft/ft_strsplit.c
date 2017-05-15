/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:05 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/14 15:01:43 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_words(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == c)
			while (*str == c && *str)
				str++;
		if (*str == '\0')
			break ;
		while (*str && *str != c)
			str++;
		i++;
	}
	return (i);
}

static size_t	ft_len(char const *str, char c)
{
	size_t	len;

	len = 0;
	while (*str != c && *str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

static	char	**ft_makearr(char **res, const	char *str, char c)
{
	char	**tmp;
	size_t	words;
	size_t	index;

	index = 0;
	words = ft_count_words(str, c);
	tmp = res;
	while (index < words)
	{
		while (*str == c && *str != '\0')
			str++;
		tmp[index] = ft_strsub(str, 0, ft_len(str, c));
		if (tmp[index] == NULL)
		{
			while (index-- > 0)
				free(tmp[index]);
			return (NULL);
		}
		str = str + ft_len(str, c);
		index++;
	}
	tmp[words] = NULL;
	return (res);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**res;
	size_t	words;

	if (!str || *str == '\0' || str == NULL)
		return (ft_memalloc(sizeof(res)));
	words = ft_count_words(str, c);
	if (words == 0)
		return (ft_memalloc(sizeof(res)));
	res = (char **)malloc(sizeof(res) * words + 1);
	if (res == 0)
		return (ft_memalloc(sizeof(res)));
	res = ft_makearr(res, str, c);
	return (res);
}
