/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:59:51 by cveeta            #+#    #+#             */
/*   Updated: 2020/12/03 16:06:10 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*


 * "%.d" !!!!!!!!!!!!!!!!!!!!!?!?!?!?!?!?!?!?!?!?!?
 *
 *  First line of code: {return test("%07d", -54);}
    First line of code: {return test("%04d", -532);}
    First line of code: {return test("%04d", -4825;}


    First line of code: {return test("%08.3d", -8473);}
    First line of code: {return test("%03.3d", -8462);}
    First line of code: {return test( "%0-8.3d", -8473);}
    First line of code: {return test("%0-3.3d", -8462);}

"%*s", -3, "hello"

 * "% 010.5d", -216
 * "% 08.3d", -8473
 */
 int main()
{
	char *qwe = "%04d";
	char *qww = "%04d";
	char *www = "%04d";

//	char *qwe = "%07d";
//	char *qww = "%04d";
//	char *www = "%04d";

	int qqq =   -8141;
	int hex = 1024;
	printf("this %.s number\n", "1");
	ft_printf("this %.s number\n", "1");

}