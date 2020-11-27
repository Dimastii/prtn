/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_check_what_you_pars.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:16:42 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/27 19:48:22 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_type_d(long long int dig, s_s_f struct_)
{

}

void	write_type_percent(s_s_f struct_)
{
	unsigned int i;

	if (!(struct_.flags & FLG_MINUS) && (struct_.width))
		while (i < struct_.width && (i++ <= 1 - struct_.width - struct_.precision))
			write(1, " ", 1);
	write(1, "%", 1);
	if ((struct_.flags & FLG_MINUS) && (struct_.width))
		while (i < struct_.width && (i++ <= 1 - struct_.width - struct_.precision))
			write(1, " ", 1);
}

void 	lets_check_what_you_fuck_SpArSiL(s_s_f *struct_, va_list *ap)
{
	if (struct_->type == 'd')
		write_type_d(va_arg(*ap, long long), *struct_);
	if (struct_->type == 's')
		write_type_s(va_arg(*ap, char*), *struct_);
	if (struct_->type == '%')
		write_type_percent(*struct_);
}
