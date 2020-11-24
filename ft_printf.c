/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:52:25 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/24 19:43:27 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	lets_check_what_you_fuck_SpArSiL(char *str, s_s_f *struct_, va_list *ap)
{
	if (struct_->type == 'd'){}
}


int		ft_printf(const char *str, ...)
{
	va_list ap, ap2;
	char  *sss;
	s_s_f struct_;

	struct_.flags = 0;
	struct_.type = 0;

	sss = (char*) str;

	va_start(ap, str);
	va_copy(ap2, ap);
	while (*sss)
	{
		if (*sss == '%')
		{
			printf("1)%s\n",sss);
			sss = lets_parse(sss, &struct_, &ap);
			//lets_check_what_you_fuck_SpArSiL(s, &struct_, &ap);
			printf("2)%s\n",sss);
		}
		else{sss++;}
			//printf("%c",*s++);//write(1, s++, 1);
	}
	printf("\n%d|FLG\n", struct_.flags);
	if (struct_.flags & FLG_MINUS)
		printf("[+] FLG_MINUS exist\n");
	if (struct_.flags & FLG_ZERO)
		printf("[+] FLG_ZERO exist\n");
	if (struct_.width)
		printf("[+] width %d exist\n",struct_.width);
	if (struct_.precision)
		printf("[+] precision %d exist\n",struct_.precision);
	if (struct_.type  == 1)
		printf("[+] type d exist\n");
	va_end(ap);

	va_end(ap2);
	return (0);
}