/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:02:26 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/14 20:02:37 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sbstr;

    sbstr = malloc(sizeof(char) * len) /* might have to add (char *) */
    if (!sbstr)
        return (NULL);
    while (i < len)
    {
        sbstr[i] = s[start]
        i++;
        start++;
    }
    sbstr[len] = '\0';
    return (sbstr);
}