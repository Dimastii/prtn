/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:41:52 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/28 18:41:09 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_type_d(long long int num, s_s_f struct_)
{
	unsigned int i;
	char *str;
	char space;
	//printf("!!!%d !!\n", num);
	str = ft_itoa(num);


	space = ' ';
	if (struct_.flags & FLG_ZERO)
		space = '0';
	if (!str)
		str = "(null)";
	if ((struct_.precision < 0) || struct_.precision > (int)ft_strlen(str))
		struct_.precision = ft_strlen(str);
	i = struct_.precision;
	if (!(struct_.flags & FLG_MINUS) && (struct_.width))
		while (i < struct_.width && (i++ <= 1 - struct_.width - struct_.precision))
			write(1, &space, 1);
	write(1, str, struct_.precision);
	if ((struct_.flags & FLG_MINUS) && (struct_.width))
		while (i < struct_.width && (i++ <= 1 - struct_.width - struct_.precision))
			write(1, " ", 1);
}
