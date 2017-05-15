/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:05 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/09 15:05:19 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen((char *)dst);
	len_src = ft_strlen((char *)src);
	if (n == 0)
		return (len_src);
	if (n - 1 < len_dst)
		return (n + len_src);
	i = 0;
	while (dst[i])
		i++;
	while (*src && i < (n - 1))
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}
