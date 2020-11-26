/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:59:51 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/26 10:15:39 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
	char *printArg = "\n111_%20.0s_222\n";
	char *printArg = "\n111_%20.s_222\n";
	char *printArg = "\n111_%20.11s_222\n";
	char *printArg = "\n111_%20.111s_222\n";

*/

int main() {
	int a = -10;
	char b = '4';
	char d = 'p';
	char *s = "qwerty";
	char *str;
	char *printArg = "\n111_%20.111s_222\n";
	//s[3] = '\0';


	ft_printf(printArg,"1234567890");
	   printf(printArg,"1234567890");
}