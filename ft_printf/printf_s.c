/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:56:13 by floris            #+#    #+#             */
/*   Updated: 2024/04/01 01:47:29 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int printf_s(va_list s)
{
    char    *str;
    int     len;

    str = va_arg(s, char *);
    if (str == NULL)
        str = "(null)";
    len = 0;
    while (*str)
    {
        ft_putchar_fd(*str, 1);
        str++;
        len++;
    }
    return len;
}