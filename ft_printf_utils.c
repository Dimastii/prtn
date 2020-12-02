/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:05:04 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/02 20:33:48 by cveeta           ###   ########.fr       */
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

static void		ft_itoaX_utils(unsigned int n, int *size, int upper_mode, char *x_or_X)
{
	while (n /= 16)
		(*size)++;
	if (upper_mode)
		*x_or_X = 'W';
	else
		*x_or_X = '7';
}
char	*ft_itoaX(unsigned int n, int precision, int upper_mode)
{
	int		size;
	char	*str;
	char	*strRet;
	char 	x_or_X;

	size = 1;
	ft_itoaX_utils(n, &size, upper_mode, &x_or_X);
	if (!(str = malloc(sizeof(char) * (size + 1 + precision))))
		return (NULL);
	strRet = str;
	while ((precision-- - size) > 0)
		*str++ = '0';
	str += size;
	*str-- = '\0';
	if (n == 0)
		*str-- = '0';
	while (n)
	{
		if ((n % 16) <= 9)
			*str-- = (n % 16) + '0';
		else
			*str-- = (n % 16) + x_or_X;
		n /= 16;
	}
	return (strRet);
}


static void		ft_itoaP_utils(unsigned long long int n, int *size, int upper_mode, char *x_or_X)
{
	while (n /= 16)
		(*size)++;
	if (upper_mode)
		*x_or_X = 'W';
	else
		*x_or_X = '7';
}

char	*ft_itoaP(unsigned long long int n, int precision, int upper_mode)
{
	int		size;
	char	*str;
	char	*strRet;
	char 	x_or_X;

	size = 1;
	ft_itoaP_utils(n, &size, upper_mode, &x_or_X);
	if (!(str = malloc(sizeof(char) * (size + 1 + precision))))
		return (NULL);
	strRet = str;
	while ((precision-- - size) > 0)
		*str++ = '0';
	str += size;
	*str-- = '\0';
	if (n == 0)
		*str-- = '0';
	while (n)
	{
		if ((n % 16) <= 9)
			*str-- = (n % 16) + '0';
		else
			*str-- = (n % 16) + x_or_X;
		n /= 16;
	}
	return (strRet);
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
	return (strRet);
}
