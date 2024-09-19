/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggutor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:12:22 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/19 14:51:18 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

pid_t	exeggutor_last(char **command_id, char *outfile,
			char **env, int *piped_fds)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (throw_error(1, outfile, NULL), exit(1), -1);
	else if (pid == 0)
	{
		fd = open(outfile, O_WRONLY | O_CREAT, 0777);
		(dup2(fd, STDOUT_FILENO), close(fd));
		close(piped_fds[WRITE]);
		(dup2(piped_fds[READ], STDIN_FILENO), close(piped_fds[READ]));
		if (command_id == NULL)
			(throw_error(3, NULL, NULL), exit(127));
		if ((execve(command_id[0], command_id, env)) == -1)
			(throw_error(3, command_id[0], piped_fds), exit(127));
		exit(0);
	}
	close(piped_fds[READ]);
	close(piped_fds[WRITE]);
	free_array(command_id);
	return (pid);
}

pid_t	exeggutor_halfway(char **command_id, char **argv,
			char **env, int piped_fds[2])
{
	pid_t	pid;
	int		pipe_halfway[2];

	pipe(pipe_halfway);
	if (command_id == NULL)
		return (throw_error(3, NULL, pipe_halfway), 0);
	pid = fork();
	if (pid < 0)
		return (throw_error(1, argv[0], NULL), exit(1), -1);
	else if (pid == 0)
	{
		(close(pipe_halfway[READ]), close(piped_fds[WRITE]));
		(dup2(piped_fds[READ], STDIN_FILENO), close(piped_fds[READ]));
		(dup2(pipe_halfway[WRITE], STDOUT_FILENO), close(pipe_halfway[WRITE]));
		if ((execve(command_id[0], command_id, env)) == -1)
			(throw_error(3, command_id[0], piped_fds), exit(127));
		exit(0);
	}
	free_array(command_id);
	(close(pipe_halfway[WRITE]), close(piped_fds[READ]));
	piped_fds[READ] = pipe_halfway[READ];
	return (pid);
}

pid_t	exeggutor_first(char **command_id, char **argv,
			char **env, int *piped_fds)
{
	int		fd;
	pid_t	pid;
	int		status;

	status = 0;
	if (command_id == NULL)
		return (throw_error(3, NULL, NULL), 0);
	pid = fork();
	if (pid < 0)
		return (throw_error(1, NULL, NULL), exit(1), -1);
	else if (pid == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (throw_error(2, argv[1], NULL), exit(12), -1);
		(dup2(fd, STDIN_FILENO), close(fd));
		(dup2(piped_fds[WRITE], STDOUT_FILENO), close(piped_fds[WRITE]));
		if ((execve(command_id[0], command_id, env)) == -1)
			(throw_error(3, command_id[0], NULL), exit(127));
		exit(0);
	}
	waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == 12)
		return (-1);
	return (free_array(command_id), pid);
}

pid_t	*exeggutor_connex(int argc, char **argv, char **env, int *piped_fds)
{
	pid_t	*pid;
	int		i_pid;

	i_pid = 0;
	pid = malloc(sizeof(pid_t) * (argc - 2));
	pid[i_pid] = exeggutor_first(ft_verify_command(argv[i_pid + 2], env),
			argv, env, piped_fds);
	if (pid[i_pid] == -1)
		return (free(pid), NULL);
	while (++i_pid + 2 < argc - 2)
	{
		pid[i_pid] = exeggutor_halfway(ft_verify_command(argv[i_pid + 2], env),
				argv, env, piped_fds);
		if (pid[i_pid] == -1)
			return (free(pid), NULL);
	}
	pid[i_pid] = exeggutor_last(ft_verify_command(argv[argc - 2], env),
			argv[argc - 1], env, piped_fds);
	if (pid[i_pid] == -1)
		return (free(pid), NULL);
	return (pid);
}
