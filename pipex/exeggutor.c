/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggutor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:12:22 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/04 19:36:09 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// executes the commands
int	exeggutor(char *command_id, char **argv, char **env, int *piped_fds)
{
	pid_t	pid;
	int		file_fd;

	pid = fork();

	if (pid < 0)
		return (printf("fork for pid[0] failed"));
	else if (pid == 0)
	{
		dup2(piped_fds[WRITE], STDOUT_FILENO);
		execlp("/bin/ls", "ls", "-l", NULL);
//		execve(find_path(command_id, env), &argv[2], env);
//		execve(find_path(command_id, env), &argv, env); //doesn't work
//		execve("/usr/bin/ls", "ls -l", env);
//		exit;
	}
	return (pid); // Is it being returned if it is after an exit or an execve?
}