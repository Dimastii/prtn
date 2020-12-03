/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:05:04 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/03 18:20:11 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_itoax_utils(unsigned int n, int *size,
								int upper_mode, char *x_or_x)
{
	while (n /= 16)
		(*size)++;
	if (upper_mode)
		*x_or_x = 'W';
	else
		*x_or_x = '7';
}

char			*ft_itoa_x(unsigned int n, int precision, int upper_mode)
{
	int		size;
	char	*str;
	char	*strret;
	char	x_or_x;

	size = 1;
	ft_itoax_utils(n, &size, upper_mode, &x_or_x);
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
		if ((n % 16) <= 9)
			*str-- = (n % 16) + '0';
		else
			*str-- = (n % 16) + x_or_x;
		n /= 16;
	}
	return (strret);
}

static void		ft_itoap_utils(unsigned long long int n, int *size,
				int upper_mode, char *x_or_x)
{
	while (n /= 16)
		(*size)++;
	if (upper_mode)
		*x_or_x = 'W';
	else
		*x_or_x = '7';
}

static void		ft_itoap_utils_check(unsigned long long int n, char **str)
{
	if (n == 0)
		*(*str)-- = '0';
}

char			*ft_itoa_p(unsigned long long int n, int precision,
				int upper_mode, int base)
{
	int		size;
	char	*str;
	char	*strret;
	char	x_or_x;

	size = 1;
	ft_itoap_utils(n, &size, upper_mode, &x_or_x);
	precision = (precision >= -1) ? precision : -1;
	if (!(str = malloc(sizeof(char) * (size + 1 + precision))))
		return (NULL);
	strret = str;
	while ((precision-- - size) > 0)
		*str++ = '0';
	str += size;
	*str-- = '\0';
	ft_itoap_utils_check(n, &str);
	while (n)
	{
		if ((n % base) <= 9)
			*str-- = (n % base) + '0';
		else
			*str-- = (n % base) + x_or_x;
		n /= base;
	}
	return (strret);
}
