#include <stdio.h>
/*
int main() {
    int decimal = 11;
    int octal = 077;    // starts with 0
    int hex = 0x11;     // starts with 0x

    printf("%d\n", decimal);  // Output: 10
    printf("%u\n", decimal);  // Output: 10

   // printf("%d\n", octal);    // Output: 8
   // printf("%i\n", octal);    // Output: 8

  //  printf("%d\n", hex);      // Output: 16
  //  printf("%i\n", hex);      // Output: 16

    return 0;
}
*/
#include <stdio.h>

int main() {
    int z = 134567890;
    int *ptr = &z;

    // Printing the address of the pointer using printf
    printf("Address of the pointer: %p\n", (void*)&ptr);

    return 0;
}


/*
#include <unistd.h>

void	ft_putstr_non_printable(char	*str)
{
	while (*str)
	{
		if (*str < 32 || *str == 127)
		{
			write (1, "\\", 1);
			write (1, &(char){"0123456789abcdef"[*str / 16]}, 1);
			write (1, &(char){"0123456789abcdef"[*str % 16]}, 1);
		}
		else
			write (1, &(char){*str}, 1);
	str++;
	}
}
*/

