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

int ft_printf(char const *text, ...);
{
    va_list arguments;

    while (text != '\0')
    {
        
    }

    va_start(arguments, text);

    printf(text)

    va_end(arguments);
}

// EXAMPLE
void    print_ints(int num, ...)
{
    va_list args;

    va_start(args, num);

    for (int i = 0; i < num; i++)
    {
        int value = va_arg(args, int);
        printf("%d: %d\n", i, value);
    }

    va_end(args);
}
int ft_printf(char const *, ...)
{
    
}