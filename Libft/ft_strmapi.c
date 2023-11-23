/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:18:21 by floris            #+#    #+#             */
/*   Updated: 2023/11/23 16:15:42 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*string;

	if (!s)
		return NULL;
	i = 0;
	string = ft_strdup(s);
	if (!string)
		return (NULL);
	while (string[i])
	{
		string[i] = (*f)(i, string[i]);
		i++;
	}
	return (string);
}
