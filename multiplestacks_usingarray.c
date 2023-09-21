#include <stdio.h>
#include <stdlib.h>

#define MAX 20 // Total size of the array
#define MAX_STACKS 10 // Maximum number of stacks

int stack[MAX]; // The single array to hold all stacks
int top[MAX_STACKS]; // Array to store the top index of each stack
int base[MAX_STACKS]; // Array to store the base index of each stack

// Function to push an element onto the specified stack
void push(int stackNum, int value) {
    if (top[stackNum] == base[stackNum + 1]) {
        printf("Stack %d is full\n", stackNum);
    } else {
        stack[++top[stackNum]] = value;
    }
}

// Function to pop an element from the specified stack
int pop(int stackNum) {
    if (top[stackNum] == base[stackNum]) {
        printf("Stack %d is empty\n", stackNum);
        return -9999; // Return a sentinel value to indicate an error
    } else {
        return stack[top[stackNum]--];
    }
}

// Function to display the contents of the specified stack
void display(int stackNum) {
    for (int j = base[stackNum] + 1; j <= top[stackNum]; j++) {
        printf("%d ", stack[j]);
    }
    printf("\n");
}

int main() {
    int m, n, opt, stackNum, ele, val;

    printf("Enter total size: ");
    scanf("%d", &m);
    printf("Enter number of stacks: ");
    scanf("%d", &n);

    // Calculate the size of each stack
    int stackSize = m / n;

    // Initialize the top and base arrays
    for (int i = 0; i < n; i++) {
        top[i] = base[i] = i * stackSize - 1;
    }
    base[n] = m - 1; // Set the last base as the end of the array

    while(1) {
        printf("\nOptions:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Push into which stack (0-%d): ", n - 1);
                scanf("%d", &stackNum);
                printf("Enter the element: ");
                scanf("%d", &ele);
                push(stackNum, ele);
                break;

            case 2:
                printf("Pop from which stack (0-%d): ", n - 1);
                scanf("%d", &stackNum);
                val = pop(stackNum);
                if (val != -9999) {
                    printf("Popped value: %d\n", val);
                }
                break;

            case 3:
                printf("Display which stack (0-%d): ", n - 1);
                scanf("%d", &stackNum);
                display(stackNum);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}
