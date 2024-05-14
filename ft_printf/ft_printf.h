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
#include <stdint.h>

typedef struct s_printer
{
    va_list arguments;
    int     width;
    int     length;
    int     count;
}	                t_printer;

int ft_printf(char const *text, ...);
int printf_c(int c);
int printf_p(void *pointer);
int printf_x(uintptr_t number, char *base);
int printf_s(char *str);
int printf_d_i(int number);
int printf_u(unsigned int number);

#endif