/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:38:05 by marvin            #+#    #+#             */
/*   Updated: 2023/10/04 01:38:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_printer
{
    va_list arguments;
    int     width;
    int     length;
    int     count;
}	                t_printer;

int ft_printf(char const *, ...);

//the other functs

#endif