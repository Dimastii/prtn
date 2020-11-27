/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_check_what_you_pars.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:16:42 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/27 15:54:42 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reed_write_type_s(char *str, s_s_f struct_)
{
	unsigned int i;

	if (!str)
		str = "(null)";
	if ((struct_.precision < 0) || struct_.precision > (int)ft_strlen(str))
		struct_.precision = ft_strlen(str);
	i = struct_.precision;
	if (!(struct_.flags & FLG_MINUS) && (struct_.width))
		while (i < struct_.width && (i++ <= 1 - struct_.width - struct_.precision))
			write(1, " ", 1);
	write(1, str, struct_.precision);
	if ((struct_.flags & FLG_MINUS) && (struct_.width))
		while (i < struct_.width && (i++ <= 1 - struct_.width - struct_.precision))
			write(1, " ", 1);
}

void 	lets_check_what_you_fuck_SpArSiL(s_s_f *struct_, va_list *ap)
{
	if (struct_->type == 'd'){}
	if (struct_->type == 's') {
		reed_write_type_s(va_arg(*ap, char*), *struct_);
	}
}
