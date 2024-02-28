#include <stdio.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

int main(void)
{
    int i = 2;
    printf ("this is a two %d\n", i);
    printf ("meine funktion macht das\n");
    ft_putstr_fd ("this is a two 2\n", 1);
    
    return (0);
}