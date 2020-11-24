/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:05:04 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/23 15:06:58 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned char	*c;
	int				sign;
	int				dig;

	dig = 0;
	sign = 1;
	c = (unsigned char*)str;
	while (*c == ' ' || *c == '\t' || *c == '\n' || *c == '\v' || *c == '\f'
		   || *c == '\r')
		c++;
	if ((*c == '-') || (*c == '+'))
	{
		if (*c == '-')
			sign *= -1;
		c++;
	}
	while (ft_isdigit(*c))
	{
		dig = dig * 10 + *c - '0';
		c++;
	}
	return (dig * sign);
}
