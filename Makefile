# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 15:38:53 by cveeta            #+#    #+#              #
#    Updated: 2020/11/14 16:34:45 by cveeta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
RM	= rm -f
SRCS	=	ft_printf_lets_parse.c ft_printf_utils.c ft_printf.c lets_check_what_you_pars.c
OBJ	= $(SRCS:.c=.o)
BONUS_OBJ	= $(BONUS:.c=.o)
all:	$(NAME)
$(NAME):$(OBJ)
		ar rc $(NAME) $(OBJ) ft_printf.h
clean:
		$(RM) $(OBJ) $(BONUS_OBJ)
fclean:	clean
		$(RM) $(NAME)
re:		fclean $(NAME)
bonus:	$(OBJ) $(BONUS_OBJ)
		ar rc $(NAME) $(OBJ) $(BONUS_OBJ) ft_printf.h