/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:26:40 by fleonte           #+#    #+#             */
/*   Updated: 2023/10/04 18:28:20 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		strl;

	strl = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * strl + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, strl);
	str[strl] = '\0';
	return (str);
}
