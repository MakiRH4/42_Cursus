/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 01:36:10 by floris            #+#    #+#             */
/*   Updated: 2024/05/15 00:59:06 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_u(unsigned int number)
{
	int digits;

	digits = 0;
	ft_putnbr_fd(number, 1);
	if (number == 0)
		digits = 1;
	else
	{
		while (number != 0)
		{
			number /= 10;
			digits++;
		}
	}
	return (digits);
}