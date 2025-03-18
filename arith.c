#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    // Display menu
    printf("Simple Calculator\n");
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator); // Note the space before %c to avoid newline issues

    // Taking two numbers as input
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    // Performing operation based on user input
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else {
                printf("Error! Division by zero is not allowed.\n");
                return 1; // Exit with error
            }
            printf("Result: %.2lf\n", result);
            break;
        default:
            printf("Invalid operator! Please use +, -, *, or /.\n");
            return 1; // Exit with error
    }

    return 0;
}
