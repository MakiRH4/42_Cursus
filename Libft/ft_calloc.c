/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:16:05 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/14 18:27:52 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    void    *ptr;

    if (count == 0 || size == 0)
    {
        count = 1;
        size = count;
    }
    ptr = malloc (count * size);
    if (ptr)
        ft_bzero (ptr, count * size);
    return (ptr);
}