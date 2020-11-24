/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:52:25 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/24 14:58:10 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_reed_precision(char **str, s_s_f **struct_, va_list **ap)
{
	if (**str == '.')
	{
		if (*(++*str) == '*')
			(*struct_)->precision = va_arg(**ap, int);
		else
			(*struct_)->precision = ft_atoi(*str);
		while (ft_isdigit(**str))
			str++;
	}
	return (*str);
}

char	*check_reed_width(char **str, s_s_f **struct_, va_list **ap)
{
	if (ft_isdigit(**str) && **str != '0')
	{
		(*struct_)->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			str++;
	}
	if (**str == '*')
		(*struct_)->width = va_arg(**ap, int);
	return (*str);// над этой функциеей можно ещё покумекать но вроде работает
}

int		check_flags(char **str, s_s_f **struct_)
{
	if (**str == '-') {
		(*struct_)->flags = (*struct_)->flags | FLG_MINUS;
		return (1);
	}
	else if (**str == '0') {
		(*struct_)->flags = (*struct_)->flags | FLG_ZERO;
		return (1);
	}
	else
		return (0);
}

char *lets_parse(char *str, s_s_f *struct_, va_list *ap)
{
	str++;
	while (!struct_->type)
	{
		check_flags(&str, &struct_);
		str = check_reed_width(&str, &struct_, &ap);
		str = check_reed_precision(&str, &struct_, &ap);
		if (*str == 'd')
		{
			struct_->type = 1;
			return (++str);
		}
		str++;
	}
	return (str);
}

void ft_printf(const char *str, ...)
{
	va_list ap, ap2;
	char  *s;
	s_s_f struct_;

	struct_.flags = 0;
	struct_.type = 0;

	s = (char*) str;

	va_start(ap, str);
	va_copy(ap2, ap);
	while (*s)
	{
		if (*s == '%')
			s = lets_parse(s, &struct_, &ap);
		else
			write(1, s++, 1);
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
}