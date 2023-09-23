#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKS 10
#define size 20

struct Stack {
    int top;
    int data[size];
};

typedef struct Stack STACK;

void initStack(STACK *s) {
    s->top = -1;
}

void push(STACK *s, int item) {
    if (s->top == size - 1) {
        printf("Stack is full\n");
    } else {
        s->data[++(s->top)] = item;
    }
}

int pop(STACK *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -9999;
    } else {
        return s->data[(s->top)--];
    }
}

void display(STACK s) {
    if (s.top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = s.top; i >= 0; i--) {
            printf("%d\n", s.data[i]);
        }
    }
}

int main() {
    int n, opt, stackNum, ele, val;
    STACK s;
    s.top = -1; // Initialize the stack top to -1

    printf("Enter number of stacks: ");
    scanf("%d", &n);

    // Initialize the remaining stacks if needed
    STACK stacks[MAX_STACKS];
    for (int i = 0; i < n; i++) {
        stacks[i].top = -1;
    }

    while (1) {
        printf("\nOptions:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Push into which stack (0-%d): ", n - 1);
                scanf("%d", &stackNum);
                if (stackNum >= 0 && stackNum < n) {
                    printf("Enter the element: ");
                    scanf("%d", &ele);
                    push(&stacks[stackNum], ele);
                } else {
                    printf("Invalid stack number\n");
                }
                break;

            case 2:
                printf("Pop from which stack (0-%d): ", n - 1);
                scanf("%d", &stackNum);
                if (stackNum >= 0 && stackNum < n) {
                    val = pop(&stacks[stackNum]);
                    if (val != -9999) {
                        printf("Popped value: %d\n", val);
                    }
                } else {
                    printf("Invalid stack number\n");
                }
                break;

            case 3:
                printf("Display which stack (0-%d): ", n - 1);
                scanf("%d", &stackNum);
                if (stackNum >= 0 && stackNum < n) {
                    display(stacks[stackNum]);
                } else {
                    printf("Invalid stack number\n");
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}
