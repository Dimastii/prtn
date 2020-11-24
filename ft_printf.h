//
// Created by Cloyster Veeta on 11/19/20.
//

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# define FLG_NONE	0b00000000
# define FLG_MINUS	0b00000001
# define FLG_ZERO	0b00000010


#include "stdarg.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

typedef struct ssf
{
	unsigned char	flags;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	type;

} s_s_f;
void		ft_printf(const char *fmt, ...);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

#endif
