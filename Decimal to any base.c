#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

int pop(struct Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

int main() {
    struct Stack stack;
    initStack(&stack);

    int decimalNumber, base;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    printf("Enter the desired base (2, 8, 16): ");
    scanf("%d", &base);

    if (base != 2 && base != 8 && base != 16) {
        printf("Invalid base. Please enter 2, 8, or 16.\n");
        return 1; // Exit with an error code
    }

    // Conversion
    while (decimalNumber > 0) {
        int remainder = decimalNumber % base;
        push(&stack, remainder);
        decimalNumber /= base;
    }

    // Display the result
    printf("Number in base %d: ", base);
    while (stack.top >= 0) {
        int digit = pop(&stack);
        if (base == 16 && digit >= 10) {
            // Print hexadecimal digits A-F
            printf("%c", 'A' + digit - 10);
        } else {
            printf("%d", digit);
        }
    }
    printf("\n");

    return 0;
}
