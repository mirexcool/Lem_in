/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:05 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/09 14:42:26 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_zero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = '0';
	return (str);
}

static	char	*ft_max(void)
{
	char	*str;

	str = ft_strdup("-2147483648\0");
	return (str);
}

static	char	*ft_mem_alloc_str(size_t n)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * n + 1);
	return (str);
}

static	size_t	ft_size_of_int(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t	i;
	char	*str;

	if (n == 0)
		return (ft_zero());
	if (n == -2147483648)
		return (ft_max());
	i = ft_size_of_int(n);
	str = ft_mem_alloc_str(i);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	str[i] = '\0';
	while (n > 9)
	{
		str[--i] = n % 10 + '0';
		n = n / 10;
	}
	i--;
	str[i] = '0' + n;
	return (str);
}
