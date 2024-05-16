/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:57:45 by fleonte           #+#    #+#             */
/*   Updated: 2024/05/15 20:29:42 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	length_printf_x(unsigned long number)
{
	int	length;

	length = 0;
	if (number == 0)
	{
		return (1);
	}
	while (number != 0)
	{
		length++;
		number = number / 16;
	}
	return (length);
}

void	write_printf_x(unsigned long number, char *base)
{
	if (number >= 16)
	{
		write_printf_x((number / 16), base);
		write (1, &(char){base[number % 16]}, 1);
	}
	else
		write (1, &(char){base[number % 16]}, 1);
}

int	printf_x(unsigned long number, char *base)
{
	write_printf_x(number, base);
	return (length_printf_x(number));
}
