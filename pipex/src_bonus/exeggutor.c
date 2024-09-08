/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggutor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:12:22 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/08 06:04:17 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

pid_t	exeggutor_last(char **command_id, char **argv, char **env, int *piped_fds, int argc)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (something_failed(1, argv), exit(1), -1);
	else if (pid == 0)
	{
		printf("exeg_last\n");
		printf("piped_fds[READ]: %d\n", piped_fds[READ]);
		printf("piped_fds[WRITE]: %d\n", piped_fds[WRITE]);
		fd = open(argv[argc-1], O_WRONLY | O_CREAT, 0777);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		close(piped_fds[WRITE]);
		dup2(piped_fds[READ], STDIN_FILENO);
		close(piped_fds[READ]);
		ft_putstr_fd("a ver si escribe el comando\n", STDOUT_FILENO);
		ft_putstr_fd(command_id[1], STDOUT_FILENO);
		if ((execve(command_id[0], command_id, env)) == -1)
		{
			something_failed(3, argv);
//			perror("Execve failed");
			exit(127);
		}
	}
	close(piped_fds[READ]);
	close(piped_fds[WRITE]);
	free_array(command_id);
//	close(piped_fds[READ]);
	return (pid);
}

pid_t	exeggutor_halfway(char **command_id, char **argv, char **env, int piped_fds[2], int i)
{
	pid_t	pid;
	int		pipe_halfway[2];

	pipe(pipe_halfway);
	pid = fork();
	if (pid < 0)
		return (something_failed(1, argv), exit(1), -1);
	else if (pid == 0)
	{
		printf("exeggutor_halfway\n");
		printf("piped_fds[READ]: %d\n", piped_fds[READ]);
		printf("pipe_halfway[WRITE]: %d\n", pipe_halfway[WRITE]);
		close(pipe_halfway[READ]);
		close(piped_fds[WRITE]);
		dup2(piped_fds[READ], STDIN_FILENO);
		close(piped_fds[READ]);
		dup2(pipe_halfway[WRITE], STDOUT_FILENO);
		close(pipe_halfway[WRITE]);
		execve(command_id[i], command_id, env);
		exit(0);
	}
	free_array(command_id);
	close(pipe_halfway[WRITE]);
	close(piped_fds[READ]);
	piped_fds[READ] = pipe_halfway[READ];
	return (pid);
}

pid_t	exeggutor_first(char **command_id, char **argv, char **env, int piped_fds[2])
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (something_failed(1, argv), exit(1), -1);
	else if (pid == 0)
	{

		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			something_failed(2, argv);
			exit(127);
		}
		printf("exeggutor_first\n");
		printf("fd: %d\n", fd);
		printf("piped_fds[WRITE]: %d\n", piped_fds[WRITE]);
		dup2(fd, STDIN_FILENO);
		close(fd);
		dup2(piped_fds[WRITE], STDOUT_FILENO);
		close(piped_fds[WRITE]);
		execve(command_id[0], command_id, env);
	}
	free_array(command_id);
	return (pid);
}

pid_t	*exeggutor_connex(int argc, char **argv, char **env, int piped_fds[2])
{
	pid_t	*pid;
	int		i_pid;

	i_pid = 0;
	pid = malloc(sizeof(pid_t) * (argc -  2));
	pid[i_pid] = exeggutor_first(ft_verify_command(argv[i_pid+2], env),
			argv, env, piped_fds);
	if (pid[i_pid] == -1)
	{
		free(pid);
		return NULL;
	}
	while (++i_pid + 2 < argc - 2)
	{
		pid[i_pid] = exeggutor_halfway(ft_verify_command(argv[i_pid+2], env),
				argv, env, piped_fds, i_pid);
		if (pid[i_pid] == -1)
		{
			free(pid);
			return NULL;
		}
	}
	pid[i_pid] = exeggutor_last(ft_verify_command(argv[argc - 2], env),
			argv, env, piped_fds, argc);
	if (pid[i_pid] == -1)
	{
		free(pid);
		return NULL;
	}
	return (pid);
}