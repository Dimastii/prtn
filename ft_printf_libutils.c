/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:25:52 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/03 18:05:22 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int					ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int					ft_atoi(const char *str)
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

static void			ft_itoa_utils(int n, int *size)
{
	while (n /= 10)
		(*size)++;
}

char				*ft_itoa(int n, int precision)
{
	int		size;
	int		sign;
	char	*str;
	char	*strret;

	size = 1;
	sign = n < 0;
	ft_itoa_utils(n, &size);
	if (!(str = malloc(sizeof(char) * (size + 1 + precision))))
		return (NULL);
	strret = str;
	while ((precision-- - size) > 0)
		*str++ = '0';
	str += size;
	*str-- = '\0';
	if (n == 0)
		*str-- = '0';
	while (n)
	{
		*str-- = (n % 10) * (sign ? -1 : 1) + '0';
		n /= 10;
	}
	return (strret);
}
