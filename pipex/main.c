/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:04 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/03 02:14:56 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	**splitted_command;
	char	*command_id[2];
	int		piped_fds[2];
	pid_t	pid[2];
	int		status;
	
	if (argc != 5)
		return (printf("%s", "wrong arg count"));
	
	// we PIPE here
	if (pipe(piped_fds) == -1)
		return (printf("pipe failed"));
	
	splitted_command = ft_split(argv[2], ' ');
	command_id[0] = splitted_command[0];
	splitted_command = ft_split(argv[3], ' ');
	command_id[1] = splitted_command[0];

	pid[0] = exeggutor(command_id[0], argv, env, piped_fds); // child for first command(argv[comm1])

//	pid[1] = exeggutor(command_id[1], argv[3], env, piped_fds[1]); // child for second command(argv[comm2])

	waitpid(pid[0], &status, 0); // can't use wait(&status) because we have 2 parallel childs
//	waitpid(pid[1], &status, 0); //-||-||-
	return 0;
}