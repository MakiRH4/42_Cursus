/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:51:38 by floris            #+#    #+#             */
/*   Updated: 2024/05/14 09:10:20 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	printf_p(void *pointer)
{
	int	length;
	int	pointer_check;

	write(1, "0x", 2);
	length = printf_x((uintptr_t)pointer, "0123456789abcdef");
	return (length + 2);
}
