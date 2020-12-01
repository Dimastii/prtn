/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lets_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:08:12 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/01 17:05:08 by cveeta           ###   ########.fr       */
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
	else if (**str == '%')
		(*struct_)->type = '%';
	else if (**str == 'i')
		(*struct_)->type = 'i';
	else if (**str == 'p')
		(*struct_)->type = 'p';
	else if (**str == 'x')
		(*struct_)->type = 'x';
	else if (**str == 'X')
		(*struct_)->type = 'X';
	else if (**str == 'u')
		(*struct_)->type = 'u';
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
			(*struct_)->preci = va_arg(**ap, int);
			++*str;
		}
		else if (ft_isdigit(**str))
		{
			(*struct_)->preci = ft_atoi(*str);
			while (ft_isdigit(**str))
				++*str;
		}
		else
			(*struct_)->preci = 0;
	}
}

void	check_reed_width(char **str, s_s_f **struct_, va_list **ap)
{
	if (ft_isdigit(**str) && **str != '0')
	{
		(*struct_)->wth = ft_atoi(*str);
		while (ft_isdigit(**str)) {
			++*str;
		}
	}
	if (**str == '*') {
		(*struct_)->wth = va_arg(**ap, int);
		++*str;
	}
}

void	check_flags(char **str, s_s_f **struct_)
{
	//printf("1!!!%d <-----> %s!!!\n", (*struct_)->flg, *str);
	if (**str == '-')
		(*struct_)->flg = (*struct_)->flg | FLG_MINUS;
	else if (**str == '0')
		(*struct_)->flg = (*struct_)->flg | FLG_ZERO;
	else if (**str == ' ')
		(*struct_)->flg = (*struct_)->flg | FLG_SPACE;
	else if (**str == '#')
		(*struct_)->flg = (*struct_)->flg | FLG_FENCE;
	else if (**str == '+')
		(*struct_)->flg = (*struct_)->flg | FLG_PLUS;
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
