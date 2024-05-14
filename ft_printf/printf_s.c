/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:56:13 by floris            #+#    #+#             */
/*   Updated: 2024/05/15 01:06:33 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int printf_s(char *str)
{
    int     len;

    len = 0;
    if (str == NULL)
        return (write(1, "(null)", 6));
    while (*str)
    {
        ft_putchar_fd((int)(*str), 1);
        str++;
        len++;
    }
    return (len);
}