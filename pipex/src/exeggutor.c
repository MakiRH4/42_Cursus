/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggutor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:12:22 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/06 21:56:04 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//executes the commands
int	exeggutor_first(char **command_id, char **argv, char **env, int *piped_fds)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (ft_printf("fork for pid[0] failed"));
	else if (pid == 0)
	{

		int fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			(ft_printf("zsh: no such file or directory: %s", argv[1]), exit(127));
		dup2(fd, STDIN_FILENO);

		dup2(piped_fds[WRITE], STDOUT_FILENO);
		close(piped_fds[WRITE]);
		execve(command_id[0], command_id, env);
	}
	free_array(command_id);
	close(piped_fds[WRITE]);
	return (pid);
}

int	exeggutor_second(char **command_id, char **argv, char **env, int *piped_fds)
{
	pid_t	pid;

	pid = fork();

	if (pid < 0)
		return (ft_printf("fork for pid[0] failed"));
	else if (pid == 0)
	{

		int fd = open(argv[4], O_WRONLY | O_CREAT, 0777);	

		dup2(fd, STDOUT_FILENO);
		close(fd);
		dup2(piped_fds[READ], STDIN_FILENO);
		close(piped_fds[READ]);
		if ((execve(command_id[0], command_id, env)) == -1)
		{
			perror("Execve failed");
			exit(127);
		}
	}
	close(piped_fds[READ]);
	return (pid);
}