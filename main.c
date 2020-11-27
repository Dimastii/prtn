/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:59:51 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/27 14:55:02 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main() {
	int a = -10;
	char b = '4';
	char d = 'p';
	char *s = "qwerty";
	char *str;
	char *printArg = "\n111_%-20.0s_222\n";

	printf("|%*s",1, NULL);
	printf("\n--\n");
	//ft_printf("%-3s", NULL);
//	printf("\n--\n");
	ft_printf("|%*s",1, NULL);

//	ft_printf(printArg,"1234567890");
//	   printf(printArg,"1234567890");
}