/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:03:13 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/19 15:42:13 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n != 0)
	{
		while ((int)--n >= 0)
		{
			if (*(unsigned char *)s == (unsigned char)c)
				return ((unsigned char *)s);
			s++;
		}
	}
	return (NULL);
}
