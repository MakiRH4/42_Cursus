/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:33:54 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/05 04:45:33 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **array)
{
	int	strings;

	strings = -1;
	while (array[++strings])
		free(array[strings]);
	free(array);
}

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


char **ft_verify_command(char *command, char **env)
{
	char **command_splitted;
	char *valid_path;

	//Chequeo si me enviaron ./ls y si puedo ejecutarlo.
	command_splitted = ft_split(command, ' ');
	if (access(command_splitted[0], F_OK | X_OK) && str_in_str(command_splitted[0], "./"))
		return (command_splitted);
	else if(access(command_splitted[0], F_OK | X_OK) != 0 && ft_strchr(command_splitted[0], '/')) //Que pasa si me envian un comando incompleto bin/ls
		return (free_array(command_splitted), NULL);
	else
	{
		valid_path = find_path(command_splitted[0], env);
		free(command_splitted[0]);
		command_splitted[0] = valid_path;
		return (command_splitted);
	}
	return(command_splitted);
}
char	*find_path(char *command_id, char **env)
{
	char	**env_arr;
	char	**env_arr_cp;
	char	*path_temp;
	char	*path;

	while (*env++)
	{
		// if PATH= is found in **env, conditional evaluates to true
		if (str_in_str(*env, "PATH="))
		{
			env_arr = ft_split(*env, ':'); //ft_split gets a string from env
			env_arr_cp = env_arr;
			while (*env_arr++)
			{
				path_temp = ft_strjoin(*env_arr, "/"); // path + /
				path = ft_strjoin(path_temp, command_id); // path/ + command
				free(path_temp); //otherwise path_temp creates memory leaks
				ft_putstr_fd(path, 2);
				ft_putstr_fd("\n", 2);
				
				if (access(path, F_OK | X_OK) == 0)
				{
					ft_putstr_fd("al sona prohibida", 2);
					return (free_array(env_arr_cp), path);
				}
				free(path);
			}
			free_array(env_arr_cp);
		}
	}
	ft_putstr_fd(command_id, 2);
	return command_id;
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
