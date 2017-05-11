/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:54:46 by yyefimov          #+#    #+#             */
/*   Updated: 2017/04/27 16:50:29 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nbr_to_upstr(unsigned long long v, unsigned long long b, char **str)
{
	if (v >= b)
	{
		nbr_to_upstr(v / b, b, str);
		nbr_to_upstr(v % b, b, str);
	}
	else
	{
		if (v >= 10)
			**str = v + 'A' - 10;
		else
			**str = v + '0';
		(*str)++;
	}
}

static void	nbr_to_lowstr(unsigned long long v, unsigned long long b, char **s)
{
	if (v >= b)
	{
		nbr_to_lowstr(v / b, b, s);
		nbr_to_lowstr(v % b, b, s);
	}
	else
	{
		if (v >= 10)
			**s = v + 'a' - 10;
		else
			**s = v + '0';
		(*s)++;
	}
}

char		*ft_itoa_unsigned(unsigned long long value, int base, char mod)
{
	char	*str;
	char	*p;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * 33);
	while (i < 33)
	{
		str[i] = 0;
		i++;
	}
	p = str;
	if (base > 1 && base < 17 && mod == 'X')
		nbr_to_upstr((unsigned long long)value, (unsigned int)base, &p);
	else if ((base > 1 && base < 17) || mod == 'x')
		nbr_to_lowstr((unsigned long long)value, (unsigned int)base, &p);
	return (str);
}
