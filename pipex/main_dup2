#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main()
{
	int file_fd;

	file_fd = open ("text.txt", O_WRONLY);
	printf("%d\n", file_fd);
	dup2(file_fd, STDOUT_FILENO);
	printf("%d\n", file_fd);
	execlp("/bin/ls", "ls", "-l", NULL);
}