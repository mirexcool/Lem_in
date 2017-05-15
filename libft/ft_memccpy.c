/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:05 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/09 14:28:49 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*cpy;

	res = (unsigned char *)dst;
	cpy = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (res = 0);
	while (i < n)
	{
		res[i] = cpy[i];
		if (cpy[i] == (unsigned char)c)
			return ((void *)&res[i + 1]);
		i++;
	}
	return (NULL);
}
