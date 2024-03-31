#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

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

int printf_x(uintptr_t number, char *base)
{
    int digits;

    digits = 0;
    if (number >= 16)
    {
        printf_x((number / 16), base);
        write (1, &(char){base[number % 16]}, 1);
        digits += 1;
    }
    else 
        write (1, &(char){base[number % 16]}, 1);
        digits += 1;
    return (digits);
}

int printf_p(void *pointer)
{
    return (printf_x((uintptr_t) pointer, "0123456789abcdef"));
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
            ++printed_chars;
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
            void *zeiger;
            zeiger = va_arg(arguments, void *);
            printed_chars += write(1, "0x", 2);
            printed_chars += printf_p((void *)&zeiger);
        }
        else if (text[i] == 'd')
        {
            int d = va_arg(arguments, int);
            ft_putnbr_fd(d, 1);
            ++i;
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
        else if (text[i] == '%')
        {
            ft_putchar_fd('%', 1);
            ++i;
            printed_chars++;
        }
        else if (text[i] == 'x')
        {
            printed_chars += printf_x(va_arg(arguments, int), "0123456789abcdef");
            ++i;
        }
        else if (text[i] == 'X')
        {
            printed_chars += printf_x(va_arg(arguments, int), "0123456789ABCDEF");
            ++i;
        }
    }
    va_end(arguments);
    return printed_chars;
}

int main(void)
{
    char c = 'c';
    char *s = "stringgggg";
    void *p = (char *)s;
    int d = 012;
    int x = 123;
    int X = 123;
    char symbol = '%';
    int ft_printf_len;
    int printf_len;
    ft_printf_len = ft_printf("Das ist: %c und es schreibt:\nd: %d\nx: %x\nX: %X\ns: %s\nund Zeiger: %p\nund der neueste freund: %%\n", 'C', d, x, X, s, (void *)&d);
    printf("ft_printf-länge ist: %d chars\n", ft_printf_len);
    printf("Adresse des Zeigers: %p\n", (void *)&d);
    printf_len = printf("Das ist: %c und es schreibt:\nd: %d\nx: %x\nX: %X\ns: %s\nund Zeiger: %p\nund der neueste freund: %%\n", 'C', d, x, X, s, (void *)&d);
    printf ("printf-länge ist: %d chars\n", printf_len);
    return(0);
}