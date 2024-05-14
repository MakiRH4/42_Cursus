/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:51:38 by floris            #+#    #+#             */
/*   Updated: 2024/05/14 10:56:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_p(void *pointer)
{
	int	length;

	write(1, "0x", 2);
	length = printf_x((uintptr_t)pointer, "0123456789abcdef");
	return (length + 2);
}
