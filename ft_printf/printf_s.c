/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:57:11 by fleonte           #+#    #+#             */
/*   Updated: 2024/05/15 20:26:58 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_s(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		ft_putchar_fd((int)(*str), 1);
		str++;
		len++;
	}
	return (len);
}
