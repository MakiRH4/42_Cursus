/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:18:21 by floris            #+#    #+#             */
/*   Updated: 2024/10/21 17:53:09 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*string;

	if (!s)
		return (NULL);
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
