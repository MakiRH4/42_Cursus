/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:04 by fleonte           #+#    #+#             */
/*   Updated: 2024/08/31 00:07:45 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

#define FILE1 1	// 1st file
#define COMM1 2	// 1st command
#define COMM2 3	// 2nd command
#define FILE2 4	// 2nd file

char	*ft_str_in_str(const char *haystack, const char *needle)
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

char	*find_path(char *command, char **env)
{
	char	**path_arr;
	char	*path;
	char	*path_temp;
	
	while (*env++)
	{
		// if PATH= is found in **env, conditional evaluates to true
		if (str_in_str(*env, "PATH="))
		{
			path_arr = ft_split(*env, ':'); //ft_split gets a string from env
			while (*path_arr++)
			{
				path_temp = ft_strjoin(*path_arr, '/'); // path + /
				path = ft_strjoin(path_temp, command); // path/ + command
				free(path_temp); //otherwise path_temp creates memory leaks
				if(access(path, F_OK | X_OK) == 0)
					return path;
				free(path);
			}	
		}
	}
	return ft_printf ("command %s not found", command);
}

int	main(int argc, char **argv, char **env)
{
	char	**command1;
	int		execint;

	if (argc != 5)
		return (printf("%s", "wrong arg count"));
	
	int execve(const char *filename, char *const argv[], char *const envp[]);

	**command1 = ft_split(argv[COMM1], " ");

	execint = execve(*argv[FILE1], *command1[0], *command1[1]);
	execint = execve("path/ls", ft_split(argv[COMM2], " "), env);


}