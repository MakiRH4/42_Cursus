/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:49:13 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/18 02:05:43 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	dstsize = (unsigned int)dstsize;
	i = 0;
	j = 0;
	if (dstsize > 0)
	{
		while (i < dstsize && dst[i])
			i++;
		while (src[j] && i + j < (dstsize - 1))
		{
			dst[i + j] = src[j];
			j++;
		}
		if (i + j < dstsize)
			dst[i + j] = '\0';
	}
	while (src[j])
		j++;
	return (i + j);
}