/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:05:04 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/29 20:11:38 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int			ft_isdigit(int c)
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

char	*ft_itoa(int n, int precision)
{
	int		temp;
	int		size;
	int		sign;
	char	*str;
	char	*strRet;


	temp = n;
	size = 1;
	sign = n < 0;
	while (temp /= 10)
		size++;
	if (!(str = malloc(sizeof(char) * (size + 1 + precision))))
		return (NULL);
	strRet = str;
	//if (sign)
	//	*str++ = '-';
	while ((precision-- - size) > 0) {
		*str++ = '0';
		//printf("!!!%s %d!!\n", str - 1, preci);
	}

	str += size;
	*str-- = '\0';
	if (n == 0)
		*str-- = '0';
	while (n)
	{
		*str-- = (n % 10) * (sign ? -1 : 1) + '0';
		n /= 10;
	}
	return (strRet);
}
