/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:42:43 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/02 19:50:57 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_type_x_X(unsigned int num, s_s_f s_, int mode)
{
	int i;
	char *str;
	char space;
	int sign;
	int j;

	str = ft_itoaX(num, s_.preci, mode);
	sign = (num < 0)? 1:0;
	space = ' ';
	if ((s_.flg & FLG_ZERO) && s_.preci < 0)
		space = '0';
	j = s_.preci;
	if (s_.preci != 0)
		j = ft_strlen(str);
	i = j + sign;
	if (!(s_.flg & FLG_MINUS) && (s_.wth))
		while (i++ < s_.wth)
			write(1, &space, 1);
	write(1, str, j);
	if ((s_.flg & FLG_MINUS) && (s_.wth))
		while (i++ < s_.wth)
			write(1, " ", 1);
	free(str);
}
