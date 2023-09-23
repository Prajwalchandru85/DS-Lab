#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char data[MAX_SIZE];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, char value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

char pop(struct Stack *stack) {
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

    char input[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", input);

    int length = strlen(input);
    int i;

    // Push each character onto the stack
    for (i = 0; i < length; i++) {
        push(&stack, input[i]);
    }

    // Pop characters from the stack and compare with the original string
    for (i = 0; i < length; i++) {
        if (pop(&stack) != input[i]) {
            printf("Not a palindrome\n");
            return 0;
        }
    }

    printf("Palindrome\n");

    return 0;
}
