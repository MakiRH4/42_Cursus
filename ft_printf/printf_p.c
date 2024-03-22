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
