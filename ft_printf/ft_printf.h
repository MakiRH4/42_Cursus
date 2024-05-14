/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:38:05 by marvin            #+#    #+#             */
/*   Updated: 2023/10/04 01:38:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "./../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct s_printer
{
    va_list arguments;
    int     width;
    int     length;
    int     count;
}	                t_printer;

int ft_printf(char const *text, ...);
int printf_p(void *pointer);
int printf_x(uintptr_t number, char *base);
int printf_s(va_list s);
int printf_i(int i);
int printf_d(int d);

#endif