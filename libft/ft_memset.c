/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:05 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/06 10:16:30 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *data, int c, size_t n)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	res = (unsigned char *)data;
	while (i < n)
	{
		res[i] = (unsigned char)c;
		i++;
	}
	return (data);
}
