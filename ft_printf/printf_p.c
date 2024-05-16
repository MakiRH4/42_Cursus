/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:57:04 by fleonte           #+#    #+#             */
/*   Updated: 2024/05/15 19:57:07 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_p(char *pointer)
{
	int	length;

	if (!pointer)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	write(1, "0x", 2);
	length = printf_x((unsigned long)pointer, "0123456789abcdef");
	return (length + 2);
}
