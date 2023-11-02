#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void ft_putchar_fd(char c, int fd);
void ft_put_c(char c);

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void ft_put_c(char c)
{
    ft_putchar_fd(c, 1);
}

int ft_printf(const char *text, ...)
{
    va_list arguments;
    int i;

    i = 0;
    va_start(arguments, text);

    while (text[i] != '\0')
    {
        if (text[i] != '%')
        {
            ft_putchar_fd(text[i], 1);
        }
        else if (text[i] == '%' && text[i + 1] == 'c')
        {
            char c = va_arg(arguments, int);
            ft_put_c(c);
            i++; // Increment i to skip 'c' in the format string.
        }
        i++;
    }

    va_end(arguments);

    return i;
}

int main(void)
{
    ft_printf("This is: %c", 'c');
    return 0;
}