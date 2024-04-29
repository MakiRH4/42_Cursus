/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:52:41 by floris            #+#    #+#             */
/*   Updated: 2024/04/01 01:47:33 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	length_printf_x(uintptr_t number)
{
	int length;

	length = 0;
	while (number != 0)
	{
		length++;
		number = number / 16;
	}
	return (length);
}

void write_printf_x(uintptr_t number, char *base)
{
    if (number >= 16)
    {
        write_printf_x((number / 16), base);
        write (1, &(char){base[number % 16]}, 1);
    }
    else 
        write (1, &(char){base[number % 16]}, 1);
}

int printf_x(uintptr_t number, char *base)
{
    write_printf_x(number, base);
    return(length_printf_x(number));
}