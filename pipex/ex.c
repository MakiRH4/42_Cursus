#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define READ_END 0	// index pipe, extremo escritura
#define WRITE_END 1	// index pipe, extremo lectura

int	main (int argc, char *argv[])
{
	int fd1[2], fd2[2];
	int status, pid;

	// the function creates pipefd[2], which stores the file descriptors that are connected
	pipe(fd1);	//communicates ls and grep and takes fd1[0] and fd1[1];

	pid = fork();
	printf("%d\n", pid);

	if (pid == 0)	// child 1
	{
		close(fd1[READ_END]);
		dup2(fd1[WRITE_END], STDOUT_FILENO); // what is written on STDOUT get written also on fd1[WRITE_END] (the pipe)
		close(fd1[WRITE_END]);
		execlp("/bin/ls", "ls", "-l", NULL); // calls ls from bin with the argument vector of index 0 (ls), is also programs name, and first arg "-l", end with NULL
	}
	else	//father
	{
		close(fd1[WRITE_END]); //end not needed anymore

		pipe(fd2);
		pid = fork();
		printf("%d\n", pid);

		if (pid == 0) //child 2
		{
			close(fd2[READ_END]); // close not needed end

			dup2(fd1[READ_END], STDIN_FILENO); // because grep reads from STDIN by default
			close(fd1[READ_END]);

			dup2(fd2[WRITE_END], STDOUT_FILENO);
			close(fd2[WRITE_END]);

			execlp("bin/grep", "grep", "u", NULL);
		}
		else // father
		{
			close(fd1[READ_END]);
			close(fd2[WRITE_END]);

			pid = fork();
			printf("%d\n", pid);
			if (pid == 0) // child 3
			{
				dup2(fd2[READ_END], STDIN_FILENO);
				close(fd2[READ_END]);

				execlp("/usr/bin/wc", "wc", "-l", NULL);
			}
		}
	}
		close(fd2[READ_END]);

		// wait for each child
		wait(&status);
		wait(&status);
		wait(&status);
	
	return 0;
}