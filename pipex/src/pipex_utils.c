/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:33:54 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/06 20:13:54 by fleonte          ###   ########.fr       */
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
	int		i;

	i = -1;
	while (*env)
	{
		// if PATH= is found in **env, conditional evaluates to true
		if (str_in_str/*ft_strnstr*/(*env, "PATH="/*, ft_strlen(*env)*/) && *env[0] == 'P')
		{
			env_arr = ft_split(*env, ':'); //ft_split gets a string from envm
			while (env_arr[++i])
			{
				path_temp = ft_strjoin(env_arr[i], "/"); // path + /
				path = ft_strjoin(path_temp, command_id); // path/ + command
				free(path_temp); //otherwise path_temp creates memory leaks
				if (access(path, F_OK | X_OK) == 0)
					return (free_array(env_arr), path);
				free(path);
			}
			free_array(env_arr);
		}
		env++;
	}
	return command_id;
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
		if (ft_strncmp(valid_path, command_splitted[0], ft_strlen(valid_path)) != 0)
		{
			free(command_splitted[0]);
			command_splitted[0] = valid_path;
		}
		return (command_splitted);
	}
	return(command_splitted);
}