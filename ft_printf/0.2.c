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

int ft_printf(char const *text, ...)
{
    va_list arguments;
    int i;

    i = 0;
    va_start(arguments, text);

    while (text[i] != '%' && text[i] != '\0')
    {
        ft_putchar_fd(text[i], 1);
        ++i;
    }
    if (text[i] == '%' && text[i + 1] != '\0' && text[i + 1] == 'c')
    {
        char c = va_arg(arguments, int);
        ft_putchar_fd(c, 1);
    }



    va_end(arguments);
    return (0);
}

int main(void)
{
    ft_printf("This is: %c and %c", 'c', 'z');
    return(0);
}