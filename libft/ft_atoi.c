/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:05 by yyefimov          #+#    #+#             */
/*   Updated: 2017/05/11 19:10:34 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_check(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\r')
	{
		i++;
	}
	return (i);
}

long long int	ft_atoi(const char *str)
{
	long long	res;
	int			i;
	int			j;

	if (*str == '\0' || !str)
		return (0);
	res = 0;
	i = ft_check(str);
	j = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		while (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i] - '0';
			i++;
			if (res > 9223372036854775807 && str[j] == '-')
				return (0);
			if (res > 9223372036854775807)
				return (-1);
		}
	if (str[j] == '-')
		res = -res;
	return (res);
}
