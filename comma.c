#include <stdio.h>

int main() {
    // For loop: Prints numbers from 1 to 5
    printf("For Loop:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    // While loop: Prints numbers from 1 to 5
    printf("While Loop:\n");
    int j = 1;
    while (j <= 50) {
        printf("%d ", j);
        j++;
    }
    printf("\n\n");

    // Do-While loop: Prints numbers from 1 to 5
    printf("Do-While Loop:\n");
    int k = 1;
    do {
        printf("%d ", k);
        k++;
    } while (k <= 15);
    printf("\n");

    return 0;
}
