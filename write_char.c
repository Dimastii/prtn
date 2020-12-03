/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:30:25 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/03 17:17:06 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_type_char(char c, t_s struct_)
{
	int		i;
	char	space;

	space = ' ';
	if (struct_.flg & FLG_ZERO)
		space = '0';
	if ((struct_.preci < 0) || struct_.preci > 1)
		struct_.preci = 1;
	i = struct_.preci;
	if (!(struct_.flg & FLG_MINUS) && (struct_.wth))
		while (i++ < struct_.wth)
			write(1, &space, 1);
	write(1, &c, 1);
	if ((struct_.flg & FLG_MINUS) && (struct_.wth))
		while (i++ < struct_.wth)
			write(1, " ", 1);
}
