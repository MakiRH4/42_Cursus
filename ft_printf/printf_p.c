/*#include <stdint.h>

int printf_p(void *p)
{
    int ret1;
    int ret2;

    if (p == NULL)
        return (ft_putstr_fd("0x0", 1));
    ret1 = ft_putstr_fd("0x", 1);
    if (ret1 == -1)
        return (-1);
    ret2 = printf_x((uintptr_t) p);
    if (ret2 == -1)
        return (-1);
    return (ret1 + ret2);
}




WORKS IN PYTRHONTUTOR

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

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
    {
        write (1, &(char){base[number % 16]}, 1);
        digits += 1;
    }
    return (digits);
}

int printf_p(uintptr_t *pointer)
{
    //ret = printf_x((uintptr_t) p, "0123456789abcdef");
    return (printf_x((uintptr_t) pointer, "0123456789abcdef"));
}

int main(void)
{
  int puntero;
  puntero = 22;
  printf_p((void *)&puntero);
  printf("\n%p", (void *)&puntero);
  return(0);
}

*/
#include <stdio.h>

int main() {
    int number = 10;
    int *ptr = &number; // Pointer pointing to the address of 'number'

    // Printing the address of the pointer using printf
    printf("Adresse des Zeigers: %p\n", (void *)&ptr);
    printf("number 012 when printed is: %d\n", 012);
    return 0;
}
