/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:09:32 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/03 17:17:06 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		lets_write_minus_0(char *space, char **str, int num, t_s s_)
{
	*space = ' ';
	if ((s_.flg & FLG_ZERO) && s_.preci < 0)
		*space = '0';
	if ((s_.flg & FLG_SPACE) && (num > 0) && !(s_.flg & FLG_PLUS))
		write(1, " ", 1);
	if (num > 0 && (s_.flg & FLG_PLUS)
	&& (((s_.flg & FLG_ZERO) && *str[0] != '0' && !s_.wth)
	|| ((s_.flg & FLG_ZERO) && (*str[0] == '0' || s_.wth) && s_.preci == -1)))
		write(1, "+", 1);
	if (num < 0 && (((s_.flg & FLG_ZERO) && *str[0] != '0' && !s_.wth)
	|| ((s_.flg & FLG_ZERO) && (*str[0] == '0' || s_.wth) && s_.preci == -1)))
		write(1, "-", 1);
}

static void		lets_write_minus_1(char **str, int num, t_s s_)
{
	if (num > 0 && (s_.flg & FLG_PLUS)
	&& !(((s_.flg & FLG_ZERO) && *str[0] != '0' && !s_.wth)
	|| ((s_.flg & FLG_ZERO) && (*str[0] == '0' || s_.wth) && s_.preci == -1)))
		write(1, "+", 1);
	if (num < 0 && !(((s_.flg & FLG_ZERO) && *str[0] != '0' && !s_.wth)
	|| ((s_.flg & FLG_ZERO) && (*str[0] == '0' || s_.wth) && s_.preci == -1)))
		write(1, "-", 1);
}

void			write_type_i(int num, t_s s_)
{
	int		i;
	char	*str;
	char	space;
	int		sign;
	int		j;

	str = ft_itoa(num, s_.preci);
	sign = (num < 0) ? 1 : 0;
	lets_write_minus_0(&space, &str, num, s_);
	j = s_.preci;
	if (s_.preci != 0)
		j = ft_strlen(str);
	i = j + sign;
	if (!(s_.flg & FLG_MINUS) && (s_.wth))
		while (i++ < s_.wth)
			write(1, &space, 1);
	lets_write_minus_1(&str, num, s_);
	write(1, str, j);
	if ((s_.flg & FLG_MINUS) && (s_.wth))
		while (i++ < s_.wth)
			write(1, " ", 1);
	free(str);
}
