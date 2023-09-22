/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:18:21 by floris            #+#    #+#             */
/*   Updated: 2023/09/22 22:15:51 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char            *string;
    unsigned int    i;

    i = 0;
    string = ft_strdup(s);
    if (!string)
        return(NULL);
    while(string[i])
    {
        string[i] = (*f)(i, string[i]);
        i++;
    }
    return(string);
}