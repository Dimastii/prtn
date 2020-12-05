/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:27:32 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/05 19:22:15 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_type_p(unsigned long long int num, t_s s_)
{
	int		i;
	char	*str;
	char	space;
	int		sign;
	int		j;

	str = ft_itoa_p(num, s_.preci, 1, 16);
	sign = (num < 0) ? 1 : 0;
	space = ' ';
	if ((s_.flg & FLG_ZERO) && s_.preci < 0)
		space = '0';
	j = s_.preci;
	if (s_.preci != 0)
		j = ft_strlen(str);
	i = j + sign;
	if (!(s_.flg & FLG_MINUS) && (s_.wth))
		while (i++ < s_.wth - 2)
			ft_putchar(space);
	if (str)
		ft_putstr("0x", 2);
	write(1, str, j);
	if ((s_.flg & FLG_MINUS) && (s_.wth))
		while (i++ < s_.wth - 2)
			ft_putchar(' ');
	_ret += j;
	free(str);
}
