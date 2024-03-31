/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:51:38 by floris            #+#    #+#             */
/*   Updated: 2024/04/01 01:15:50 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int printf_p(void *pointer)
{
    int length;
    int pointer_check;

    pointer_check = 0;

    write(1, "0x", 2);
    pointer check = 2;
    length = printf_x((uintptr_t) pointer, "0123456789abcdef");
    return (length + pointer_check);
}