#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void    ft_putchar_fd(char c, int fd);
void    ft_put_c(char c);

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_put_c(char c)
{
    ft_putchar_fd(c, 1);
}

void    ft_putstr_fd(char *s, int fd)
{
    while (*s)
    {
        ft_putchar_fd(*s, fd);
        s++;
    }
}

int ft_printf_s(va_list s)
{
    char    *str;
    int     len;

    str = va_arg(s, char *);
    if (str == NULL)
        str = "(null)";
    len = 0;
    while (*str)
    {
        ft_putchar_fd(*str, 1);
        str++;
        len++;
    }
    return len;
}

void    ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
    {
        ft_putchar_fd('-', fd);
        ft_putchar_fd('2', fd);
        ft_putnbr_fd(147483648, fd);
    }
    else if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -n;
        ft_putnbr_fd(n, fd);
    }
    else if (n > 9)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
    else
        ft_putchar_fd(n + 48, fd);
}

int ft_printf(char const *text, ...)
{
    va_list arguments;
    int i;
    int printed_chars = 0;

    i = 0;
    va_start(arguments, text);

    while (text[i] != '\0')
    {
        if(text[i] != '%')
        {
            ft_putchar_fd(text[i], 1);
            ++i;
            printed_chars++;
            continue;
        }
        if(text[++i] == 'c')
        {
            char c = va_arg(arguments, int);
            ft_putchar_fd(c, 1);
            ++i;
            printed_chars++;
        }
        else if (text[i] == 's')
        {
            printed_chars += ft_printf_s(arguments);
            ++i;
        }
        else if (text[i] == 'p')
        {
            // Assuming pointer value is being passed as argument
            void *p = va_arg(arguments, void *);
            printf("0x%p", p);
            ++i;
            printed_chars += 2; // '0x' added
        }
        else if (text[i] == 'd')
        {
            int d = va_arg(arguments, int);
            ft_putnbr_fd(d, 1);
            ++i;
            // Count digits in number
            int digits = 0;
            int temp = d;
            if (temp == 0)
                digits = 1;
            else
            {
                while (temp != 0)
                {
                    temp /= 10;
                    digits++;
                }
            }
            printed_chars += digits;
        }
    }
    va_end(arguments);
    return printed_chars;
}

int main(void)
{
    ft_printf("This is: %c and it's written in: %d , %d and %s. ze pointer ist %p", 'c', 1234, 567, "ebec", );
    return(0);
}