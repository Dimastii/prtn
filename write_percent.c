/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:08:27 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/28 17:31:12 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_type_percent(s_s_f struct_)
{
	unsigned int i;
	char space;

	space = ' ';
	if (struct_.flags & FLG_ZERO)
		space = '0';
	if ((struct_.precision < 0) || struct_.precision > 1)
		struct_.precision = 1;
	i = struct_.precision;
	if (!(struct_.flags & FLG_MINUS) && (struct_.width))
		while (i < struct_.width && (i++ <= 1 - struct_.width - struct_.precision))
			write(1, &space, 1);
	write(1, "%", 1);
	if ((struct_.flags & FLG_MINUS) && (struct_.width))
		while (i < struct_.width && (i++ <= 1 - struct_.width - struct_.precision))
			write(1, " ", 1);
}
