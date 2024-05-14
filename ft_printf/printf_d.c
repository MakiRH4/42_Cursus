/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 01:36:10 by floris            #+#    #+#             */
/*   Updated: 2024/05/14 09:56:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_d(int d)
{
	int digits;

	digits = 0;
	ft_putnbr_fd(d, 1);
	if (d == 0)
		digits = 1;
	else
	{
		while (d != 0)
		{
			d /= 10;
			digits++;
		}
	}
	return (digits);
}