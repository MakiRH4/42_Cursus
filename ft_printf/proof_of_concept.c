#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void    ft_put_c(char c);

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void    ft_put_c(char c)
{
    ft_putchar_fd(c, 1);
}

int ft_printf(char const *text, ...);
{
    va_list arguments;
    
    va_start(arguments, text);
    
}