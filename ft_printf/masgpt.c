#include <stdio.h>

void printHexadecimal(int num) {
    char hex[16]; // Array to store hexadecimal digits
    int i = 0, remainder;

    // Convert decimal to hexadecimal
    while (num != 0) {
        remainder = num % 16;
        if (remainder < 10)
            hex[i++] = remainder + 48; // Convert to ASCII character
        else
            hex[i++] = remainder + 55; // Convert to ASCII character
        num /= 16;
    }

    // Print hexadecimal number in reverse order
    printf("Hexadecimal representation: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

int main() {
    int num;

    // Prompt user to enter an integer
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Print the integer in hexadecimal format
    printHexadecimal(num);

    return 0;
}
