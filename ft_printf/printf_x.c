#include <stdio.h>
#include <unistd.h>

int dec_to_hex(int number)
{
    if (number >= 16)
    {
        write (1, &(char){"0123456789abcdef"[number % 16]}, 1);
        dec_to_hex(number / 16);
    }
    else 
        write (1, &(char){"0123456789abcdef"[number % 16]}, 1);
    return (0);
}

int main(void)
{
    int number = 1234;
    dec_to_hex(number);
    return (0);
}