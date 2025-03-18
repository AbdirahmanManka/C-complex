#include <stdio.h>

int main() {
    int num;

    // Taking user input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Checking if the number is even or odd
    if (num % 2 == 0) {
        printf("%d is even.\n", num);
    } else {
        printf("%d is odd.\n", num);
    }

    return 0;
}
