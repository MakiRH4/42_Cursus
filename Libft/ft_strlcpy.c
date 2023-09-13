/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:25:47 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/13 15:50:51 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t	ft_strlcpy(char * dst, const char * src, size_t dstsize);
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src && i <= (dstsize - 1))
		{
			dst++ = src++;
			i++;
		}
		dst++ = '\0';
		i++; /* i++ so returns full length accounting for NUL-termination */
	}
	return (i)
}
