/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:05 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/12 10:27:58 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sorc;

	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	i = n - 1;
	if (n > 0)
	{
		if (src > dst)
		{
			ft_memcpy(dst, src, n);
		}
		else
		{
			while (i > 0)
			{
				dest[i] = sorc[i];
				i--;
			}
			dest[i] = sorc[i];
		}
	}
	return ((void *)dst);
}
