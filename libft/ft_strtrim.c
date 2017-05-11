/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:45:00 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/09 15:44:22 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s)
		return (ft_strdup(""));
	i = 0;
	j = 0;
	len = ft_strlen(s);
	i = len - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		j++;
	}
	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		s++;
		i++;
	}
	if ((len - i) == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, 0, len - j - i));
}
