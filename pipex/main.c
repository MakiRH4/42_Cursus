/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:04 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/02 22:53:03 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// executes the commands
int	exeggutor(char *command_id, char *argv, char **env, int fd)
{
	pid_t	pid;
	int		file_fd;

	if ((pid = fork()) < 0)
		return (printf("fork for pid[0] failed"));
	else if (pid == 0)
	{
//		dup2(fd, STDOUT_FILENO);
//		execve(find_path(command_id, env), &argv, env);
//		exit;

//		file_fd = open ("text.txt", O_WRONLY);
//		printf("file_fd:%d\n", file_fd);
		dup2(fd, STDOUT_FILENO);
		printf("file_fd:%d\n", fd);
		execlp("/bin/ls", "ls", "-l", NULL);
	}
	return (pid); // Is it being returned if it is after an exit or an execve?
}

/*
int	pipex(char **command_id, char **argv, char **env)
{
	int		i;

	
	

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
*/
int	main(int argc, char **argv, char **env)
{
	char	**splitted_command;
	char	*command_id[2];
	int		piped_fds[2];
	pid_t	pid[2];
	int		status;
	int		file_fd;
//	if (argc != 5)
//		return (printf("%s", "wrong arg count"));

	printf("Parent PID: %d\n\n", getpid());
	
	// we PIPE here
	if (pipe(piped_fds) == -1)
		return (printf("pipe failed"));
	//printf("piped_fds: %d and %d\n", piped_fds[0], piped_fds[1]);
	file_fd = open ("text.txt", O_WRONLY);

	dup2(file_fd, STDOUT_FILENO);

	splitted_command = ft_split(argv[1], ' ');
	command_id[0] = splitted_command[0];
	splitted_command = ft_split(argv[2], ' ');
	command_id[1] = splitted_command[0];

	pid[0] = exeggutor(command_id[0], argv[2], env, piped_fds[PIPE_INLET]); // child for first command(argv[comm1])
//	printf("PID: %d //printed after line 90\n\n", getpid());
//	pid[1] = exeggutor(command_id[1], argv[3], env, piped_fds[1]); // child for second command(argv[comm2])
//	printf("PID: %d //printed after line 92\n", getpid());


	//printf("pids: %d and %d\n", pid[0], pid[1]);
//	if (pid[1] == 0)
//	{
//		printf("STATUSES:\n");
//		printf("PID: %d\n", getpid());
//	}
	waitpid(pid[0], &status, 0); // can't use wait(&status) because we have 2 parallel childs
//	printf("PID: %d // status pid[0]: %d\n", getpid(), status);
//	waitpid(pid[1], &status, 0); //-||-||-
//	printf("PID: %d // status pid[1]: %d\n", getpid(), status);
	return 0;
}