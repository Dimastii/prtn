/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:41:52 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/29 20:10:53 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_type_d(int num, s_s_f struct_)
{
	unsigned int i;
	char *str;
	char space;
	int sign;
	str = ft_itoa(num, struct_.precision);

	sign = (num < 0)? 1:0;
	space = ' ';
	if ((struct_.flags & FLG_ZERO) && struct_.precision < 0)
		space = '0';

	if ((struct_.flags & FLG_SPACE) && (num > 0) && !(struct_.flags & FLG_PLUS))
		write(1, " ", 1);
		//printf("|%d|", num);
	if (!str)
		str = "(null)";
	if ((struct_.precision < (int)ft_strlen(str)) || struct_.precision > (int)ft_strlen(str))
		struct_.precision = ft_strlen(str);
	i = struct_.precision + sign;
	//printf("!!!%d !!\n", struct_.precision);
	if (!(struct_.flags & FLG_MINUS) && (struct_.width))
		while (i < struct_.width && (i++ <= 1 - struct_.width - struct_.precision))
			write(1, &space, 1);
	if (num > 0 && (struct_.flags & FLG_PLUS))
		write(1, "+", 1);
	if (num < 0)
		write(1, "-", 1);
	write(1, str, struct_.precision);
	if ((struct_.flags & FLG_MINUS) && (struct_.width))
		while (i < struct_.width && (i++ <= 1 - struct_.width - struct_.precision))
			write(1, " ", 1);
}
