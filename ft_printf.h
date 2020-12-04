/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:25:38 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/04 17:42:16 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLG_MINUS	0b00000001
# define FLG_ZERO	0b00000010
# define FLG_PLUS	0b00000100
# define FLG_FENCE	0b00001000
# define FLG_SPACE	0b00010000

# include "stdarg.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

int _ret;

typedef struct	s_list
{
	unsigned char	flg;
	int				wth;
	int				preci;
	unsigned char	type;

}				t_s;

int				ft_printf(const char *fmt, ...);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
char			*ft_itoa(int n, int precision);
char			*ft_itoa_x(unsigned int n, int precision, int upper_mode);
char			*ft_itoa_p(unsigned long long int n, int precision,
				int upper_mode, int base);
size_t			ft_strlen(const char *str);
char			*lets_parse(char *str, t_s *struct_, va_list *ap);
void			lets_check_what_you_fuck_sparsil(t_s *struct_, va_list *ap);
void			write_type_s(char *str, t_s struct_);
void			write_type_percent(t_s struct_);
void			write_type_char(char c, t_s struct_);
void			write_type_d(int num, t_s struct_);
void			write_type_i(int num, t_s s_);
void			write_type_x(unsigned int num, t_s s_, int mode);
void			write_type_u(unsigned int num, t_s s_);
void			write_type_p(unsigned long long int num, t_s s_);
void 			ft_putchar(char c);
#endif
