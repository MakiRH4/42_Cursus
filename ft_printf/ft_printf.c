/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:33:49 by marvin            #+#    #+#             */
/*   Updated: 2023/10/04 01:33:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char const *text, ...)
{
    va_list arguments;
    int i;
    int printed_chars = 0;

    i = 0;
    va_start(arguments, text);

    while (text[i] != '\0')
    {
        if(text[i] != '%')
        {
            ft_putchar_fd(text[i], 1);
            ++i;
            ++printed_chars;
            continue;
        }
        if(text[++i] == 'c')
        {
            char c = va_arg(arguments, int);
            ft_putchar_fd(c, 1);
            ++i;
            printed_chars++;
        }
        else if (text[i] == 's')
        {
            printed_chars += printf_s(arguments);
            ++i;
        }
        else if (text[i] == 'p')
        {
            void *zeiger;
            zeiger = va_arg(arguments, void *);
            printed_chars += write(1, "0x", 2);
            printed_chars += printf_p((void *)&zeiger);
        }
        else if (text[i] == 'd')
        {
            int d = va_arg(arguments, int);
            ft_putnbr_fd(d, 1);
            ++i;
            int digits = 0;
            int temp = d;
            if (temp == 0)
                digits = 1;
            else
            {
                while (temp != 0)
                {
                    temp /= 10;
                    digits++;
                }
            }
            printed_chars += digits;
        }
        else if (text[i] == '%')
        {
            ft_putchar_fd('%', 1);
            ++i;
            printed_chars++;
        }
        else if (text[i] == 'x')
        {
            uintptr_t x;
            x = va_arg(arguments, int);
            //printf_x(x, "0123456789abcdef");
            //printed_chars += length_printf_x(x);
            printed_chars += printf_x(x, "0123456789abcdef");
            ++i;
        }
        else if (text[i] == 'X')
        {
            uintptr_t X;
            X = va_arg(arguments, int);
            //printf_x(X, "0123456789ABCDEF");
            //printed_chars += length_printf_x(X);
            printed_chars += printf_x(X, "0123456789abcdef");
            ++i;
        }
    }
    va_end(arguments);
    return printed_chars;
}