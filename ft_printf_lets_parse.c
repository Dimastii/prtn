/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lets_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:08:12 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/27 15:54:42 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_type(char **str, s_s_f **struct_)
{
	if (**str == 'd')
		(*struct_)->type = 'd';
	else if (**str == 's')
		(*struct_)->type = 's';
	else if (**str == 'c')
		(*struct_)->type = 'c';
	else
		return ;
	++*str;
}

void	check_reed_precision(char **str, s_s_f **struct_, va_list **ap)
{
	if (**str == '.')
	{
		if (*(++*str) == '*')
		{
			(*struct_)->precision = va_arg(**ap, int);
			++*str;
		}
		else if (ft_isdigit(**str))
		{
			(*struct_)->precision = ft_atoi(*str);
			while (ft_isdigit(**str))
				++*str;
		}
		else
			(*struct_)->precision = 0;
	}
}

void	check_reed_width(char **str, s_s_f **struct_, va_list **ap)
{
	if (ft_isdigit(**str) && **str != '0')
	{
		(*struct_)->width = ft_atoi(*str);
		while (ft_isdigit(**str)) {
			++*str;
		}
	}
	if (**str == '*') {
		(*struct_)->width = va_arg(**ap, int);
		++*str;
	}
}

void	check_flags(char **str, s_s_f **struct_)
{
	if (**str == '-')
		(*struct_)->flags = (*struct_)->flags | FLG_MINUS;
	else if (**str == '0')
		(*struct_)->flags = (*struct_)->flags | FLG_ZERO;
	else
		return ;
	++*str;
}

char	*lets_parse(char *str, s_s_f *struct_, va_list *ap)
{
	str++;
	while (!struct_->type)
	{
		check_flags(&str, &struct_);
		check_reed_width(&str, &struct_, &ap);
		check_reed_precision(&str, &struct_, &ap);
		check_type(&str, &struct_);
	}
	return (str);
}