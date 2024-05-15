/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 01:36:10 by floris            #+#    #+#             */
/*   Updated: 2024/05/15 17:09:42 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_d_i(int number)
{
	int digits;

	digits = 0;
	ft_putnbr_fd(number, 1);
	if (number == 0)
		digits = 1;
	else if (number < 0)
	{
		digits++;
		number *= -1;
	}
	while (number != 0)
	{
		number /= 10;
		digits++;
	}
	return (digits);
}