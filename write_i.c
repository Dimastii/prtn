/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:09:32 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/01 17:50:32 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_type_i(int num, s_s_f s_)
{
	int i;
	char *str;
	char space;
	int sign;
	int j;

	str = ft_itoa(num, s_.preci);
	sign = (num < 0)? 1:0;
	space = ' ';
	if ((s_.flg & FLG_ZERO) && s_.preci < 0)
		space = '0';
	if ((s_.flg & FLG_SPACE) && (num > 0) && !(s_.flg & FLG_PLUS))
		write(1, " ", 1);
	if (!str)
		str = "(null)";
	if (num > 0 && (s_.flg & FLG_PLUS) && (s_.flg & FLG_ZERO) && str[0] != '0')
		write(1, "+", 1);
	if (num < 0 && (((s_.flg & FLG_ZERO) && str[0] != '0' && !s_.wth)
					|| ((s_.flg & FLG_ZERO) && (str[0] == '0' || s_.wth) && s_.preci == -1)))
		write(1, "-", 1);
	j = s_.preci;
	if (s_.preci != 0)
		j = ft_strlen(str);
	i = j + sign;
	if (!(s_.flg & FLG_MINUS) && (s_.wth))
		while (i++ < s_.wth)
			write(1, &space, 1);
	if (num > 0 && (s_.flg & FLG_PLUS) && (!(s_.flg & FLG_ZERO) || str[0] == '0'))
		write(1, "+", 1);
	if (num < 0 && !(((s_.flg & FLG_ZERO) && str[0] != '0' && !s_.wth)
					 || ((s_.flg & FLG_ZERO) && (str[0] == '0' || s_.wth) && s_.preci == -1)))
		write(1, "-", 1);
	write(1, str, j);
	if ((s_.flg & FLG_MINUS) && (s_.wth))
		while (i++ < s_.wth)
			write(1, " ", 1);
}