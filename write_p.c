/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:27:32 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/02 21:39:36 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_type_p(unsigned long long int num, s_s_f s_)
{
	int i;
	char *str;
	char space;
	int sign;
	int j;

	str = ft_itoaP(num, s_.preci, 1, 16);
	sign = (num < 0)? 1:0;
	space = ' ';
	if ((s_.flg & FLG_ZERO) && s_.preci < 0)
		space = '0';
	j = s_.preci;
	if (s_.preci != 0)
		j = ft_strlen(str);
	i = j + sign;
	if (!(s_.flg & FLG_MINUS) && (s_.wth))
		while (i++ < s_.wth - 2)
			write(1, &space, 1);
	if (str)
		write(1, "0x", 2);
	write(1, str, j);
	if ((s_.flg & FLG_MINUS) && (s_.wth))
		while (i++ < s_.wth - 2)
			write(1, " ", 1);
	free(str);
}
