#include <stdio.h>

// Declare two stacks.
int stack1[100], stack2[100];

// Declare top variables.
int top1 = -1, top2 = -1;

// Enqueue an element into the queue.
void enqueue(int element) {
    // Push the element into stack1.
    stack1[++top1] = element;
}

// Dequeue an element from the queue.
int dequeue() {
    // Check if both stacks are empty.
    if (top1 == -1 && top2 == -1) {
        // The queue is empty. Return -1.
        return -1;
    }

    // If stack2 is empty, transfer all elements from stack1 to stack2.
    if (top2 == -1) {
        while (top1 >= 0) {
            stack2[++top2] = stack1[top1--];
        }
    }

    // Pop and return the top element from stack2.
    return stack2[top2--];
}

// Print the queue.
void printQueue() {
    // If stack2 is empty, transfer all elements from stack1 to stack2.
    if (top2 == -1) {
        while (top1 >= 0) {
            stack2[++top2] = stack1[top1--];
        }
    }

    // Print all elements in stack2.
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Queue: ");
    printQueue();

    int element = dequeue();
    if (element != -1) {
        printf("Dequeued: %d\n", element);
    } else {
        printf("Dequeue failed: Queue is empty\n");
    }

    printf("Queue: ");
    printQueue();

    enqueue(40);
    printf("Queue: ");
    printQueue();

    return 0;
}
