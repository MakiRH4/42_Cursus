/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggutor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:12:22 by fleonte           #+#    #+#             */
/*   Updated: 2024/10/17 22:41:51 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exeggutor_first(char **command_id, char **argv, char **env, int *piped_fds)
{
	int		fd;
	pid_t	pid;

	if (command_id == NULL)
		return (throw_error(5, NULL, piped_fds), exit(127), 0);
	pid = fork();
	if (pid < 0)
		return (throw_error(1, NULL, piped_fds), exit(1), -1);
	else if (pid == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (throw_error(2, argv[1], piped_fds), exit(127), -1);
		(dup2(fd, STDIN_FILENO), close(fd));
		(dup2(piped_fds[WRITE], STDOUT_FILENO), close(piped_fds[WRITE]));
		if ((execve(command_id[0], command_id, env)) == -1)
			(throw_error(3, command_id[0], piped_fds), exit(127));
		exit(0);
	}
	free_array(command_id);
	close(piped_fds[WRITE]);
	return (pid);
}

int	exeggutor_second(char **command_id, char **argv, char **env, int *piped_fds)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (throw_error(1, NULL, piped_fds), exit(1), -1);
	else if (pid == 0)
	{
		fd = open(argv[4], O_WRONLY | O_CREAT, 0777);
		(dup2(fd, STDOUT_FILENO), close(fd));
		(dup2(piped_fds[READ], STDIN_FILENO), close(piped_fds[READ]));
		if (command_id == NULL)
			(throw_error(5, NULL, piped_fds), exit(127));
		if ((execve(command_id[0], command_id, env)) == -1)
			(throw_error(3, command_id[0], piped_fds), exit(127));
		exit(0);
	}
	free_array(command_id);
	(close(piped_fds[READ]), close(piped_fds[WRITE]));
	return (pid);
}
