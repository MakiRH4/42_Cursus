#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int gnl(int fd)
{
    char string[BUFFER_SIZE];
    int i;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    i = 0;
    //read(fd, string, BUFFER_SIZE);
    //printf("%s", string);
    printf("\n");
    while (i < BUFFER_SIZE && string[i] != '\n')
    {
        read(fd, string, BUFFER_SIZE);
        write(1, &string[i], 1);
        ++i;
    }
    printf("\n");
    printf("%ld", sizeof(fd));
    return(0);
}