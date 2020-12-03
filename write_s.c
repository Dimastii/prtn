/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:11:24 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/03 17:17:06 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_type_s(char *str, t_s struct_)
{
	int i;

	if (!str)
		str = "(null)";
	if ((struct_.preci < 0) || struct_.preci > (int)ft_strlen(str))
		struct_.preci = ft_strlen(str);
	i = struct_.preci;
	if (!(struct_.flg & FLG_MINUS) && (struct_.wth))
		while (i++ < struct_.wth)
			write(1, " ", 1);
	write(1, str, struct_.preci);
	if ((struct_.flg & FLG_MINUS) && (struct_.wth))
		while (i++ < struct_.wth)
			write(1, " ", 1);
}
