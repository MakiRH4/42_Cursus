/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:35:03 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/13 22:46:13 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Find the first occurrence of needle in haystack, where the search is limited 
 * to the first len characters of haystack.
 */

#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  i;
    size_t  j;

    i = 0;
    if (*needle == '\0') /* If needle is an empty string, haystack is returned */
        return (haystack);
    while (haystack[i])
    {
        j = 0;
        while(haystack[i + j] needle[j] && (i + j) < len)
        {
            if (haystack[i + j] && needle[j])
                return ((char *)(haystack + i);
            j++;
        }
        if (!needle[j])
            return((char *)(haystack + i));
        i++;
    }
    return (NULL) /* If needle occurs nowhere in haystack, NULL is returned */
}