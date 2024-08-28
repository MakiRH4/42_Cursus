/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:22:54 by fleonte           #+#    #+#             */
/*   Updated: 2024/08/28 03:17:11 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;

    // Open the file in read-only mode
    fd = open("text.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    
    printf("File descriptor number is: %d\n", fd);

    // Loop to read the file line by line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Print each line
        free(line); // Free the allocated memory for the line
    }

/*
	line = get_next_line(fd);
	printf("%s", line); // Print each line
*/
/*
// YT way
	line = get_next_line(fd);
	if (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
    // Close the file descriptor
*/
//BUFFER_SIZE=223423423423
    close(fd);

    return (0);
}

