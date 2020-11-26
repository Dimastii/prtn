/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:52:25 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/25 16:43:24 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list ap, ap2;
	char  *strTemp;
	s_s_f struct_;

	struct_.flags = 0;
	struct_.width = 0;
	struct_.precision = 0;
	struct_.type = 0;

	strTemp = (char*) str;
	va_start(ap, str);
	va_copy(ap2, ap);
	while (*strTemp) {
		if (*strTemp == '%') {
			strTemp = lets_parse(strTemp, &struct_, &ap);
			lets_check_what_you_fuck_SpArSiL(strTemp, &struct_, &ap);
		}
		else
			{
			write(1, strTemp++, 1);
		}
	}
//	printf("\n%d|FLG\n", struct_.flags);
//	if (struct_.flags & FLG_MINUS)
//		printf("[+] FLG_MINUS exist\n");
//	if (struct_.flags & FLG_ZERO)
//		printf("[+] FLG_ZERO exist\n");
//	if (struct_.width)
//		printf("[+] width %d exist\n",struct_.width);
//	if (struct_.precision)
//		printf("[+] precision %d exist\n",struct_.precision);
//	if (struct_.type  == 1)
//		printf("[+] type d exist\n");
	va_end(ap);

	va_end(ap2);
	return (0);
}