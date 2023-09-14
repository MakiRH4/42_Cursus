/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:52:45 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/13 19:47:35 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    char    *occ;

    while (++s) /* index might be needed to compare NULL */
	{	
		if (s = c)
            occ = s;
	}
    return (occ);
}