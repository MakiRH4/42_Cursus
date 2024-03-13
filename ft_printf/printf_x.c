#include <stdio.h>
#include <unistd.h>

int printf_x(int number, char *base)
{
    if (number >= 16)
    {
        write (1, &(char){base[number % 16]}, 1);
        printf_x((number / 16), base);
    }
    else 
        write (1, &(char){base[number % 16]}, 1);
    return (0);
}

int main(void)
{
    int number = 1234;
    printf_x(number, "0123456789ABCDEF");
    return (0);
}