/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:25:38 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/26 16:27:28 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# define FLG_NONE	0b00000000
# define FLG_MINUS	0b00000001
# define FLG_ZERO	0b00000010


# include "stdarg.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct ssf
{
	unsigned char	flags;
	unsigned int	width;
	int				precision;
	unsigned char	type;

} s_s_f;

int			ft_printf(const char *fmt, ...);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
char		*lets_parse(char *str, s_s_f *struct_, va_list *ap);
void		lets_check_what_you_fuck_SpArSiL(s_s_f *struct_, va_list *ap);

#endif
