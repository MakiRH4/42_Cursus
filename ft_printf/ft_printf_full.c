/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:59:22 by floris            #+#    #+#             */
/*   Updated: 2024/04/01 01:16:06 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_putstr_fd(char *s, int fd)
{
    while (*s)
    {
        ft_putchar_fd(*s, fd);
        s++;
    }
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

int	length_printf_x(uintptr_t number)
{
	int length;

	length = 0;
	while (number != 0)
	{
		length++;
		number = number / 16;
	}
	return (length);
}

void write_printf_x(uintptr_t number, char *base)
{
    if (number >= 16)
    {
        write_printf_x((number / 16), base);
        write (1, &(char){base[number % 16]}, 1);
    }
    else 
        write (1, &(char){base[number % 16]}, 1);
}

int printf_x(uintptr_t number, char *base)
{
    write_printf_x(number, base);
    return(length_printf_x(number));
}

int printf_p(void *pointer)
{
    int length;
    write(1, "0x", 2);
    length = printf_x((uintptr_t) pointer, "0123456789abcdef");
    return (length+2);
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
            printed_chars += printf_p((void *)zeiger);
            ++i; // Increment i to skip the 'p' character
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
            uintptr_t x;
            x = va_arg(arguments, int);
            printf_x(x, "0123456789abcdef");
            printed_chars += length_printf_x(x);
            ++i;
        }
        else if (text[i] == 'X')
        {
            uintptr_t X;
            X = va_arg(arguments, int);
            printf_x(X, "0123456789ABCDEF");
            printed_chars += length_printf_x(X);
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
    int x = 765432;
    int X = 123;
    char symbol = '%';
    int ft_printf_len;
    int printf_len;
    ft_printf_len = ft_printf("Das ist: %c und es schreibt:\nd: %d\nx: %x\nX: %X\ns: %s\nund Zeiger: %p\nund der neueste freund: %%\n", 'C', d, x, X, s, (void *)&d);
    printf("ft_printf-länge ist: %d chars\n", ft_printf_len);
    printf("Adresse des Zeigers: %p\n", (void *)&d);
    printf_len = printf("Das ist: %c und es schreibt:\nd: %d\nx: %x\nX: %X\ns: %s\nund Zeiger: %p\nund der neueste freund: %%\n", 'C', d, x, X, s, (void *)&d);
    printf ("printf-länge ist: %d chars\n", printf_len);
    /*
    ft_printf_len = ft_printf("\n%p", (void *)&d);
    printf_len = printf("\n%p", (void *)&d);
    */
    //ft_printf_len = ft_printf("\n%p", s);
    //printf_len = printf("\n%p", s);
    printf("\n%d vs %d", ft_printf_len, printf_len);
    return(0);
}