/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:04 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/01 02:06:09 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

# define FILE1			1	// 1st file
# define COMM1			2	// 1st command
# define COMM2			3	// 2nd command
# define FILE2			4	// 2nd file
# define PIPE_INLET		0
# define PIPE_OUTLET	1


int	pipex(char **command_id, char **argv, char **env)
{
	int	piped_fds[2];
	pid_t	pid[2];
	int		i;

	
	// we PIPE here
	if (pipe(piped_fds) == -1)
		return (printf("pipe failed"));

	// we DUP2 here
	dup2(piped_fds[PIPE_INLET], STDOUT_FILENO);

	// FORK child PID1
	if ((pid[0] = fork()) < 0)
		return (printf("fork for pid[0] failed"));
		
	
	// child PID1
	else if (pid[0] == 0)
	{
		dup2(piped_fds[PIPE_OUTLET], STDIN_FILENO);
		execve(find_path(command_id[0], env), &argv[1], env);
	}

	// FORK child PID2
	if ((pid[1] = fork()) < 0)
		return (printf("fork for pid[1] failed"));
		
	
	// child PID2
	else if (pid[1] == 0)
	{
		dup2(piped_fds[PIPE_OUTLET], STDIN_FILENO);
		execve(find_path(command_id[1], env), &argv[2], env);
	}
	
}

int	main(int argc, char **argv, char **env)
{
	char	**splitted_command;
	char	*command_id[2];

	if (argc != 5)
		return (printf("%s", "wrong arg count"));

	splitted_command = ft_split(argv[1], ' ');
	command_id[0] = splitted_command[0];
	splitted_command = ft_split(argv[2], ' ');
	command_id[1] = splitted_command[0];

	pipex(command_id , argv, env);

	return 0;
}