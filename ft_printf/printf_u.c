/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 01:36:10 by floris            #+#    #+#             */
/*   Updated: 2024/05/15 17:38:32 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	ft_putuint(int n)
{
	if (n > 9)
	{
		ft_putuint(n / 10);
		ft_putuint(n % 10);
	}
	else
		ft_putchar_fd(n + 48, 1);
}

int	printf_u(unsigned int number)
{
	int digits;

	digits = 0;
	ft_putuint(number);
	if (number == 0)
		digits = 1;
	while (number != 0)
	{
		number /= 10;
		digits++;
	}
	return (digits);
}
*/
int	printf_u(unsigned int n)
{
	char	*str;
	int		digits;

	digits = 0;
	str = "0123456789abcdef";
	if (n < 10)
		digits += printf_c(str[n]);
	else
	{
		digits += printf_u(n / 10);
		digits += printf_u(n % 10);
	}
	return (digits);
}