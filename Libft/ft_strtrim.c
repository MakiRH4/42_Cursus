/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:13:11 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/23 22:13:28 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istrimmable(char c, char *sett)
{
	int	i;

	i = 0;
	while (sett[i])
	{
		if (c == sett[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	char		*return_string;
	int			i;

	start = s1;
	end = s1 + (ft_strlen(s1) - 1);
	while (*start && ft_istrimmable(*start, (char *)set))
		start++;
	while (end > start && ft_istrimmable(*end, (char *)set))
		end--;
	return_string = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!return_string)
		return (NULL);
	i = 0;
	while (start <= end)
		return_string[i++] = *start++;
	return_string[i] = '\0';
	return (return_string);
}
