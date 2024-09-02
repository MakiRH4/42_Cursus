/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:33:54 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/02 02:45:25 by fleonte          ###   ########.fr       */
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
		return (NULL);
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

char	*str_in_str(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while ((unsigned char)haystack[i + j] == (unsigned char)needle[j]
			&& haystack[i + j] && needle[j])
		{
			if (!needle[j + 1])
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*find_path(char *command_id, char **env)
{
	char	**env_arr;
	char	*path_temp;
	char	*path;

	while (*env++)
	{
		// if PATH= is found in **env, conditional evaluates to true
		if (str_in_str(*env, "PATH="))
		{
			env_arr = ft_split(*env, ':'); //ft_split gets a string from env
			while (*env_arr++)
			{
				path_temp = ft_strjoin(*env_arr, "/"); // path + /
				path = ft_strjoin(path_temp, command_id); // path/ + command
				free(path_temp); //otherwise path_temp creates memory leaks
				if (access(path, F_OK | X_OK) == 0)
					return (path);
				free(path);
			}
		}
	}
	printf ("command %s not found", command_id);
	return NULL;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i++ < n)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (dst - i + 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
