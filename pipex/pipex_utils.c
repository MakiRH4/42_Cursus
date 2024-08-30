/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:33:54 by fleonte           #+#    #+#             */
/*   Updated: 2024/08/30 23:35:48 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	char	*ret;

	if (!s1 || !s2)
		return NULL;
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	ret = joined;
	if (!joined)
		return (NULL);
	while (*s1)
		*joined++ = *s1++;
	while (*s2)
		*joined++ = *s2++;
	*(joined) = '\0';
	return (ret);
}