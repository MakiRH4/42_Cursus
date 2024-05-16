/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:57:37 by fleonte           #+#    #+#             */
/*   Updated: 2024/05/15 20:27:42 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
