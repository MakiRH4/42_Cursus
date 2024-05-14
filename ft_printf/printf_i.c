/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 01:45:36 by floris            #+#    #+#             */
/*   Updated: 2024/05/14 09:57:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_i(int i)
{
	int	digits;

	digits = 0;
	ft_putnbr_fd(i, 1);
	if (i == 0)
		digits = 1;
	else
	{
		while (i != 0)
		{
			i /= 10;
			digits++;
		}
	}
	return (digits);
}
