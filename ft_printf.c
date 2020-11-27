/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:52:25 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/27 14:51:43 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lets_null(s_s_f *struct_)
{
	struct_->flags = 0;
	struct_->width = 0;
	struct_->precision = -1;
	struct_->type = 0;
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	char  *strTemp;
	s_s_f struct_;

	strTemp = (char*) str;
	va_start(ap, str);
	while (*strTemp) {
		if (*strTemp == '%')
		{
			lets_null(&struct_);
			strTemp = lets_parse(strTemp, &struct_, &ap);
			lets_check_what_you_fuck_SpArSiL(&struct_, &ap);
		}
		else
			write(1, strTemp++, 1);
	}
	va_end(ap);
	return (0);
}