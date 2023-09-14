/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:51:02 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/13 23:41:00 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int atoi(const char *str)
{
    int	sign;
	int	res;
    int signcont;

	sign = 1;
    signcont = 0;
	res = 0;
	if (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == 32 || *str == 43)
			str++;
		if (*str == 45)
        {
			sign = -sign;
            signcont++;
            if (signcont > 1)
                return (0);
        }
        str++;
		}
		while (*str >= 48 && *str <= 57)
		{
			res = (res * 10) + *str - 48;
			str++;
		}
	}
	return (res * sign);
}