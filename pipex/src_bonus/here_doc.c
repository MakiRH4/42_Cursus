/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:59:08 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/11 04:03:31 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	here_doc(int argc, char **argv, char **env, int *piped_fds)
{
	char	*line;
	char	*lim;

	lim = argv[2];
	close(piped_fds[READ]);

	while (TRUE)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, lim, ft_strlen(lim)) == 0)
			(free(line), close(piped_fds[WRITE]), exit(0));
		ft_putstr_fd(line, piped_fds[WRITE], free(line));
	}

//	should call exeggutor_connex
	free(lim);
	return;
}
