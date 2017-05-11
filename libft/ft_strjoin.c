/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 20:23:28 by yyefimov          #+#    #+#             */
/*   Updated: 2017/01/21 18:20:53 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (s == NULL)
		return (NULL);
	ft_strcat(s, s1);
	ft_strcat(s, s2);
	return (s);
}
