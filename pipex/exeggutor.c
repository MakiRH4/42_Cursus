/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggutor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:12:22 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/05 03:41:54 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// executes the commands
int	exeggutor(char **command_id, char **argv, char **env, int *piped_fds)
{
	pid_t	pid;

	pid = fork();

	if (pid < 0)
		return (printf("fork for pid[0] failed"));
	else if (pid == 0)
	{

		int fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			(ft_putstr_fd("failed to open infile", 2), exit(127));
		dup2(fd, STDIN_FILENO);

		dup2(piped_fds[WRITE], STDOUT_FILENO);
		close(piped_fds[WRITE]);
		execve(command_id[0], command_id, env);
	}
	free_array(command_id);
	close(piped_fds[WRITE]);
	return (pid);
}