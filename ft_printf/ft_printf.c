/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:33:49 by marvin            #+#    #+#             */
/*   Updated: 2024/05/15 01:18:47 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(char type, va_list arguments)
{
	int	printed_chars;

	printed_chars = 0;
	if (type == 'c')
		printed_chars += printf_c(va_arg(arguments, int));
	else if (type == 's')
		printed_chars += printf_s(va_arg(arguments, char *));
	else if (type == 'p')
		printed_chars += printf_p((void *)va_arg(arguments, void *));
	else if (type == 'd' || type == 'i')
		printed_chars += printf_d_i((va_arg(arguments, int)));
	else if (type == 'u')
		printed_chars += printf_u((unsigned int)(va_arg(arguments, int)));
	else if (type == 'x')
		printed_chars += printf_x((uintptr_t)(va_arg(arguments, int)), \
									"0123456789abcdef");
	else if (type == 'X')
		printed_chars += printf_x((uintptr_t)(va_arg(arguments, int)), \
									"0123456789ABCDEF");
	else if (type == '%')
		printed_chars += write(1, "%", 1);
	return (printed_chars);
}

int	ft_printf(char const *text, ...)
{
	va_list	arguments;
	int		printed_chars;

	printed_chars = 0;
	va_start(arguments, text);
	while (*text != '\0')
	{
		if (*text == '%')
			printed_chars += print_type(*(++text), arguments);
		else
			printed_chars += write(1, text, 1);
		text++;
	}
	va_end(arguments);
	return (printed_chars);
}
