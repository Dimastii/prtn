/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_check_what_you_pars.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:16:42 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/26 10:11:39 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reed_write_type_s(char *str, s_s_f struct_)
{
	unsigned int i;
	char *strTemp = str;


	if (!struct_.precision)
		struct_.precision = ft_strlen(strTemp);

	i = struct_.precision;
	if (struct_.width) {
		if (!(struct_.flags & FLG_MINUS))
		{
			printf("!!!!!!!1!!!!!!!");

			while (i < struct_.width /*- struct_.precision*/) {
				if ((i++ < 1 - struct_.width - struct_.precision))
					write(1, " ", 1);
				//printf("QWE precision %d | i %d \n",struct_.precision, i);
			}
			write(1, strTemp, struct_.precision);
		}
		else
		{
			printf("!!!!!!!2!!!!!!!");
			write(1, strTemp, struct_.precision);
			while (i < struct_.width /*- struct_.precision*/) {
				if ((i++ < 1 - struct_.width - struct_.precision))
					write(1, " ", 1);
			}
		}
	}
	else
		write(1, strTemp, struct_.precision);
}

void 	lets_check_what_you_fuck_SpArSiL(char *str, s_s_f *struct_, va_list *ap)
{
	if (struct_->type == 'd'){}
	if (struct_->type == 's') {
		reed_write_type_s(va_arg(*ap, char*), *struct_);
	}
}
