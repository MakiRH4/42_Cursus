/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:16:05 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/29 15:13:59 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!count || !size)
		return (ptr = (void *)malloc(0));
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, count * size);
	return (ptr);
}
