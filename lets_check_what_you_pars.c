/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_check_what_you_pars.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:16:42 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/02 20:32:31 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	lets_check_what_you_fuck_SpArSiL(s_s_f *struct_, va_list *ap)
{
	if (struct_->type == 's')
		write_type_s(va_arg(*ap, char*), *struct_);
	if (struct_->type == 'd')
		write_type_d(va_arg(*ap, int), *struct_);
	if (struct_->type == '%')
		write_type_percent(*struct_);
	if (struct_->type == 'c')
		write_type_char(va_arg(*ap, int), *struct_);
	if (struct_->type == 'i')
		write_type_i(va_arg(*ap, int), *struct_);
	if (struct_->type == 'p')
		write_type_p(va_arg(*ap, unsigned long long int), *struct_);
	if (struct_->type == 'x')
		write_type_x_X(va_arg(*ap, int), *struct_, 1);
	if (struct_->type == 'X')
		write_type_x_X(va_arg(*ap, int), *struct_, 0);
	if (struct_->type == 'u')
		write_type_u(va_arg(*ap, unsigned long long int), *struct_);
}
