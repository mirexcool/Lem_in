/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:05 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/07 17:47:19 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *dst, int c)
{
	if (ft_strchr(dst, c) == NULL || !dst)
		return (NULL);
	while (*dst)
		dst++;
	while (*dst != c)
		dst--;
	return ((char *)dst);
}
