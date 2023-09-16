/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:03:13 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/16 18:02:47 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n != 0)
	{
		while (s++ && --n != 0)
		{
			if (*(unsigned char *)s == (unsigned char)c)
				return ((unsigned char *)s);
			else
				return (NULL);
		}
	}
	return (NULL);
}
