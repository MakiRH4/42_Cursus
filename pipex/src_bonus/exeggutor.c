/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggutor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:12:22 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/08 01:06:55 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exeggutor_first(char **command_id, char **argv, char **env, int *piped_fds)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (something_failed(), exit(1), -1);
	else if (pid == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			something_failed(2, argv)
			exit(127);
		}
		dup2(fd, STDIN_FILENO);
		dup2(piped_fds[WRITE], STDOUT_FILENO);
		close(piped_fds[WRITE]);
		execve(command_id[0], command_id, env);
	}
	free_array(command_id);
	close(piped_fds[WRITE]);
	return (pid);
}

int	halfway_exeggutor(char **command_id, char **argv, char **env, int *piped_fds, int i)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (something_failed(), exit(1), -1);
	else if (pid == 0)
	{
		dup2(piped_fds[READ], STDIN_FILENO);
		dup2(piped_fds[WRITE], STDOUT_FILENO);
		close(piped_fds[WRITE]);
		execve(command_id[i], command_id, env);
	}
	free_array(command_id);
	close(piped_fds[WRITE]);
	return (pid);
}

int	exeggutor_connex(int argc, char **argv, char **env, int *piped_fds)
{
	pid_t	*pid;
	int		i_pid;

	i_pid = 0;
	pid[i_pid] = exeggutor_first(ft_verify_command(argv[i_pid+2], env),
			argv, env, piped_fds);
	if pid[i_pid] == -1
	{
		free pid
		return failure
	}
	while (++i_pid+2 < argc -1)
	{
		pid[i_pid] = exeggutor_halfway(ft_verify_command(argv[i_pid+2], env),
				argv, env, piped_fds, i_pid);
		if pid[i_pid] == -1
		{
			free pid
			return failure
		}
	}
	pid[argc - 1] = exeggutor_last(t_verify_command(argv[argc-1], env),
			argv, env, piped_fds)
	if pid[argc - 1] == -1
	{
		free pid
		return failure
	}
	return (0);
}

int	exeggutor_last(char **command_id, char **argv, char **env, int *piped_fds)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (something_failed(), exit(1), -1);
	else if (pid == 0)
	{
		fd = open(argv[4], O_WRONLY | O_CREAT, 0777);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		dup2(piped_fds[READ], STDIN_FILENO);
		close(piped_fds[READ]);
		if ((execve(command_id[0], command_id, env)) == -1)
		{
			something_failed(3, argv);
//			perror("Execve failed");
			exit(127);
		}
	}
	close(piped_fds[READ]);
	return (pid);
}
