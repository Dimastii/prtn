/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:52:25 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/05 19:00:48 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lets_null(t_s *struct_)
{
	struct_->flg = 0;
	struct_->wth = 0;
	struct_->preci = -1;
	struct_->type = 0;
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	char		*strtemp;
	t_s			struct_;

	_ret = 0;
	strtemp = (char*)str;
	va_start(ap, str);
	while (*strtemp)
	{
		if (*strtemp == '%')
		{
			lets_null(&struct_);
			strtemp = lets_parse(strtemp, &struct_, &ap);
			lets_check_what_you_fuck_sparsil(&struct_, &ap);
		}
		else
			ft_putchar(*strtemp++);

	}
	va_end(ap);
	return (_ret);
}
