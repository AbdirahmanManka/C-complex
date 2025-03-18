#include <stdio.h>

int main(void) {
    int v1, v2, sum;  // Declaring integer variables

    // Asking for user input
    printf("Enter first number: ");
    scanf("%d", &v1);

    printf("Enter second number: ");
    scanf("%d", &v2);

    // Performing the sum
    sum = v1 + v2;

    // Displaying the result
    printf("The sum of %d and %d is: %d\n", v1, v2, sum);

    return 0;  // Successful execution
}
