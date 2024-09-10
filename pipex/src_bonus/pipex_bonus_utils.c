/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:42:40 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/11 01:43:13 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	something_failed(int reason, char *file_name)
{
	if (reason == 1)
//		close(all fds);
		return(ft_printf("fork failed\n"));
	else if (reason == 2)
//		close todas las cosas habidas y por haber
		return(ft_printf("zsh: no such file or directory: %s\n", file_name));
	else if (reason == 3)
//		execve failed, do what you gotta do
		return(ft_printf("zsh: command not found: %s\n", file_name));
	else
		return(0);
}

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
		if (str_in_str(*env, "PATH=") && *env[0] == 'P')
		{
			env_arr = ft_split(*env, ':');
			while (env_arr[++i])
			{
				path_temp = ft_strjoin(env_arr[i], "/");
				path = ft_strjoin(path_temp, command_id);
				free(path_temp);
				if (access(path, F_OK | X_OK) == 0)
					return (free_array(env_arr), path);
				free(path);
			}
			free_array(env_arr);
		}
		env++;
	}
	return (command_id);
}

char	**ft_verify_command(char *command, char **env)
{
	char	**cmd_splitted;
	char	*valid_path;

	cmd_splitted = ft_split(command, ' ');
	if (access(cmd_splitted[0], F_OK | X_OK)
		&& str_in_str(cmd_splitted[0], "./"))
		return (cmd_splitted);
	else if (access(cmd_splitted[0], F_OK | X_OK) != 0
		&& ft_strchr(cmd_splitted[0], '/'))
		return (free_array(cmd_splitted), NULL);
	else
	{
		valid_path = find_path(cmd_splitted[0], env);
		if (ft_strncmp(valid_path, cmd_splitted[0], ft_strlen(valid_path)) != 0)
		{
			free(cmd_splitted[0]);
			cmd_splitted[0] = valid_path;
		}
		return (cmd_splitted);
	}
	return (cmd_splitted);
}
