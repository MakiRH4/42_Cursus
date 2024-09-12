/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:55:58 by fleonte           #+#    #+#             */
/*   Updated: 2024/05/15 20:09:07 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_printer
{
	va_list	arguments;
	int		width;
	int		length;
	int		count;
}			t_printer;

int	ft_printf(char const *text, ...);
int	printf_c(int c);
int	printf_p(char *pointer);
int	printf_x(unsigned long number, char *base);
int	printf_s(char *str);
int	printf_d_i(int number);
int	printf_u(unsigned int number);

#endif
