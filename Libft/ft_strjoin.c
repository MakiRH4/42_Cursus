/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:03:05 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/15 01:14:13 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *joined;
    int ttl;

    ttl = strlen(s1) + strlen(s2);
    joined = (char *)malloc(sizeof(s1) + sizeof(s2) + 1);
    if (!joined)
        return (NULL);
    while (s2)
    {
        while (s1)
            joined++ = s1++;
        joined++ = s2++;
    }
    ++joined = '\0';
    return (joined - (ttl + 1));
}