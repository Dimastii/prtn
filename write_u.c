/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:54:10 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/05 18:52:04 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_itoau_utils(unsigned int n, int *size)
{
	while (n /= 10)
		(*size)++;
}

static char			*ft_itoa_u(unsigned int n, int precision)
{
	int				size;
	int				sign;
	char			*str;
	char			*strret;

	size = 1;
	sign = n < 0;
	ft_itoau_utils(n, &size);
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

void				write_type_u(unsigned int num, t_s s_)
{
	int		i;
	char	*str;
	char	space;
	int		sign;
	int		j;

	str = ft_itoa_u((int)num, s_.preci);
	sign = (num < 0) ? 1 : 0;
	space = ' ';
	if ((s_.flg & FLG_ZERO) && s_.preci < 0)
		space = '0';
	j = s_.preci;
	if (s_.preci != 0)
		j = ft_strlen(str);
	i = j + sign;
	if (!(s_.flg & FLG_MINUS) && (s_.wth))
		while (i++ < s_.wth)
			ft_putchar(space);
	write(1, str, j);
	if ((s_.flg & FLG_MINUS) && (s_.wth))
		while (i++ < s_.wth)
			ft_putchar(' ');
	_ret += j;
	free(str);
}
