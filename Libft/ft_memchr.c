/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:03:13 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/13 19:45:50 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    int i;

    i = 0;
    if (n != 0)
    {
        while (s++ && --n != 0)
        {
            if (*s = c)
                return (s);
            else
                return (NULL);
        }
    }
    return (NULL);
}