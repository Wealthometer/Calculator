#include <stdio.h>
#include <math.h>

// Function declarations
void displayMenu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
int modulus(int a, int b);
float power(float base, float exponent);
float squareRoot(float num);
void scientificCalculator();
void basicCalculator();

int main() {
    int choice;

    do {
        printf("\n=== C CALCULATOR ===\n");
        printf("1. Basic Calculator\n");
        printf("2. Scientific Calculator\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                basicCalculator();
                break;
            case 2:
                scientificCalculator();
                break;
            case 3:
                printf("Thank you for using the calculator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}

void displayMenu() {
    printf("\n--- Operations ---\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("6. Power (^)\n");
    printf("7. Square Root (√)\n");
    printf("8. Back to Main Menu\n");
    printf("Enter operation number: ");
}

// Basic arithmetic operations
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if(b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero!\n");
        return 0;
    }
}

int modulus(int a, int b) {
    if(b != 0) {
        return a % b;
    } else {
        printf("Error: Division by zero!\n");
        return 0;
    }
}

float power(float base, float exponent) {
    return pow(base, exponent);
}

float squareRoot(float num) {
    if(num >= 0) {
        return sqrt(num);
    } else {
        printf("Error: Cannot calculate square root of negative number!\n");
        return 0;
    }
}

void basicCalculator() {
    int operation;
    float num1, num2, result;
    int int1, int2, intResult;

    do {
        displayMenu();
        scanf("%d", &operation);

        if(operation >= 1 && operation <= 7) {
            if(operation == 5) { // Modulus requires integers
                printf("Enter first integer: ");
                scanf("%d", &int1);
                printf("Enter second integer: ");
                scanf("%d", &int2);
            } else if(operation == 7) { // Square root needs only one number
                printf("Enter a number: ");
                scanf("%f", &num1);
            } else {
                printf("Enter first number: ");
                scanf("%f", &num1);
                if(operation != 6) {
                    printf("Enter second number: ");
                    scanf("%f", &num2);
                } else {
                    printf("Enter exponent: ");
                    scanf("%f", &num2);
                }
            }
        }

        switch(operation) {
            case 1:
                result = add(num1, num2);
                printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("%.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 4:
                result = divide(num1, num2);
                if(num2 != 0) {
                    printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;
            case 5:
                intResult = modulus(int1, int2);
                if(int2 != 0) {
                    printf("%d %% %d = %d\n", int1, int2, intResult);
                }
                break;
            case 6:
                result = power(num1, num2);
                printf("%.2f ^ %.2f = %.2f\n", num1, num2, result);
                break;
            case 7:
                result = squareRoot(num1);
                if(num1 >= 0) {
                    printf("√%.2f = %.2f\n", num1, result);
                }
                break;
            case 8:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid operation! Please try again.\n");
        }
    } while(operation != 8);
}

void scientificCalculator() {
    int choice;
    float num, result;

    do {
        printf("\n=== SCIENTIFIC CALCULATOR ===\n");
        printf("1. Sine\n");
        printf("2. Cosine\n");
        printf("3. Tangent\n");
        printf("4. Logarithm (base 10)\n");
        printf("5. Natural Logarithm\n");
        printf("6. Exponential (e^x)\n");
        printf("7. Absolute Value\n");
        printf("8. Floor\n");
        printf("9. Ceiling\n");
        printf("10. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 9) {
            printf("Enter a number: ");
            scanf("%f", &num);
        }

        switch(choice) {
            case 1:
                result = sin(num * M_PI / 180); // Convert to radians
                printf("sin(%.2f) = %.4f\n", num, result);
                break;
            case 2:
                result = cos(num * M_PI / 180);
                printf("cos(%.2f) = %.4f\n", num, result);
                break;
            case 3:
                result = tan(num * M_PI / 180);
                printf("tan(%.2f) = %.4f\n", num, result);
                break;
            case 4:
                if(num > 0) {
                    result = log10(num);
                    printf("log10(%.2f) = %.4f\n", num, result);
                } else {
                    printf("Error: Logarithm of non-positive number!\n");
                }
                break;
            case 5:
                if(num > 0) {
                    result = log(num);
                    printf("ln(%.2f) = %.4f\n", num, result);
                } else {
                    printf("Error: Logarithm of non-positive number!\n");
                }
                break;
            case 6:
                result = exp(num);
                printf("e^(%.2f) = %.4f\n", num, result);
                break;
            case 7:
                result = fabs(num);
                printf("|%.2f| = %.2f\n", num, result);
                break;
            case 8:
                result = floor(num);
                printf("floor(%.2f) = %.2f\n", num, result);
                break;
            case 9:
                result = ceil(num);
                printf("ceil(%.2f) = %.2f\n", num, result);
                break;
            case 10:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 10);
}
