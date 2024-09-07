/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggutor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:12:22 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/08 00:05:59 by fleonte          ###   ########.fr       */
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

int	exeggutor_connex(int argc, char **argv, char **env, int *piped_fds)
{
	pid_t	*pid;

	int		i;

	i = 0;
	pid[i] = exeggutor_first(ft_verify_command(argv[2], env),
			argv, env, piped_fds);
	pid[1] = exeggutor_second(ft_verify_command(argv[3], env),
			argv, env, piped_fds);


}

int	exeggutor_second(char **command_id, char **argv, char **env, int *piped_fds)
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
